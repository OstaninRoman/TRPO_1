#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "area.h"

class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    Window();
};
#endif
