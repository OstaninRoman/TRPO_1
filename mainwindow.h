#ifndef MAINWINDOW_H //директива для предотвращения многократного включения файла
#define MAINWINDOW_H

#include <QtWidgets> //библиотека для всех обьектов пользовательского интерфейса

class Win:public QWidget // класс окна
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов

protected:
    //обьявление указателей на различные виджеты, которые будут использоваться в пользовательском интерфейсе окна
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход

public:
    Win(QWidget *parent = 0); // конструктор

public slots:
    //методы класса
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
};

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){} //конструктор наследника с вызовом конструктора базового класса
    State validate(QString &str,int &pos)const override //метод проверки вводимой строки
    {
        auto msg = QMessageBox(
                    QMessageBox::Information,
                    "Предупреждение",
                    "Вызван метод validate",
                    QMessageBox::Ok
                );
                msg.exec();
        return Acceptable; // метод всегда принимает вводимую строку
    }
};
#endif
