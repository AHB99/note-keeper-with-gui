#pragma once

#include <QDialog>
#include "ui_AddNoteDialog.h"

class AddNoteDialog : public QDialog, public Ui::AddNoteDialog
{
	Q_OBJECT

public:
	AddNoteDialog(QWidget *parent = Q_NULLPTR);
	~AddNoteDialog();
};
