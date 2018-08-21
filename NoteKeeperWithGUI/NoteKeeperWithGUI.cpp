#include "NoteKeeperWithGUI.h"

NoteKeeperWithGUI::NoteKeeperWithGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void NoteKeeperWithGUI::on_testButton_clicked() {
	
	NotePool testPool(loadNoteAndTagPool("noteSave.txt", "tagSave.txt"));
	testPool.fillListWithNotePool(ui.notesList);

}
