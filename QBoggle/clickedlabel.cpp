#include "clickedlabel.h"

ClickedLabel::ClickedLabel()
{

}

void ClickedLabel::mouseReleaseEvent(QMouseEvent *){
    emit Clicked(this);
}
