#include "Cube.h"
#include<QDebug>
#include <QHBoxLayout>

Cube::Cube(QWidget *parent) : QWidget(parent)
{
    label = new ClickedLabel();
    label->setText("");
    label->setAlignment(Qt::AlignCenter);
    QFont font = label->font();
    font.setPointSize(20);
    label->setFont(font);

    this->setFixedSize(75, 75);
    this->setStyleSheet("background-color: white; border-radius: 15px; border: 2px solid");

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);

    connect(label,SIGNAL(Clicked(ClickedLabel*)),this,SLOT(clicked()));
    //connect(label,SIGNAL())
    setLayout(layout);
}

void Cube::setLetter(QString l)
{
    letter=l;
    label->setText(l);
}

QString Cube::getLetter()
{
    return this->letter;
}

void Cube::lightLetter(){
    label->setStyleSheet("background-color: yellow; border-radius: 15px; border: 2px solid");
}

void Cube::extinguishLetter()
{
    this->isclicked=false;
    label->setStyleSheet("background-color: white; border-radius: 15px; border: 2px solid");
}

void Cube::clicked()
{
    /*ensure a cube can only be clicked once during a search procedure*/
    if(isclicked==false)
    {
        isclicked=true;
        lightLetter();
        emit mouseClickCube(size);
    }
}

int Cube::getSize()
{
    return size;
}

void Cube::setSize(int size)
{
    this->size=size;
}
