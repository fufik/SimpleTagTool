//GPL
#include "mainwindow.h"
#include "ui_mainwindow.h"

#define QS(s) QString::fromUtf8(s.toCString(true))
#define TS(s) QFile::encodeName(s).constData()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openfilebut_clicked()
{
    switch (ui->typech->currentIndex())
    {
        case 0:
        pFile = new QFileInfo(QFileDialog::getOpenFileName(this, tr("Open MP3 file"),"/home",tr("MP3 files (*.mp3)")));
        ui->openfiledir->setEnabled(1);
        ui->openfiledir->setText(pFile->absoluteFilePath());
        pTrack = new TagLib::MPEG::File(TS(pFile->absoluteFilePath()));
        ui->fileauthor->setText(QS(pTrack->tag()->artist()));
        ui->filealbum->setText(QS(pTrack->tag()->album()));
        break;
        //TODO:More formats
    }
}

void MainWindow::on_openfiledir_textChanged(const QString &arg1)
{
    if (pFile->isFile()) //Checking: is file exists
    {
    enableFields();
     }
    else
    {
    disableFields();
    }
}

void MainWindow::on_savebut_clicked()
{
    pTrack->tag()->setArtist(TS(ui->fileauthor->text()));
    pTrack->tag()->setAlbum(TS(ui->filealbum->text()));
    pTrack->save();
    clearFields();
    disableFields(1);
    delete pTrack;
    delete pFile;
}

void MainWindow::on_typech_currentIndexChanged(int index)
{
    clearFields();
    disableFields(1);
}

void MainWindow::clearFields()
{
    ui->openfiledir->clear();
    ui->fileauthor->clear();
    ui->filealbum->clear();
}

void MainWindow::enableFields(bool opfd) //Argument for disabling openfiledir
{
    if (opfd)
        ui->openfiledir->setEnabled(1);
    ui->fileauthor->setEnabled(1);
    ui->filealbum->setEnabled(1);
    ui->savebut->setEnabled(1);
}

void MainWindow::disableFields(bool opfd) //Same here
{
    if (opfd)
        ui->openfiledir->setEnabled(0);
    ui->fileauthor->setEnabled(0);
    ui->filealbum->setEnabled(0);
    ui->savebut->setEnabled(0);
}
