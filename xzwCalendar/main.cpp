#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QProcess>
#include <fstream>
#include <QDebug>
#include <string>
#include "calendar.h"
#include "mydialog.h"
#include "myinputdialog.h"

#define TO_CHANGE_LAN 6

int main_width, main_height;
int main_x, main_y;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load("../../../eng.qm");

    std::ifstream fin;
    fin.open("./AppFile/UserFile/language.txt");
    std::string tmp;
    getline(fin, tmp);

    qDebug() << QString::fromStdString(tmp);

    if(tmp == "1") a.installTranslator(&translator);

//    MyDialog d;
//    d.show();

//    MyInputDialog i;
//    i.show();
    MainWindow w;
    w.show();
    main_width = w.width(); main_height = w.height();
    main_x = w.pos().x(); main_y = w.pos().y();
    int ret = a.exec();
    if(ret == TO_CHANGE_LAN)
    {
        QProcess::startDetached(qApp->applicationFilePath(),QStringList());
        return 0;
    }


    return ret;
}
