#pragma once 
#include <string>

class TagModel {
private:
	int tag_id;
	std::string tag_name;

public:
	// Constructor	
	TagModel(int id, const std::string& name)
		: tag_id(id), tag_name(name) {}
	int getTagId() const { return tag_id; }

	std::string getTagName() const { return tag_name; }
	void setTagName(const std::string& name) { tag_name = name; }

};