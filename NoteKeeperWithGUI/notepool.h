#ifndef NOTE_POOL_H
#define NOTE_POOL_H

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "tagpool.h"
#include <qlistwidget.h>

class Note;

class NotePool {
	friend NotePool loadNoteAndTagPool(const std::string&, const std::string&);

public:
	NotePool() = default;

	std::ostream& printNotePool(std::ostream&) const;
	int getNextValidID() const;
	void storeNoteAndTagPool(const std::string&, const std::string&) const;
	Note searchNoteByValidID(int) const;
	NotePool filterByTags(std::vector<std::string>) const;
	bool deleteNoteByID(int);
	void inputNoteToPool();
	bool deleteTagFromNotes(const std::string&);
	NotePool filterByTitle(const std::string&) const;
	void editTitleByID(int, const std::string&);
	void editMessageByID(int, const std::string&);

	void fillListWithNotePool(QListWidget*) const;


	TagPool tagPool;

private:
	//helper for inputNoteToPool
	void addNote(const Note&);

	//helper function for searching and deleting
	std::vector<Note>::const_iterator findNoteByID(int) const;
	std::vector<Note> pool;
};

NotePool loadNoteAndTagPool(const std::string&, const std::string&);


#endif