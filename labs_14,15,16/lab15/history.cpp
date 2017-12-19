#include "history.h"
#include "ui_history.h"
#include "calculator.h"
extern unsigned int count;
history::history(QStringList item, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
    ui->listWidget->addItems(item);
}

history::~history()
{
    delete ui;
}

void history::on_pushButton_clicked()
{
   /* QString str = ui->listWidget->items();
    for (unsigned int i = {0}; i < str.size(); ++i)
    {
        if (str[i] == ' ')
        {
            QString temp = str;
            temp.chop(temp.size() - i);
            //temp.erase(0,i);
            int x = temp.toInt();
            if (i < 2)
                Calculator::ui->spinBox->setValue(x);
            else if (i > 2)
                Calculator::ui->spinBox_2->setValue(x);
        }
    }*/
}
