#include "NoteKeeperWithGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	NoteKeeperWithGUI w;
	w.show();
	return a.exec();
}
