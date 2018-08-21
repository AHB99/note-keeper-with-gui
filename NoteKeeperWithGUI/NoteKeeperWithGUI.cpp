#include "NoteKeeperWithGUI.h"

NoteKeeperWithGUI::NoteKeeperWithGUI(QWidget *parent, NotePool* givenPool)
	: QWidget(parent), mainPool(givenPool)
{
	ui.setupUi(this);
	mainPool->fillListWithNotePool(ui.notesList);
}

void NoteKeeperWithGUI::on_viewAllButton_clicked() {
	mainPool->fillListWithNotePool(ui.notesList);
}

void NoteKeeperWithGUI::on_addNoteButton_clicked() {
	AddNoteDialog addNoteDialog(this);
	if (addNoteDialog.exec()) {
		QString tempTitle = addNoteDialog.addTitleLineEdit->text();
		QString tempMessage = addNoteDialog.addMessagePlainTextEdit->toPlainText();
		mainPool->addNoteToPoolFromDialog(tempTitle.toStdString(), tempMessage.toStdString());
		ui.notesList->clear();
		mainPool->fillListWithNotePool(ui.notesList);
	}
}
