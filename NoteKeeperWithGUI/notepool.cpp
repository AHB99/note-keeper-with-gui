#include "notepool.h"
#include "note.h"

using std::cin;
using std::cout;
using std::endl;

void NotePool::addNote(const Note& note) {
	pool.push_back(note);
}

std::ostream& NotePool::printNotePool(std::ostream& os) const {
	for (auto & note : pool) {
		note.printNote(os);
	}
	return os;
}

int NotePool::getNextValidID() const {
	//start fresh from 1
	if (pool.empty()) {
		return 1;
	}
	//to move from beginning till last value safely
	int nextID = 2;
	
	while (true) {
		auto iter = pool.begin();
		//search pool if nextID is already used
		while (iter != pool.end()) {
			if ((iter->getID()) == nextID) {
				break;
			}
			++iter;
		}
		//could note find nextID, so return it
		if (iter == pool.end()) {
			return nextID;
		}
		++nextID;
	}
}

void NotePool::storeNoteAndTagPool(const std::string& noteFileName, const std::string& tagFileName) const {
	std::ofstream fout(noteFileName);
	if (fout.fail()) {
		std::cout << "Could not save to file." << std::endl;
		return;
	}
	fout << pool.size() << "\n";
	for (auto & note : pool) {
		note.storeNote(fout);
	}
	fout.close();
	(this->tagPool).storeTagPool(tagFileName);
}


NotePool loadNoteAndTagPool(const std::string& noteFileName, const std::string& tagFileName) {
	NotePool result;
	std::ifstream fin(noteFileName);
	if (fin.fail()) {
		cout << "Couldn't load notes." << endl;
		return result;
	}
	std::string input;
	if (!getline(fin, input)) {
		return result;
	}
	int numberOfNotes = stoi(input);
	for (int i = 0; i < numberOfNotes; ++i) {
		Note currentNote;
		getline(fin, input);
		currentNote.uniqueID = stoi(input);
		getline(fin, input);
		currentNote.title = input;
		getline(fin, input);
		currentNote.message = input;
		getline(fin, input);
		currentNote.timeStamp = input;
		getline(fin, input);
		int numberOfResourceLinks = stoi(input);
		for (int j = 0; j < numberOfResourceLinks; ++j) {
			getline(fin, input);
			(currentNote.resourceLinks).push_back(input);
		}
		getline(fin, input);
		int numberOfTags = stoi(input);
		for (int j = 0; j < numberOfTags; ++j) {
			getline(fin, input);
			(currentNote.tags).push_back(input);
		}
		result.addNote(currentNote);
	}
	fin.close();
	result.tagPool = loadTagPool(tagFileName);
	return result;
}

std::vector<Note>::const_iterator NotePool::findNoteByID(int id) const {
	std::vector<Note>::const_iterator result;
	for (result = pool.cbegin(); result != pool.cend(); ++result) {
		if (result->getID() == id) {
			return result;
		}
	}
	throw std::out_of_range("Invalid ID entered.");
}


Note NotePool::searchNoteByValidID(int id) const {
	auto targetPosition = this->findNoteByID(id);
	return (*targetPosition);
}

NotePool NotePool::filterByTags(std::vector<std::string> targetTags) const {
	NotePool result;
	for (auto& note : pool) {
		for (auto& targetTag : targetTags) {
			if (note.isTagInNote(targetTag)) {
				result.addNote(note);
				break;
			}
		}
	}
	return result;
}

bool NotePool::deleteNoteByID(int id) {
	//hack to remove constness
	std::vector<Note>::iterator targetPosition = pool.begin() + (this->findNoteByID(id) - pool.cbegin());
	pool.erase(targetPosition);
	return true;
}

void NotePool::inputNoteToPool() {
	Note inputNote;
	inputNote.setNoteByInput(*this);
	this->addNote(inputNote);
}

bool NotePool::deleteTagFromNotes(const std::string& targetTag) {
	//if couldn't remove from tagpool, then it doesn't exist anyway
	if (!(tagPool.removeTagFromTagPool(targetTag))) {
		return false;
	}
	for (auto& note : pool) {
		note.deleteTag(targetTag);
	}
	return true;
}

NotePool NotePool::filterByTitle(const std::string& targetTitle) const {
	NotePool result;
	for (auto& note : pool) {
		std::string noteTitle(note.getTitle());
		if (noteTitle.std::string::find(targetTitle) != std::string::npos) {
			result.addNote(note);
		}
	}
	return result;
}

void NotePool::editTitleByID(int id, const std::string& newTitle) {
	//hack to remove constness. may throw
	std::vector<Note>::iterator targetPosition = pool.begin() + (this->findNoteByID(id) - pool.cbegin());
	(targetPosition->setTitle(newTitle));
}

void NotePool::editMessageByID(int id, const std::string& newMessage) {
	//hack to remove constness. may throw
	std::vector<Note>::iterator targetPosition = pool.begin() + (this->findNoteByID(id) - pool.cbegin());
	(targetPosition->setMessage(newMessage));
}

void NotePool::fillListWithNotePool(QListWidget* destinationList) const {
	for (auto& note : pool) {
		note.addNoteToList(destinationList);
	}
}

void NotePool::addNoteToPoolFromDialog(const std::string& titleFromDialog, const std::string& messageFromDialog, const std::vector<std::string>& resourcesFromDialog) {
	Note noteToAdd;
	noteToAdd.setNoteByDialogInput(*this, titleFromDialog, messageFromDialog, resourcesFromDialog);
	this->addNote(noteToAdd);
}











