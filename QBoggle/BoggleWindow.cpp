#include "BoggleWindow.h"
#include "lexicon.h"

#include <QFile>
#include <QHBoxLayout>
#include <QTextEdit>
#include <iostream>

BoggleWindow::BoggleWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("QBoggle!");
    this->setFixedSize(BOGGLE_WINDOW_WIDTH, BOGGLE_WINDOW_HEIGHT);

    me = new WordListWidget(this, "Me");
    computer = new WordListWidget(this, "Computer");
    board = new Board(this);
    console = new Console(this);
    me->setGeometry(20, 20, 230, 300);
    board->setGeometry(230, 0, 300, 300);
    computer->setGeometry(800 - 50 - 200, 20, 230, 300);
    console->setGeometry(30, 320, 740, 260);

    this->connect(console,SIGNAL(newLineWritten(QString)),board,SLOT(receiveInput(QString)));
    this->connect(board,SIGNAL(addScoreOfMe(int)),me,SLOT(addScore(int)));
    this->connect(board,SIGNAL(addWordToMe(QString)),me,SLOT(addWord(QString)));
    this->connect(console,SIGNAL(extinguishSeletedWords()),board,SLOT(extinguishSeletedWords()));
    this->connect(board,SIGNAL(addScoreOfComputer(int)),computer,SLOT(addScore(int)));
    this->connect(board,SIGNAL(addWordToComputer(QString)),computer,SLOT(addWord(QString)));
    this->connect(console,SIGNAL(replay()),this,SLOT(replay()));

    /*
    for (std::string s: lex) {
        std::cout << s << std::endl;
    }
    */
    console->write("[gz]: Welcome to the game Boggle!\n");
}

BoggleWindow::~BoggleWindow()
{
}

void BoggleWindow::replay()
{
    me->reset();
    computer->reset();
    board->shake();
    console->write("[gz]: Welcome to play Boggle again!\n");
}
