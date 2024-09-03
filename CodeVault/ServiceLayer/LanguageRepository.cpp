#include <vector>
#include <cppconn/exception.h>
#include "LanguageRepository.h"
#include "../MySQLConnectionManager.h"
#include "../Models/LanguageModel.h"

LanguageRepository::LanguageRepository()
{
	m_connectionManager = MySQLConnectionManager::Instance();
}

std::vector<LanguageModel> LanguageRepository::GetAll() const
{
	//m_connectionManager =  MySQLConnectionManager::Instance();
	m_connectionManager->setSchema("codevaultdb");

	std::vector<LanguageModel> languages;   


	try {
		std::unique_ptr<sql::Statement> stmt(m_connectionManager->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM languages"));

		while (res->next()) {
			int id = res->getInt("language_id");
			std::string name = res->getString("language_name");

			LanguageModel language(id, name);
			languages.push_back(language);
		}
		
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL error: Failed to get languages from database " << e.what() << std::endl;
	}

	return languages;

}
