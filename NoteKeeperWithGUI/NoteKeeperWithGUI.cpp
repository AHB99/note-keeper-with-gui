#include "NoteKeeperWithGUI.h"
#include <qlistwidget.h>
#include "TestWidg.h"

NoteKeeperWithGUI::NoteKeeperWithGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void NoteKeeperWithGUI::on_testButton_clicked() {
	//QListWidgetItem * item = new QListWidgetItem("blahblahblah\nVery long run on sentence very long\nmore stuff\nmore\nlasdkhfla\nsdlifj\nadsfa\nadsf", ui.notesList);
	QListWidgetItem * item = new QListWidgetItem(ui.notesList);
	TestWidg*  realItem = new TestWidg;
	
	item->setSizeHint(realItem->sizeHint());
	ui.notesList->setItemWidget(item, realItem);
}
