#ifndef CUBE_H
#define CUBE_H

#include <QLabel>
#include <QWidget>

class Cube : public QWidget
{
    Q_OBJECT
public:
    explicit Cube(QWidget *parent = nullptr);
    void setLetter(QString l);
    QString getLetter();

signals:

public slots:

private:
    QString letter;
    QLabel *label;
};

#endif // CUBE_H
