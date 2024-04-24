#include "mainwindow.h"

Window::Window()
{
    this->setWindowTitle("Обработка событий");
    area = new Area(this); //создаем холст
    btn = new QPushButton("Завершить", this);
    QVBoxLayout *layout = new QVBoxLayout(this); //вертикальная компановка
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, &QWidget::close);
};

