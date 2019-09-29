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

    shake();

    // this->setStyleSheet("background-color:grey; border: 3px solid");
    QFile qFile(":/res/EnglishWords.txt");
    if (!qFile.open(QIODevice::ReadOnly)) {
        throw new std::runtime_error("Resource file not found!");
    }
    lex=new Lexicon(qFile);

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

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
        {
            this->cubes[index(i, j)]->setLetter(this->letters[index(i, j)].at(0));
            if(this->cubes[index(i,j)]->getLetter().compare("Q")==0)
            {
                qDebug()<<"qu";
                this->cubes[index(i, j)]->setLetter("Qu");
            }
        }
    }
}

void Board::receiveInput(QString str)
{
     str=str.toUpper();
    if(str.size()>=4&&!selectedWords.contains(str)||lex->contains(str.toStdString()))
    {
        humanRecursive(str);
    }
    if(str.size()==0)
    {
        computerRecursive();
    }
}

void Board::humanRecursive(QString string)
{
    QVector<int> path;
    for(int i=0;i<size*size;++i)
    {
        if(recursive(string,0,i,path)==true)
        {
            this->addScoreOfMe(string.size()-3);
            this->addWordToMe(string);
            /*light suitable words in the board*/
            this->lightSeletedWords();
            selectedWords.append(string);
        }
    }
}

bool Board::recursive(QString string,int index, int start,QVector<int> path)
{
    int adjacent;
    int length=cubes[start]->getLetter().length();
    QString toCompare=string.mid(index,length);
    if(toCompare.compare(this->cubes[start]->getLetter().toUpper()))
    {
        return false;
    }
    else{
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
                /* skip the case when adjacent has been used*/
                if(path.contains(adjacent))
                    continue;
                if(adjacent<0||adjacent>=size*size||((adjacent%size==0&&start%size==size-1)||(adjacent%size==size-1&&start%size==0)))
                    continue;
                if(recursive(string,index+length,adjacent,path)==true)
                    return true;
            }
        }
    }
    return false;
}

void Board::lightSeletedWords()
{
    for(int i=0;i<letterPath.size();++i)
    {
        this->cubes[letterPath.at(i)]->lightLetter();
    }
}

void Board::extinguishSeletedWords()
{
    for(int i=0;i<letterPath.size();++i)
    {
        this->cubes[letterPath.at(i)]->extinguishLetter();
    }
}

void Board::computerRecursive()
{
    QVector<int> path;
    QString string;
    for(int i=0;i<size*size;++i)
    {
        computerrecursive(string,i,path);
    }
}

void Board::computerrecursive(QString string, int start, QVector<int> path)
{
    int adjacent;
    if(path.contains(start))
        return;
    string.append(cubes[start]->getLetter());
    path.append(start);
    if(lex->containsPrefix(string.toStdString()))
    {
        /* string is a legal word*/
        if(string.size()>=4&&lex->contains(string.toStdString())&&!this->selectedWords.contains(string))
        {
            this->selectedWords.append(string);
            this->addScoreOfComputer(string.size()-3);
            this->addWordToComputer(string);
        }
        for(int row=-1;row<=1;++row)
        {
            for(int column=-1;column<=1;++column)
            {
                adjacent=start+row*size+column;
                if(adjacent>=0&&adjacent<size*size&&!path.contains(adjacent)&&!((adjacent%size==0&&start%size==size-1)||(adjacent%size==size-1&&start%size==0)))
                {
                    computerrecursive(string,adjacent,path);
                }
            }
        }
    }
}
