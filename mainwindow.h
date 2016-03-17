//GPL
#include <taglib/mpegfile.h>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openfilebut_clicked();

    void on_openfiledir_textChanged(const QString &arg1);

    void on_savebut_clicked();

    void on_typech_currentIndexChanged(int index);

private:
    QString filename;
    Ui::MainWindow *ui;
    TagLib::MPEG::File* pTrack;
};

#endif // MAINWINDOW_H
