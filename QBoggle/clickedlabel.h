#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include <QWidget>
#include<QLabel>

class ClickedLabel :public QLabel
{
    Q_OBJECT
signals:
    void Clicked(ClickedLabel *clicked);
public:
    ClickedLabel();
protected:
    void mouseReleaseEvent(QMouseEvent*);
};

#endif // CLICKEDLABEL_H
