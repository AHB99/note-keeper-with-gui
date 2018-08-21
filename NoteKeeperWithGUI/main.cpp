#include "NoteKeeperWithGUI.h"
#include <QtWidgets/QApplication>
#include "notepool.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NotePool mainPool(loadNoteAndTagPool(configurations::NOTE_FILE, configurations::TAG_FILE));
	NoteKeeperWithGUI w(Q_NULLPTR,&mainPool);
	w.show();
	return a.exec();
}

