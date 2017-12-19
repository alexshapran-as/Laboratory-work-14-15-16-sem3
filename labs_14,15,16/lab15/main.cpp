#include <QtGui/QApplication>
#include "calculator.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *cyrillicCodec = QTextCodec::codecForName("Windows-1251");
    QTextCodec::setCodecForTr(cyrillicCodec);
    QTextCodec::setCodecForLocale(cyrillicCodec);
    QTextCodec::setCodecForCStrings(cyrillicCodec);
    QApplication a(argc, argv);
    Calculator w;
    w.show();
    
    return a.exec();
}
