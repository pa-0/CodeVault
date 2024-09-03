#pragma once 
#include <string>


class LanguageModel  {
private:
	int language_id;
	std::string language_name;

public:
	// Constructor
	LanguageModel(int id, const std::string& name)
		: language_id(id), language_name(name) {}
	int getLanguageId() const  { return language_id; }

	std::string getLanguageName() const  { return language_name; }
	void setLanguageName(const std::string& name)  { language_name = name; }

};