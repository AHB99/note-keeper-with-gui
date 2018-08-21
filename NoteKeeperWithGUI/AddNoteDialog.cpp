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

