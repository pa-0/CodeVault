#pragma once
#include <string>
#include "../Models/LanguageModel.h"


class MySQLConnectionManager;

class LanguageRepository
{
public:	
	LanguageRepository();
	std::vector<LanguageModel> GetAll() const;

 
	private:
	 MySQLConnectionManager* m_connectionManager;

};

