#ifndef BOARD_H
#define BOARD_H

#include "Cube.h"
#include"Console.h"
#include <QWidget>
#include"lexicon.h"

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr, int size = 5, const QString *cubeLetters = BIG_BOGGLE_CUBES);
    virtual ~Board();
    void shake();
    void lightSeletedWords();

signals:
    void addScoreOfMe(int score);
    void addWordToMe(QString word);
    void addScoreOfComputer(int score);
    void addWordToComputer(QString word);
public slots:
    void receiveInput(QString str);
    void extinguishSeletedWords();
    void receiveClick(QString str);

private:
    int size;
    Cube **cubes;
    QString *letters;
    QString clickLetter;
    QVector<QString> selectedWords;
    QVector<int> letterPath;
    inline int index(int i, int j) { return i * size + j; }
    static const QString STANDARD_CUBES[16];
    static const QString BIG_BOGGLE_CUBES[25];
    bool humanRecursive(QString string);
    bool recursive(QString string,int index,int start,QVector<int>path);
    void computerRecursive();
    void computerrecursive(QString string,int start,QVector<int> path);
    Lexicon *lex;
};

#endif // BOARD_H
