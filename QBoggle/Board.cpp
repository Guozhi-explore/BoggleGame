#include "Board.h"
#include "Cube.h"
#include<QTime>
#include<qrandom.h>
#include<QtGlobal>
#include<QVector>
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
            this->cubes[index(i, j)]->setLetter(this->letters[index(i, j)].at(0));
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
    QVector<QChar> vec;
    int r;
    QChar temp;
    for(int i=0;i<size*size;++i)
    {
        for(int j=0;j<letters[i].size();++j)
            vec.append(letters[i].at(j));
    }
    for(int i=0;i<vec.size();++i)
    {
        qsrand(QTime(0,0,0).msecsTo(QTime::currentTime())+i);
        r=i+qrand()%(vec.size()-i);
        temp=vec[i];
        vec[i]=vec[r];
        vec[r]=temp;
    }
    for(int i=0;i<size*size;++i)
    {
        for(int j=0;j<letters[i].size();++j)
        {
            letters[i].replace(j,1,vec[i*size+j]);
        }
    }
}

void Board::receiveInput(QString str)
{
    QFile qFile(":/res/EnglishWords.txt");
    if (!qFile.open(QIODevice::ReadOnly)) {
        throw new std::runtime_error("Resource file not found!");
    }
    Lexicon lex(qFile);
    if(lex.containsPrefix(str.toStdString()))
    qDebug()<<str;
    str=str.toUpper();
    qDebug()<<str;
    if(humanRecursive(str))
    {
        qDebug()<<"[find]  "<<str;
        for(int i=0;i<letterPath.size();++i)
        {
            qDebug()<<letterPath.at(i);
        }
    }
}

bool Board::humanRecursive(QString string)
{
    QVector<int> path;
    for(int i=0;i<size*size;++i)
    {
        if(recursive(string,0,i,path)==true)
            return true;
    }
    return false;
}

bool Board::recursive(QString string,int index, int start,QVector<int> path)
{
    int adjacent;
    if(string.at(index)!=this->cubes[start]->getLetter().at(0))
    {
        return false;
    }
    else{
        qDebug()<<path.size();
        path.append(start);
        if(index==string.size()-1)
        {
            letterPath=path;
            return true;
        }
        for(int row=-1;row<=1;++row)
        {
            for(int column=-1; column<=1;++column)
            {
                adjacent=start+row*size+column;
                if(path.contains(adjacent))
                    continue;
                if(adjacent<0||adjacent>=size*size)
                    continue;
                if(recursive(string,index+1,adjacent,path)==true)
                    return true;
            }
        }
    }
    return false;
}
