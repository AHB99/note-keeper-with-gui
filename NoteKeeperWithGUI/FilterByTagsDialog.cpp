#include "FilterByTagsDialog.h"

FilterByTagsDialog::FilterByTagsDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

FilterByTagsDialog::~FilterByTagsDialog()
{
}

void FilterByTagsDialog::on_tagsComboBox_activated(const QString& selected) {
	selectedTagsList->addItem(selected);
}

void FilterByTagsDialog::on_removeTagButton_clicked() {
	QListWidgetItem* itemToDelete = selectedTagsList->takeItem(selectedTagsList->currentRow());
	if (itemToDelete) {
		delete itemToDelete;
	}
}

