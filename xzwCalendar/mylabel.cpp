#include "mylabel.h"
#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QFileInfo>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

extern int main_width, main_height;
extern int main_x, main_y;

void MyLabel::setDate(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
       startPos = event->pos();
       emit clicked(m_day);
    }
    else QLabel::mousePressEvent(event);
}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //qDebug() << "HAHA";
        emit clicked(m_day);
        emit double_clicked(m_day);
    }
}

MyLabel::MyLabel(const QString& text, QWidget* parent, int year, int month, int day)
    : QLabel(text,parent)
{
    m_year = year;
    m_month = month;
    m_day = day;
    set_filename_list();
    set_text();
    setAcceptDrops(true);
}

void MyLabel::set_filename_list()
{
    filename_list.clear();

    int ndate = m_year*10000 + m_month*100 + m_day;
    string ndate_s = QString::number(ndate).toStdString();
    ifstream fin; string tmp;
    fin.open("./AppFile/UserFile/" + ndate_s + "_" + "index.txt");
    while(getline(fin,tmp))
    {
        filename_list.append(QString::fromStdString(tmp));
    }
}

void MyLabel::set_text()
{
    stringstream s; s.clear();
    s << "<font><font size=-10>";
    for(QList<QString>::iterator t = filename_list.begin(); t != filename_list.end(); t++)
    {
        std::string sss=(*t).toStdString();
        if (sss.length()>6)
        {
            sss.erase(6,10000);
            sss+="...";
        }
        s << sss << "<br>";
    }
    s << "</font>" << m_day << "</font>";
    setText(QString::fromStdString(s.str()));
}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        int mx = event->globalPos().x() - main_x;
        int my = event->globalPos().y() - main_y;
        if(mx >= 0 && mx <= main_width && my >=0 && my <= main_height) return;

        QDrag *drag = new QDrag(this);
        QMimeData *qm = new QMimeData;

        stringstream filePath; filePath.clear();
        QList<QUrl> fileNames;
        fileNames.clear();

        int ndate = m_year*10000 + m_month*100 + m_day;
        string ndate_s = QString::number(ndate).toStdString();
        ofstream fout;
        ifstream fin;

        if(!filename_list.empty())
        {
            QList<QString>::iterator t = filename_list.begin();
            filePath << "./AppFile/UserFile/" << ndate_s << "_" << t->toStdString();
            QFileInfo fi(QString::fromStdString(filePath.str()));

            fileNames.append(QUrl::fromLocalFile(fi.absolutePath()+ "/" + QString::fromStdString(ndate_s) + "_"+ *t));

            qDebug() << fi.absolutePath()+ "/" + QString::fromStdString(ndate_s) + "_" + *t;

            fin.open("./AppFile/UserFile/" + ndate_s + "_" + "index.txt");
            fout.open("./AppFile/UserFile/tmp.txt");
            string tmp;
            while(getline(fin, tmp))
            {
                if(tmp != (*t).toStdString())
                    fout << tmp << endl;
            }
            fin.close(); fout.close();
            fin.open("./AppFile/UserFile/tmp.txt");
            fout.open("./AppFile/UserFile/" + ndate_s + "_" + "index.txt");
            while(getline(fin, tmp))
            {
                fout << tmp << endl;
            }
            fin.close(); fout.close();

            filename_list.pop_front();
            set_text();


            qm->setUrls(fileNames);
            drag->setMimeData(qm);

            Qt::DropAction dropAction = drag->exec(Qt::CopyAction);

            //QFile::remove(fi.absolutePath()+ "/" + QString::fromStdString(ndate_s) + "_"+ *t);
        }

    }
    QLabel::mouseMoveEvent(event);
}

void MyLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
    {
        if (event->mimeData()->urls().count() > 1)
        {
            event->ignore();
            return;
        }
        event->acceptProposedAction();
        //setStyleSheet("background: #00B2EE; border: 1px solid #F7F7F7");
    }
    QLabel::dragEnterEvent(event);
}

void MyLabel::dragLeaveEvent(QDragLeaveEvent *event)
{
    emit sth_changed();
    QLabel::dragLeaveEvent(event);
}

void MyLabel::dropEvent(QDropEvent *event)
{
    int ndate = m_year*10000 + m_month*100 + m_day;
    string ndate_s = QString::number(ndate).toStdString();

    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString filename = urls.first().toLocalFile();
    if (filename.isEmpty())
        return;

    QFileInfo fi(filename);
    if (fi.isDir())
        return;

    QString real_filename = filename.section("/",-1,-1);
    ofstream fout;
    ifstream fin;
    string tmp;
    fin.open(filename.toStdString());
    fout.open("./AppFile/UserFile/" + ndate_s + "_" + real_filename.toStdString());
    while(getline(fin,tmp))
    {
        fout << tmp << endl;
    }
    fin.close(); fout.close();
    fout.open("./AppFile/UserFile/" + ndate_s + "_" + "index.txt", ios::app);
    fout << real_filename.toStdString() << endl;
    fout.close();
    set_filename_list();
    set_text();
    emit sth_changed();
}



//void MyLabel::on_contain_changed(QString & s, int i)
//{
//    setText(s + "\n" + QString::number(i));
//}
