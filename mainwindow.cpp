//GPL
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#define QS(s) QString::fromUtf8(s.toCString(true))
#define TS(s) QFile::encodeName(s).constData()

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filename="";

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
        filename = QFileDialog::getOpenFileName(this, tr("Open MP3 file"),"/home",tr("MP3 files (*.mp3)"));
        ui->openfiledir->setText(filename);
        pTrack = new TagLib::MPEG::File(TS(filename));
        ui->filealbum->setText(QS(pTrack->tag()->album()));
        break;
        //TODO:More formats
    }
}

void MainWindow::on_openfiledir_textChanged(const QString &arg1)
{
    if (QFile::exists(arg1)) //Checking file for existing
    {
        ui->filealbum->setEnabled(1);
        ui->savebut->setEnabled(1);
     }
    else
    {
        ui->filealbum->setEnabled(0);
        ui->savebut->setEnabled(0);
    }
}

void MainWindow::on_savebut_clicked()
{
    pTrack->tag()->setAlbum(TS(ui->filealbum->text()));
    pTrack->save();
    delete pTrack;
    ui->openfiledir->clear();
    ui->filealbum->clear();
}

void MainWindow::on_typech_currentIndexChanged(int index)
{
    ui->openfiledir->clear();
    ui->filealbum->clear();
}
