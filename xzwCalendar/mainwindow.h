#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QResizeEvent>
#include <QMoveEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent* event);
    void moveEvent(QMoveEvent* event);

signals:
    void lan_changed();

private slots:
    void on_action_fix_flexible_triggered();

    void on_actiontranslate_triggered();

private:
    Ui::MainWindow *ui;

    int deskMod;
};

#endif // MAINWINDOW_H
