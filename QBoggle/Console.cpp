#include "Console.h"
#include <QKeyEvent>
#include <QTextLine>
#include <QTextCursor>

Console::Console(QWidget *parent) : QTextEdit(parent)
{

}


void Console::clear()
{
    this->clear();
}

void Console::write(QString msg)
{
    this->append(msg);
}

void Console::keyPressEvent(QKeyEvent *event)
{
    /*play rules:
     * press enter to confirm word
     * press shift to replay game
     * */
    if (event->key() == Qt::Key_Backspace)
        return;
    if (event->key() == Qt::Key_Delete)
        return;
    /* kick shift to replay buggle game*/
    if(event->key()==Qt::Key_Shift)
        replay();
    if (this->textCursor().hasSelection())
        return;
    if (event->key() == Qt::Key_Return) {
        QTextCursor cursor = this->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.select(QTextCursor::LineUnderCursor);
        QString lastLine = cursor.selectedText();
        newLineWritten(lastLine);
    }
    else{
        //使得点亮的字母块恢复成normal
        extinguishSeletedWords();
    }

    QTextEdit::keyPressEvent(event);
}
