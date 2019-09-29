#ifndef CUBE_H
#define CUBE_H

#include <QLabel>
#include <QWidget>
#include "clickedlabel.h"

class Cube : public QWidget
{
    Q_OBJECT
public:
    explicit Cube(QWidget *parent = nullptr);
    void setLetter(QString l);
    QString getLetter();
    void lightLetter();
    void extinguishLetter();
    int getSize();
    void setSize(int size);

signals:
    void mouseClickCube(int size);
public slots:
    void clicked();

private:
    QString letter;
    ClickedLabel *label;
    bool isclicked=false;
    int size;
};

#endif // CUBE_H
