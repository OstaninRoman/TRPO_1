#include "mainwindow.h"

Win::Win(QWidget *parent):QWidget(parent)
{
    setWindowTitle("Возведение в квадрат"); //устанавливаем заголовок окна
    frame = new QFrame(this); //создаем обьект QFrame
    frame->setFrameShadow(QFrame::Raised); //устанавливаем стиль тени для рамки обьекта qframe
    frame->setFrameShape(QFrame::Panel); //устанавливаем стиль формы
    inputLabel = new QLabel("Введите число:", this); //создаем обьект qlable с текстом
    inputEdit = new QLineEdit("",this); //создаем обьект qlineedite для ввода текста
    StrValidator *v=new StrValidator(inputEdit); //создаем обьект валидатоа для проверки данных
    inputEdit->setValidator(v); //
    outputLabel = new QLabel("Результат:", this); //создаем обьект qlabel с текстом
    outputEdit = new QLineEdit("",this); //создаем обьект qlineedite для вывода текста
    nextButton = new QPushButton("Следующее", this); //создаем обьект кнопку
    exitButton = new QPushButton("Выход", this);

    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); //создаем вертикальную компановку для обьекта frame
    vLayout1->addWidget(inputLabel); //добавляем обьект в компановку
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch(); //добавляет растягиваемое окно в компановку vloyout1

    QVBoxLayout *vLayout2 = new QVBoxLayout(); //создаем вертикальную компановку
    vLayout2->addWidget(nextButton); //добавляем обьект в компановку
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch(); //добавляет растягиваемое окно в компановку vloyout2

    QHBoxLayout *hLayout = new QHBoxLayout(this); //создаем горизонтальную компановку
    hLayout->addWidget(frame); //добавляем обьект в компановку
    hLayout->addLayout(vLayout2);
    begin();

    //устанавливает связь между сигналом clicked от кнопки exitbutton и слотом close в обьекте класса Win
    connect(exitButton, &QPushButton::clicked, this, &Win::close);

    //устанавливает связь между сигналом clicked от кнопки nextbutton и слотом begin в обьекте класса Win
    connect(nextButton, &QPushButton::clicked, this, &Win::begin);

    //устанавливает связь между сигналом returnpressed от виджета inputEdit и слотом calc в обьекте класса Win
    connect(inputEdit, &QLineEdit::returnPressed, this, &Win::calc);
}

void Win::begin() // метод начальной настройки интерфейса
{
    inputEdit->clear(); // очищает поле ввода
    nextButton->setEnabled(false); //делаем недоступным кнопку nextButton
    nextButton->setDefault(false); //задаем значение по умолчанию(кнопка не выделяется)
    inputEdit->setEnabled(true); //поле ввода доступно
    outputLabel->setVisible(false); //обьект outputLabel делаем невидимым
    outputEdit->setVisible(false); //обьект outputEdit делаем невидимым
    outputEdit->setEnabled(false); //не дает редактировать поле с результатом
    inputEdit->setFocus(); //предоставляет фокус ввода с клавиатуры этому обьекту
}

void Win::calc()
{
    bool Ok = true;
    float r,a;
    QString str = inputEdit->text(); //создаем обьект str задаем его равным
    a = str.toDouble(&Ok); //преобразовываем и записываем результат, если произошла ошибка
                            //значение ok изменится
    if (Ok)
    {
        r=a*a;
        str.setNum(r); //устанавливает str значение r
        outputEdit->setText(str); //записываем в outputEdit str(результат)
        inputEdit->setEnabled(false); //inputEdit недоступно
        outputLabel->setVisible(true); //outputLabel видимо
        outputEdit->setVisible(true); //outputEdit видимо
        nextButton->setDefault(true); //nextButton выделяется(можно нажать)
        nextButton->setEnabled(true); //nextButton доступна
        nextButton->setFocus(); //фокус отдается nextButton
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               ("Возведение в квадрат."),
                               ("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec();
        }
}

