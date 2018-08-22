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
	extractExistingTagsToComboBox(addNoteDialog.addTagsComboBox);

	if (addNoteDialog.exec()) {
		std::vector<std::string> tagsOfNewNote(extractListToVectorOfStrings(addNoteDialog.currentTagsList));
		mainPool->updateTagPool(tagsOfNewNote);

		mainPool->addNoteToPoolFromDialog(addNoteDialog.addTitleLineEdit->text().toStdString(), addNoteDialog.addMessagePlainTextEdit->toPlainText().toStdString(), extractListToVectorOfStrings(addNoteDialog.currentResourcesList),tagsOfNewNote);
		ui.notesList->clear();
		mainPool->fillListWithNotePool(ui.notesList);
	}
}

std::vector<std::string> extractListToVectorOfStrings(QListWidget* sourceList) {
	std::vector<std::string> result;
	for (int i = 0; i < sourceList->count(); ++i) {
		result.push_back((sourceList->item(i)->text()).toStdString());
	}
	return result;
}

void NoteKeeperWithGUI::extractExistingTagsToComboBox(QComboBox* comboBox) {
	for (auto& existingTag : mainPool->tagPool.getTagPool()) {
		comboBox->addItem(QString::fromStdString(existingTag));
	}
	comboBox->clearEditText();
}



