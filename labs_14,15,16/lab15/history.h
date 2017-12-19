#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>

namespace Ui {
class history;
}

class history : public QDialog
{
    Q_OBJECT
    
public:
    explicit history(QStringList item, QWidget *parent = 0);
    ~history();
    
//private:
public:
    Ui::history *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // HISTORY_H
