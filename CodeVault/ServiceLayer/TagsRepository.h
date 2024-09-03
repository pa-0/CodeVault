#pragma once 
#include <string>
#include "../Models/TagModel.h"

class MySQLConnectionManager;

class TagsRepository
{
public:
	TagsRepository();
	std::vector<TagModel> GetAll() const;

private:
	MySQLConnectionManager* m_connectionManager;

};