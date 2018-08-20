#include "tagpool.h"

using std::cin;
using std::cout;
using std::endl;

std::ostream& TagPool::printTagPool(std::ostream& os) {
	if (!(pool.empty())) {
		for (auto beg = pool.begin(); beg != (pool.end() - 1); ++beg) {
			os << *beg << ", ";
		}
		os << pool.back();
	}
	return os;
}

bool TagPool::tagExists(const std::string& tag) const{
	if (this->findTagIndex(tag) == -1) {
		return false;
	}
	return true;
}

void TagPool::addTagToPool(const std::string& tag) {
	pool.push_back(tag);
}

void TagPool::storeTagPool(const std::string& fileName) const {
	std::ofstream fout(fileName);
	if (fout.fail()) {
		std::cout << "Could not save to file." << std::endl;
		return;
	}
	fout << pool.size() << "\n";
	for (auto & poolTag : pool) {
		fout << poolTag << "\n";
	}
	fout.close();
}

bool TagPool::removeTagFromTagPool(const std::string& targetTag){
	int targetTagIndex = this->findTagIndex(targetTag);
	if (targetTagIndex == -1) {
		return false;
	}
	else {
		pool.erase((pool.begin() + targetTagIndex));
	}
	return true;
}

int TagPool::findTagIndex(const std::string& targetTag) const {
	for (int i = 0; i < pool.size(); ++i) {
		if (pool[i] == targetTag) {
			return i;
		}
	}
	return -1;
}



TagPool loadTagPool(const std::string& fileName) {
	TagPool result;
	std::ifstream fin(fileName);
	if (fin.fail()) {
		cout << "Couldn't load notes." << endl;
		return result;
	}
	std::string input;
	if (!getline(fin, input)) {
		return result;
	}
	int numberOfPoolTags = stoi(input);
	for (int i = 0; i < numberOfPoolTags; ++i) {
		getline(fin, input);
		result.addTagToPool(input);
	}
	fin.close();
	return result;
}



