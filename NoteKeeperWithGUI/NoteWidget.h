#pragma once

#include <QWidget>
#include "ui_NoteWidget.h"

class NoteWidget : public QWidget, public Ui::NoteWidget
{
	Q_OBJECT

public:
	NoteWidget(QWidget *parent = Q_NULLPTR);
	~NoteWidget();
	int getID() const;
	void setID(int);
private:
	int idOfNote;
};
