#include "NoteWidget.h"

NoteWidget::NoteWidget(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
}

NoteWidget::~NoteWidget()
{
}

int NoteWidget::getID() const {
	return idOfNote;
}
void NoteWidget::setID(int givenID) {
	idOfNote = givenID;
}