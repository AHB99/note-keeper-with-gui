#include "NoteKeeperWithGUI.h"

NoteKeeperWithGUI::NoteKeeperWithGUI(QWidget *parent, NotePool* givenPool)
	: QWidget(parent), mainPool(givenPool)
{
	ui.setupUi(this);
	mainPool->fillListWithNotePool(ui.notesList);
}

void NoteKeeperWithGUI::on_viewAllButton_clicked() {
	ui.notesList->clear();
	mainPool->fillListWithNotePool(ui.notesList);
}

void NoteKeeperWithGUI::on_addNoteButton_clicked() {
	AddNoteDialog addNoteDialog(this);
	addNoteDialog.setWindowTitle("Add Note");
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

void NoteKeeperWithGUI::on_deleteNoteButton_clicked() {
	if (ui.notesList->selectedItems().count() != 0) {
		int deleteConfirmation = askDeletionConfirmationByMessageBox();

		if (deleteConfirmation == QMessageBox::Yes) {
			int itemRow = ui.notesList->currentRow();
			NoteWidget* noteWidgetToDelete = qobject_cast<NoteWidget*>(ui.notesList->itemWidget(ui.notesList->item(itemRow)));

			if (noteWidgetToDelete) {
				try {
					mainPool->deleteNoteByID(noteWidgetToDelete->getID());
				}
				catch (std::out_of_range) {
					QApplication::instance()->quit();
				}

				QListWidgetItem* itemToDelete = ui.notesList->takeItem(itemRow);
				if (itemToDelete) {
					delete itemToDelete;
				}
			}
		}
	}
}

void NoteKeeperWithGUI::on_editNoteButton_clicked() {
	using EditNoteDialog = AddNoteDialog;
	if (ui.notesList->selectedItems().count() != 0) {
		EditNoteDialog editNoteDialog(this);
		int itemRow = ui.notesList->currentRow();
		NoteWidget* noteWidgetToEdit = qobject_cast<NoteWidget*>(ui.notesList->itemWidget(ui.notesList->item(itemRow)));
		int noteID = noteWidgetToEdit->getID();
		setDefaultEditDialog(noteID, &editNoteDialog);
		
		if (editNoteDialog.exec()) {
			std::vector<std::string> tagsOfNewNote(extractListToVectorOfStrings(editNoteDialog.currentTagsList));
			mainPool->updateTagPool(tagsOfNewNote);

			mainPool->editNoteInPoolFromDialog(noteID, editNoteDialog.addTitleLineEdit->text().toStdString(), editNoteDialog.addMessagePlainTextEdit->toPlainText().toStdString(), extractListToVectorOfStrings(editNoteDialog.currentResourcesList), extractListToVectorOfStrings(editNoteDialog.currentTagsList));
			ui.notesList->clear();
			mainPool->fillListWithNotePool(ui.notesList);
		
		}
	}
}

void NoteKeeperWithGUI::on_filterByTitleButton_clicked() {
	FilterByTitleDialog filterByTitleDialog;
	filterByTitleDialog.setWindowTitle("Filter By Title");
	if (filterByTitleDialog.exec()) {
		NotePool filteredNotes = mainPool->filterByTitle(filterByTitleDialog.filterByTitleLineEdit->text().toStdString());
		if (!filteredNotes.isEmpty()) {
			ui.notesList->clear();
			filteredNotes.fillListWithNotePool(ui.notesList);
		}
	}
}


int askDeletionConfirmationByMessageBox() {
	QMessageBox wantToDelete;
	wantToDelete.setText("Are you sure you want to delete this note?");
	wantToDelete.setIcon(QMessageBox::Warning);
	wantToDelete.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	wantToDelete.setDefaultButton(QMessageBox::No);
	return wantToDelete.exec();
}

void NoteKeeperWithGUI::setDefaultEditDialog(int id, AddNoteDialog* addNoteDialog) {
	using EditNoteDialog = AddNoteDialog;

	Note noteToEdit;
	try {
		noteToEdit = mainPool->searchNoteByValidID(id);
	}
	catch (std::out_of_range) {
		QApplication::instance()->quit();
	}

	addNoteDialog->setWindowTitle("Edit Note");
	extractExistingTagsToComboBox(addNoteDialog->addTagsComboBox);

	addNoteDialog->addTitleLineEdit->setText(QString::fromStdString(noteToEdit.getTitle()));
	addNoteDialog->addMessagePlainTextEdit->setPlainText(QString::fromStdString(noteToEdit.getMessage()));
	for (auto& resource : noteToEdit.getResources()) {
		addNoteDialog->currentResourcesList->addItem(QString::fromStdString(resource));
	}
	for (auto& tag : noteToEdit.getTags()) {
		addNoteDialog->currentTagsList->addItem(QString::fromStdString(tag));
	}

}





