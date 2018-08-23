#pragma once

#include <QtWidgets/QWidget>
#include "ui_NoteKeeperWithGUI.h"
#include <qlistwidget.h>
#include "TestWidg.h"
#include "NoteWidget.h"
#include "note.h"
#include "notepool.h"
#include "AddNoteDialog.h"
#include <qmessagebox.h>

class NoteKeeperWithGUI : public QWidget
{
	Q_OBJECT

public:
	NoteKeeperWithGUI(QWidget *parent = Q_NULLPTR, NotePool* givenPool = nullptr);

private:
	void extractExistingTagsToComboBox(QComboBox*);

	Ui::NoteKeeperWithGUIClass ui;
	NotePool* mainPool;

	private slots:
	void on_viewAllButton_clicked();
	void on_addNoteButton_clicked();
	void on_deleteNoteButton_clicked();
};

std::vector<std::string> extractListToVectorOfStrings(QListWidget*);
int askDeletionConfirmationByMessageBox();

namespace configurations {
	const std::string NOTE_FILE = "noteSave.txt";
	const std::string TAG_FILE = "tagSave.txt";
}
