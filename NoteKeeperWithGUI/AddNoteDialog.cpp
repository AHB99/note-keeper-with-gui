#include "AddNoteDialog.h"

AddNoteDialog::AddNoteDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

AddNoteDialog::~AddNoteDialog()
{
}

void AddNoteDialog::on_addResourceButton_clicked() {
	QListWidgetItem * item = new QListWidgetItem(this->addResourceLineEdit->text(),this->currentResourcesList);
	this->addResourceLineEdit->clear();
}

void AddNoteDialog::on_addTagsComboBox_activated(const QString& selectedTag) {
	currentTagsList->addItem(selectedTag);
	addTagsComboBox->clearEditText();
}

void AddNoteDialog::on_removeResourceButton_clicked() {
	QListWidgetItem* itemToDelete = currentResourcesList->takeItem(currentResourcesList->currentRow());
	if (itemToDelete) {
		delete itemToDelete;
	}
}

void AddNoteDialog::on_removeTagButton_clicked() {
	QListWidgetItem* itemToDelete = currentTagsList->takeItem(currentTagsList->currentRow());
	if (itemToDelete) {
		delete itemToDelete;
	}
}




