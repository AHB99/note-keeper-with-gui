#include "NoteKeeperWithGUI.h"
#include <qlistwidget.h>
#include "TestWidg.h"
#include "NoteWidget.h"

NoteKeeperWithGUI::NoteKeeperWithGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void NoteKeeperWithGUI::on_testButton_clicked() {
	QListWidgetItem * item = new QListWidgetItem(ui.notesList);
	//TestWidg*  realItem = new TestWidg;
	//item->setSizeHint(realItem->sizeHint());

	NoteWidget * testNote = new NoteWidget(ui.notesList);
	item->setSizeHint(testNote->sizeHint());
	ui.notesList->setItemWidget(item, testNote);
}
