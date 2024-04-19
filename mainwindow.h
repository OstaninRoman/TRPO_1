#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):QLineEdit(contents,parent)
    {
        setReadOnly(true); //не нужно редактирование поля
    }
signals:
    void tick_signal(); //обьявляем новый сигнал
public slots:
    void add_one()
    {
        QString str = text();
        int r = str.toInt();
        if (r!=0 && r%5 == 0) emit tick_signal();
        r++;
        str.setNum(r); //устанавливаем строку str в значение r
        setText(str);
    }
};

class Win: public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    Win(QWidget *parent = 0);
};
#endif
