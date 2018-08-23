#pragma once

#include <QDialog>
#include "ui_FilterByTitleDialog.h"

class FilterByTitleDialog : public QDialog, public Ui::FilterByTitleDialog
{
	Q_OBJECT

public:
	FilterByTitleDialog(QWidget *parent = Q_NULLPTR);
	~FilterByTitleDialog();
};
