#include "NoteKeeperWithGUI.h"

NoteKeeperWithGUI::NoteKeeperWithGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void NoteKeeperWithGUI::on_testButton_clicked() {
	QListWidgetItem * item = new QListWidgetItem(ui.notesList);
	//TestWidg*  realItem = new TestWidg;
	//item->setSizeHint(realItem->sizeHint());
	Note actualBaseNote;
	NoteWidget * testNote (actualBaseNote.convertToNoteWidget());

	item->setSizeHint(testNote->sizeHint());
	ui.notesList->setItemWidget(item, testNote);
}
