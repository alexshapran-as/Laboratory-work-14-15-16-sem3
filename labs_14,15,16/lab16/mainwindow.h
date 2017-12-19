#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QGraphicsItem>

static QString str;

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

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_lineEdit_editingFinished();

    void on_action_8_triggered();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_action_triggered();

    void on_action_12_triggered();

    void on_action1_triggered();

    void on_action2_triggered();

    void on_action3_triggered();

    void on_action4_triggered();

    void on_action5_triggered();

    void on_action6_triggered();

    void wheelEvent( QWheelEvent * event );

private:
    Ui::MainWindow *ui;
public:
    QGraphicsItem *item1;
    QGraphicsItem *item2;
    QGraphicsItem *item3;
    QGraphicsItem *item4;
    QGraphicsItem *item5;
    QGraphicsItem *item6;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
