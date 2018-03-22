#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calendar.h"
#include <QWidget>
#include <QApplication>
#include <QGridLayout>
#include <QDir>
#include <fstream>
#include <string>
#include <QApplication>
#include <QTranslator>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* w = new QWidget;
    setCentralWidget(w);

    QHBoxLayout* mainlayout = new QHBoxLayout;
    calendar* this_calendar = new calendar(w);
    w->setStyleSheet("background: #F0F7F7; border: 1px solid #F7F7F7");
    mainlayout->addWidget(this_calendar);
    w->setLayout(mainlayout);

    deskMod = 1;

    QDir::setCurrent(QCoreApplication::applicationDirPath());
    QDir *nq = new QDir;
    nq->mkdir("AppFile");
    nq->mkdir("./AppFile/UserFile");
    this->resize(600,500);

    setWindowOpacity(0.8);


   // setBackgroundRole(Qt::transparent);
    /*

    mainlayout->addWidget(this_calendar);


    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_fix_flexible_triggered()
{
    if(deskMod)
    {
        setWindowOpacity(0.5);
        setWindowFlags(Qt::WindowTransparentForInput);
        show();
        deskMod = 0;
        return;
    }
    if(!deskMod)
    {
        setWindowOpacity(1);
        setWindowFlags(Qt::Window);
        show();
        deskMod = 1;
        return;
    }
}


extern int main_width, main_height;
extern int main_x, main_y;

void MainWindow::resizeEvent(QResizeEvent *event)
{
    main_width = width();
    main_height = height();
    //qDebug() << pos().x() << ' ' << pos().y();
    QMainWindow::resizeEvent(event);
}

void MainWindow::moveEvent(QMoveEvent *event)
{
    main_x = pos().x(), main_y = pos().y();
    QMainWindow::moveEvent(event);
}

void MainWindow::on_actiontranslate_triggered()
{
    ifstream fin;
    fin.open("./AppFile/UserFile/language.txt");
    string tmp;
    getline(fin, tmp);
    fin.close();
    if(tmp == "1") tmp = "0";
    else tmp = "1";
    ofstream fout;
    fout.open("./AppFile/UserFile/language.txt");
    fout << tmp << endl;
    qApp->exit(6);
}
