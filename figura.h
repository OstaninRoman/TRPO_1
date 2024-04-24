#ifndef FIGURA_H
#define FIGURA_H
#include <QPainter> //класс QPainter выполняет низкоуровневое рисование на виджетах и ​​других устройствах рисования

class Figura
{
protected:
    int x, y, halflen, dx, dy, r;
    virtual void draw(QPainter *Painter)=0; //метод для отричовки фигуры
public:
    Figura(int X,int Y,int Halflen):x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter);
};

class MyLine:public Figura
{
protected:
    void draw(QPainter *Painter) override; //переопределяем метод
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){}
};

class MyRect:public Figura
{
protected:
    void draw(QPainter *Painter) override;
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){}
};
#endif
