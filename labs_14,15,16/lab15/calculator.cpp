#include "calculator.h"
#include "ui_calculator.h"
#include "history.h"

unsigned int _index = {0};
unsigned int count;
static unsigned int r_button = {0};
QStringList item;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_comboBox_activated(int index)
{
    _index = index;
}

void Calculator::on_pushButton_clicked()
{
    int x1 = ui->spinBox->value();
    int x2 = ui->spinBox_2->value();
    count++;
    if (_index == 0)
    {
        long x3 = x1 + x2;
        QString str = QString::number(x3);
        if (r_button == 1)
            str = QString("%1").arg(x3,0,8);
        else if (r_button == 2)
            str = QString("%1").arg(x3,0,10);
        else if (r_button == 3)
            str = QString("%1").arg(x3,0,16);
        ui->lineEdit->setText(str);
        QString temp = QString::number(x1);
        temp += " + ";
        temp += QString::number(x2);
        temp += " = ";
        temp += str;
        item.push_back(temp);
    }
    else if (_index == 1)
    {
        long x3 = x1 - x2;
        QString str = QString::number(x3);
        if (r_button == 1)
            str = QString("%1").arg(x3,0,8);
        else if (r_button == 2)
            str = QString("%1").arg(x3,0,10);
        else if (r_button == 3)
           str = QString("%1").arg(x3,0,16);
        ui->lineEdit->setText(str);
        QString temp = QString::number(x1);
        temp += " - ";
        temp += QString::number(x2);
        temp += " = ";
        temp += str;
        item.push_back(temp);
    }
    else if (_index == 2)
    {
        if (x2 == 0)
        {
            ui->lineEdit->setText("Деление на 0 запрещено!");
        }
        else
        {
            double x3 = (double)x1 / (double)x2;
            QString str = QString::number(x3);
            if (r_button == 1)
                str = QString("%1").arg((int)x3,0,8);
            else if (r_button == 2)
                str = QString("%1").arg((int)x3,0,10);
            else if (r_button == 3)
                str = QString("%1").arg((int)x3,0,16);
            ui->lineEdit->setText(str);
            QString temp = QString::number(x1);
            temp += " / ";
            temp += QString::number(x2);
            temp += " = ";
            temp += str;
            item.push_back(temp);
        }
    }
    else if (_index == 3)
    {
        long x3 = x1 * x2;
        QString str = QString::number(x3);
        if (r_button == 1)
            str = QString("%1").arg(x3,0,8);
        else if (r_button == 2)
            str = QString("%1").arg(x3,0,10);
        else if (r_button == 3)
            str = QString("%1").arg(x3,0,16);
        ui->lineEdit->setText(str);
        QString temp = QString::number(x1);
        temp += " * ";
        temp += QString::number(x2);
        temp += " = ";
        temp += str;
        item.push_back(temp);
    }
}

void Calculator::on_radioButton_clicked()
{
    r_button = 1;
}

void Calculator::on_radioButton_2_clicked()
{
    r_button = 2;
}

void Calculator::on_radioButton_3_clicked()
{
    r_button = 3;
}

void Calculator::on_pushButton_2_clicked()
{
    history* h;
    h = new history(item);
    h->show();
}

void Calculator::on_spinBox_valueChanged(int arg1)
{
   if(ui->checkBox->isChecked())
       Calculator::on_pushButton_clicked();
}

void Calculator::on_spinBox_2_valueChanged(int arg1)
{
    if(ui->checkBox->isChecked())
        Calculator::on_pushButton_clicked();
}


