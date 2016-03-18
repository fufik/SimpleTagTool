//GPL
#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);
    QTranslator myTranslator;
    if (!myTranslator.load("stt_"+QLocale::system().name()))
        std::cout<<"Can't get appropriate program localization file.\n";
    a.installTranslator(&myTranslator);
    MainWindow w;
    w.show();

    return a.exec();
}
