#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QEvent>
#include <QResizeEvent>
#include <QLineEdit>
#include <QColorDialog>
#include <QColor>
#include <QPainter>
#include <QDebug>
#include <QGraphicsItem>
#include <typeinfo>
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QMouseEvent>
#include <QAction>
#include <QSize>

unsigned int count = 0;
double delt = 0.0;
QPen pen1(Qt::black);
QBrush brush1(Qt::white);
QPen pen2(Qt::black);
QBrush brush2(Qt::white);
QPen pen3(Qt::black);
QBrush brush3(Qt::white);
QPen pen4(Qt::black);
QBrush brush4(Qt::white);
QPen pen6(Qt::black);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_3_triggered() // Круг
{
    item1 = scene->addEllipse(QRectF(10,10,200,200),pen1,brush1);
    item1->setFlag(QGraphicsItem::ItemIsMovable);
    item1->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(item1);
    if (!scene->collidingItems(item1).isEmpty())
    {
        item1->hide();
        item1 = scene->addEllipse(QRectF(10,10,200,200),QPen(Qt::black),QBrush(Qt::red));
        item1->setFlag(QGraphicsItem::ItemIsMovable);
        item1->setFlag(QGraphicsItem::ItemIsSelectable);
        item1->show();
    }
}

void MainWindow::on_action_4_triggered() // Рисунок
{
    QPainterPath path;
    path.moveTo(0, 0);
    path.cubicTo(199, 0,  50, 50,  199, 199);
    path.cubicTo(0, 199,  50, 50,  0, 0);
    item2 = scene->addPath(path,pen2,brush2);
    item2->setFlag(QGraphicsItem::ItemIsMovable);
    item2->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(item2);
    if (!scene->collidingItems(item2).isEmpty())
    {
        item2->hide();
        item2 = scene->addPath(path,QPen(Qt::black),QBrush(Qt::red));
        item2->setFlag(QGraphicsItem::ItemIsMovable);
        item2->setFlag(QGraphicsItem::ItemIsSelectable);
        item2->show();
    }
}


void MainWindow::on_action_5_triggered() // Многоугольник
{
    QPolygonF polygon;
    polygon << QPointF(0, 0) << QPointF(150, 0) << QPointF(200, 150) << QPointF(0, 200);
    item3 = scene->addPolygon(polygon,pen3,brush3);
    item3->setFlag(QGraphicsItem::ItemIsMovable);
    item3->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(item3);
    if (!scene->collidingItems(item3).isEmpty())
    {
        item3->hide();
        item3 = scene->addPolygon(polygon,QPen(Qt::black),QBrush(Qt::red));
        item3->setFlag(QGraphicsItem::ItemIsMovable);
        item3->setFlag(QGraphicsItem::ItemIsSelectable);
        item3->show();
    }
}

void MainWindow::on_action_6_triggered() // Квадрат
{
    item4 = scene->addRect(QRectF(10,10,200,200),pen4,brush4);
    item4->setFlag(QGraphicsItem::ItemIsMovable);
    item4->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(item4);
    if (!scene->collidingItems(item4).isEmpty())
    {
        item4->hide();
        item4 = scene->addRect(QRectF(10,10,200,200),QPen(Qt::black),QBrush(Qt::red));
        item4->setFlag(QGraphicsItem::ItemIsMovable);
        item4->setFlag(QGraphicsItem::ItemIsSelectable);
        item4->show();
    }
}

void MainWindow::on_action_7_triggered() // Текст
{
    const QFont font("Times", 16, QFont::Light);
    item5 = scene->addSimpleText(str,font);
    item5->setFlag(QGraphicsItem::ItemIsMovable);
    item5->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(item5);
}

void MainWindow::on_lineEdit_editingFinished() // Считать сразу после окончания ввода текст из LineEdit
{
    str = MainWindow::ui->lineEdit->text();
}

void MainWindow::on_action_8_triggered() // Линия
{
    pen6.setWidth(3);
    item6 = scene->addLine(QLineF(0,0,400,400),pen6);
    item6->setFlag(QGraphicsItem::ItemIsMovable);
    item6->setFlag(QGraphicsItem::ItemIsSelectable);
    scene->addItem(item6);
    if (!scene->collidingItems(item6).isEmpty())
    {
        QPen pen(Qt::red);
        pen.setWidth(3);
        item6->hide();
        item6 = scene->addLine(QLineF(0,0,400,400),pen);
        item6->setFlag(QGraphicsItem::ItemIsMovable);
        item6->setFlag(QGraphicsItem::ItemIsSelectable);
        item6->show();
    }
}

void MainWindow::on_pushButton_clicked() // Удалить
{
    if (item1->isSelected())
        item1->hide();
    else if (item2->isSelected())
        item2->hide();
    else if (item3->isSelected())
        item3->hide();
    else if (item4->isSelected())
        item4->hide();
    else if (item5->isSelected())
        item5->hide();
    else if (item6->isSelected())
        item6->hide();
}

void MainWindow::on_pushButton_3_clicked() // Повернуть влево
{
    if (item1->isSelected())
        item1->rotate(-10);
    else if (item2->isSelected())
        item2->rotate(-10);
    else if (item3->isSelected())
        item3->rotate(-10);
    else if (item4->isSelected())
        item4->rotate(-10);
    else if (item5->isSelected())
        item5->rotate(-10);
    else if (item6->isSelected())
        item6->rotate(-10);
}

void MainWindow::on_pushButton_2_clicked() // Повернуть вправо
{
    if (item1->isSelected())
        item1->rotate(10);
    else if (item2->isSelected())
        item2->rotate(10);
    else if (item3->isSelected())
        item3->rotate(10);
    else if (item4->isSelected())
        item4->rotate(10);
    else if (item5->isSelected())
        item5->rotate(10);
    else if (item6->isSelected())
        item6->rotate(10);
}

void MainWindow::on_action_triggered() // Цвет
{
    if (item1->isSelected())
    {
        item1->hide();
        QColor pen_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет пера");
        pen1.setColor(pen_color);
        QColor brush_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет кисти");
        brush1.setColor(brush_color);
        on_action_3_triggered();
    }
    else if (item2->isSelected())
    {
        item2->hide();
        QColor pen_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет пера");
        pen2.setColor(pen_color);
        QColor brush_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет кисти");
        brush2.setColor(brush_color);
        on_action_4_triggered();
    }
    else if (item3->isSelected())
    {
        item3->hide();
        QColor pen_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет пера");
        pen3.setColor(pen_color);
        QColor brush_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет кисти");
        brush3.setColor(brush_color);
        on_action_5_triggered();
    }
    else if (item4->isSelected())
    {
        item4->hide();
        QColor pen_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет пера");
        pen4.setColor(pen_color);
        QColor brush_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет кисти");
        brush4.setColor(brush_color);
        on_action_6_triggered();
    }
    else if (item6->isSelected())
    {
        item6->hide();
        QColor pen_color = QColorDialog::getColor(Qt::white, this, "Выберете цвет пера");
        pen6.setColor(pen_color);
        on_action_8_triggered();
    }

    return;
}

void MainWindow::on_action_12_triggered() // Сохранить
{
    QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    scene->render(&painter);
    image.save("C:/qt/result.png");
}

void MainWindow::on_action1_triggered() // Приоритет перекрытия
{
    if (item1->isSelected())
        item1->setZValue(1);
    else if (item2->isSelected())
        item2->setZValue(1);
    else if (item3->isSelected())
        item3->setZValue(1);
    else if (item4->isSelected())
        item4->setZValue(1);
    else if (item5->isSelected())
        item5->setZValue(1);
    else if (item6->isSelected())
        item6->setZValue(1);
}

void MainWindow::on_action2_triggered() // ^
{
    if (item1->isSelected())
        item1->setZValue(2);
    else if (item2->isSelected())
        item2->setZValue(2);
    else if (item3->isSelected())
        item3->setZValue(2);
    else if (item4->isSelected())
        item4->setZValue(2);
    else if (item5->isSelected())
        item5->setZValue(2);
    else if (item6->isSelected())
        item6->setZValue(2);
}

void MainWindow::on_action3_triggered() // ^
{
    if (item1->isSelected())
        item1->setZValue(3);
    else if (item2->isSelected())
        item2->setZValue(3);
    else if (item3->isSelected())
        item3->setZValue(3);
    else if (item4->isSelected())
        item4->setZValue(3);
    else if (item5->isSelected())
        item5->setZValue(3);
    else if (item6->isSelected())
        item6->setZValue(3);
}

void MainWindow::on_action4_triggered() // ^
{
    if (item1->isSelected())
        item1->setZValue(4);
    else if (item2->isSelected())
        item2->setZValue(4);
    else if (item3->isSelected())
        item3->setZValue(4);
    else if (item4->isSelected())
        item4->setZValue(4);
    else if (item5->isSelected())
        item5->setZValue(4);
    else if (item6->isSelected())
        item6->setZValue(4);
}

void MainWindow::on_action5_triggered() // ^
{
    if (item1->isSelected())
        item1->setZValue(5);
    else if (item2->isSelected())
        item2->setZValue(5);
    else if (item3->isSelected())
        item3->setZValue(5);
    else if (item4->isSelected())
        item4->setZValue(5);
    else if (item5->isSelected())
        item5->setZValue(5);
    else if (item6->isSelected())
        item6->setZValue(5);
}

void MainWindow::on_action6_triggered() // ^
{
    if (item1->isSelected())
        item1->setZValue(6);
    else if (item2->isSelected())
        item2->setZValue(6);
    else if (item3->isSelected())
        item3->setZValue(6);
    else if (item4->isSelected())
        item4->setZValue(6);
    else if (item5->isSelected())
        item5->setZValue(6);
    else if (item6->isSelected())
        item6->setZValue(6);
}

void MainWindow::wheelEvent(QWheelEvent *event) // Масштабирование сцены
{
    delt = delt + event->delta();
    if (count == 0)
        delt = delt + 1000;
    if (delt > 1880)
        delt = 1880;
    if (delt < 890)
        delt = 890;
    QSize size(delt,delt * 7 / 16);
    ui->graphicsView->resize(size);
    count = 1;
}
