#pragma once

#include <QtWidgets/QWidget>
#include "ui_NoteKeeperWithGUI.h"
#include <qlistwidget.h>
#include "TestWidg.h"
#include "NoteWidget.h"
#include "note.h"
#include "notepool.h"

class NoteKeeperWithGUI : public QWidget
{
	Q_OBJECT

public:
	NoteKeeperWithGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::NoteKeeperWithGUIClass ui;
	private slots:
	void on_testButton_clicked();
};
