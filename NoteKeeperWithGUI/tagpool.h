#ifndef TAG_POOL_H
#define TAG_POOL_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class TagPool {
public:
	TagPool() = default;
	std::ostream& printTagPool(std::ostream&);
	bool tagExists(const std::string&) const;
	void addTagToPool(const std::string&);
	bool removeTagFromTagPool(const std::string&);
	void storeTagPool(const std::string&) const;

private:
	//helper to finder and remover
	int findTagIndex(const std::string&) const;

	std::vector<std::string> pool;
};

TagPool loadTagPool(const std::string&);

#endif