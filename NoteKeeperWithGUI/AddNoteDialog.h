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
};
