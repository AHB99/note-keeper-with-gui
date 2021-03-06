#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include "NoteWidget.h"

class NotePool;
class QListWidget;

class Note {
	friend NotePool loadNoteAndTagPool(const std::string&, const std::string&);
public:
	Note() = default;

	std::ostream& printNote(std::ostream&) const;
	void setNoteByInput(NotePool&);
	int getID() const;
	std::string getTitle() const;
	std::string getMessage() const;
	std::vector<std::string> getResources() const;
	std::vector<std::string> getTags() const;
	bool isTagInNote(const std::string&) const;
	void storeNote(std::ofstream&) const;
	bool deleteTag(const std::string&);
	void setTitle(const std::string&);
	void setMessage(const std::string&);
	void addNoteToList(QListWidget* destinationList) const;

	void setNoteByDialogInput(const NotePool&, const std::string&, const std::string&, const std::vector<std::string>&, const std::vector<std::string>&);
	void editNoteByDialogInput(const std::string&, const std::string&, const std::vector<std::string>&, const std::vector<std::string>&);

	
private:
	void addResourceLink(const std::string&);
	void addTag(const std::string&);
	void setCurrentTime();
	void setValidID(const NotePool&);

	int findTagIndex(const std::string&) const;

	//returns pointer to dynamically allocated notewidget form of a given note
	//helper for adding note to list
	NoteWidget* convertToNoteWidget() const;

	std::string title = "Debug Title";
	std::string message = "Debug Message that has text for this note.";
	std::vector<std::string> resourceLinks;
	std::vector<std::string> tags;
	std::string timeStamp = "DEBUG TIME STAMP";
	int uniqueID = -1;
};

std::string currentTimeAsString();

#endif 
