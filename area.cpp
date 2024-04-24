#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}

void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50); // создать таймер
}

void Area::paintEvent(QPaintEvent *) //перерисовка окна
{
    QPainter painter(this);
    painter.setPen(Qt::red); //устанавливает цвет
    myline->move(alpha,&painter); //перемещение на угол alpha
    myrect->move(alpha*(-0.5),&painter);
}

void Area::timerEvent(QTimerEvent *event) // обрабатывает события срабатывания таймера
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной обработки
}

void Area::hideEvent(QHideEvent *) // вызывается при скрытии окна
{
    killTimer(myTimer); // уничтожить таймер
}

Area::~Area()
{
    delete myline;
    delete myrect;
}
