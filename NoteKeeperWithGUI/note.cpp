#include "note.h"
#include "notepool.h"

using std::cin;
using std::cout;
using std::endl;

std::ostream& Note::printNote(std::ostream& os) const {
	os << "\n#" << uniqueID << "\n"
		<< title << "\n"
		<< message << "\n\n";
	if (!resourceLinks.empty()) {
		os << "Resources:" << endl;
		for (auto & link : resourceLinks) {
			os << link << "\n";
		}
		os << endl;
	}
	//prints comma separated list of tags
	if (!tags.empty()) {
		os << "Tags: ";
		for (auto beg = tags.begin(); beg != (tags.end() - 1); ++beg) {
			os << *beg << ", ";
		}
		os << tags.back() << "\n";
	}
	os << timeStamp
		<< "\n\n---\n";
	return os;
}

void Note::addResourceLink(const std::string& link) {
	resourceLinks.push_back(link);
}

void Note::addTag(const std::string& tag) {
	tags.push_back(tag);
}

void Note::setNoteByInput(NotePool& destinationPool) {
	std::string input;
	cout << "Enter Title: ";
	getline(cin, input);
	title = input;
	cout << "Enter Note: ";
	getline(cin, input);
	message = input;
	cout << "Enter Resource Links (\"end\" to stop):\n";
	getline(cin, input);
	while (input != "end") {
		addResourceLink(input);
		getline(cin, input);
	}
	cout << "Existing tags: ";
	destinationPool.tagPool.printTagPool(cout);
	cout << "\nEnter Tags (\"end\" to stop):\n";
	getline(cin, input);
	while (input != "end") {
		if (!destinationPool.tagPool.tagExists(input)) {
			destinationPool.tagPool.addTagToPool(input);
		}
		addTag(input);
		getline(cin, input);
	}
	this->setValidID(destinationPool);
	this->setCurrentTime();
}


std::string currentTimeAsString() {
	std::time_t rawTime = std::time(nullptr);
	std::string strTime(std::asctime(std::localtime(&rawTime)));
	//auto adds a \n. this removes it
	strTime.pop_back();
	return strTime;
}

void Note::setCurrentTime() {
	timeStamp = currentTimeAsString();
}

int Note::getID() const {
	return uniqueID;
}

std::string Note::getTitle() const {
	return title;
}


void Note::setValidID(const NotePool& destinationPool) {
	int validID = destinationPool.getNextValidID();
	uniqueID = validID;
}

void Note::storeNote(std::ofstream& fout) const {
	fout << uniqueID << "\n"
		<< title << "\n"
		<< message << "\n"
		<< timeStamp << "\n"
		<< resourceLinks.size() << endl;
	for (auto & link : resourceLinks) {
		fout << link << "\n";
	}
	fout << tags.size() << "\n";
	for (auto & tag : tags) {
		fout << tag << "\n";
	}
}

bool Note::isTagInNote(const std::string& targetTag) const {
	if (this->findTagIndex(targetTag) == -1) {
		return false;
	}
	return true;
}


std::vector<std::string> Note::getTags() const {
	return tags;
}

int Note::findTagIndex(const std::string& targetTag) const {
	for (int i = 0; i < tags.size(); ++i) {
		if (tags[i] == targetTag) {
			return i;
		}
	}
	return -1;
}

bool Note::deleteTag(const std::string& targetTag) {
	int targetTagIndex = this->findTagIndex(targetTag);
	if (targetTagIndex == -1) {
		return false;
	}
	else {
		tags.erase((tags.begin() + targetTagIndex));
	}
	return true;
}

void Note::setTitle(const std::string& newTitle) {
	title = newTitle;
}

void Note::setMessage(const std::string& newMessage) {
	message = newMessage;
}





