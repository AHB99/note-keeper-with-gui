#pragma once

#include <QDialog>
#include "ui_FilterByTagsDialog.h"
#include <qlistwidget.h>
class FilterByTagsDialog : public QDialog, public Ui::FilterByTagsDialog
{
	Q_OBJECT

public:
	FilterByTagsDialog(QWidget *parent = Q_NULLPTR);
	~FilterByTagsDialog();
	private slots:
	void on_tagsComboBox_activated(const QString&);
	void on_removeTagButton_clicked();

};
