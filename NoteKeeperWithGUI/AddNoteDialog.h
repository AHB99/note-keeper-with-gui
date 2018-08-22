#pragma once

#include <QDialog>
#include "ui_AddNoteDialog.h"
#include <qlistwidget.h>

class AddNoteDialog : public QDialog, public Ui::AddNoteDialog
{
	Q_OBJECT

public:
	AddNoteDialog(QWidget *parent = Q_NULLPTR);
	~AddNoteDialog();
	private slots:
	void on_addResourceButton_clicked();
	void on_addTagsComboBox_activated(const QString&);
	void on_removeResourceButton_clicked();
	void on_removeTagButton_clicked();

};
