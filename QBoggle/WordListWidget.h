#ifndef WORDLISTWIDGET_H
#define WORDLISTWIDGET_H

#include "WordTable.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableView>

class WordListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WordListWidget(QWidget *parent = nullptr, QString label = "");
    void reset();
signals:

public slots:
    void addScore(int s);
    void addWord(QString word);

private:
    QString label;
    QList<QString> words;
    int score;
    WordTable *wordTable;
    QLabel *scoreLabel;
};

#endif // WORDLISTWIDGET_H
