#ifndef MYLABEL_H
#define MYLABEL_H

#include <QString>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPoint>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QList>
#include <QDate>


class MyLabel : public QLabel
{
    Q_OBJECT

public:

    MyLabel(const QString& text, QWidget* parent,int year, int month, int day);

    void setDate(int year, int month, int day);

    void set_filename_list();

    void set_text();

protected:

    void mousePressEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
//   void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);

signals:
    void clicked(int);
    void double_clicked(int);
    void sth_changed();

public slots:
//    void on_contain_changed(QString&);

private:
//    void performDrag();
    QPoint startPos;
    QList<QString> filename_list;
    int m_year, m_month, m_day;
};

#endif // MYLABEL_H
