#include "Board.h"
#include "Cube.h"
#include<QTime>
#include<qrandom.h>
#include<QtGlobal>
#include <QGridLayout>
#include<QDebug>

const QString Board::STANDARD_CUBES[16]  = {
        "AAEEGN", "ABBJOO", "ACHOPS", "AFFKPS",
        "AOOTTW", "CIMOTU", "DEILRX", "DELRVY",
        "DISTTY", "EEGHNW", "EEINSU", "EHRTVW",
        "EIOSST", "ELRTTY", "HIMNQU", "HLNNRZ"
};

const QString Board::BIG_BOGGLE_CUBES[25]  = {
        "AAAFRS", "AAEEEE", "AAFIRS", "ADENNN", "AEEEEM",
        "AEEGMU", "AEGMNN", "AFIRSY", "BJKQXZ", "CCNSTW",
        "CEIILT", "CEILPT", "CEIPST", "DDLNOR", "DDHNOT",
        "DHHLOR", "DHLNOR", "EIIITT", "EMOTTT", "ENSSSU",
        "FIPRSY", "GORRVW", "HIPRRY", "NOOTUW", "OOOTTU"
};

Board::Board(QWidget *parent, int size, const QString *cubeLetters) : QWidget(parent)
{
    int select_index;
    this->size = size;
    this->cubes = new Cube*[size * size];
    this->letters = new QString[size * size];
    for (int i = 0; i < size * size; ++i)
        this->letters[i] = cubeLetters[i];
    shake();

    QGridLayout *layout = new QGridLayout();
    layout->setMargin(20);
    layout->setSpacing(10);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            this->cubes[index(i, j)] = new Cube(this);
            layout->addWidget(this->cubes[index(i, j)], i, j, Qt::AlignmentFlag::AlignCenter);
        }
    }
    setLayout(layout);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
        {
            qsrand(QTime(0,0,0).msecsTo(QTime::currentTime())+i*j);
            select_index=qrand()%(this->letters[index(i,j)].size());
            this->cubes[index(i, j)]->setLetter(this->letters[index(i, j)].at(select_index));
        }
    }
    // this->setStyleSheet("background-color:grey; border: 3px solid");

}

Board::~Board()
{
    if (cubes) delete[] cubes;
    if (letters) delete[] letters;
}

void Board::shake()
{
    QString tmp;
    int random1,random2;
    for(int i=0;i<100;++i)
    {
        qsrand(QTime(0,0,0).msecsTo(QTime::currentTime())+2*i);
        random1=qrand()%(this->size*this->size);

        qsrand(QTime(0,0,0).msecsTo(QTime::currentTime())+i);
        random2=qrand()%(this->size*this->size);
        tmp=this->letters[random1];
        this->letters[random1]=this->letters[random2];
        this->letters[random2]=tmp;
    }
}

void Board::receiveInput(QString str)
{
    qDebug()<<str;
}

void Board::humanRecursive(QString string)
{

}
