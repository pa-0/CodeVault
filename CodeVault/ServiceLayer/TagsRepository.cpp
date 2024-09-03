#include <vector>
#include <string>
#include "../MySQLConnectionManager.h"
#include "TagsRepository.h"
#include "../Models/TagModel.h"

TagsRepository::TagsRepository()
{
	m_connectionManager = MySQLConnectionManager::Instance();
}

std::vector<TagModel> TagsRepository::GetAll() const
{
	//m_connectionManager =  MySQLConnectionManager::Instance();
	m_connectionManager->setSchema("codevaultdb");

	std::vector<TagModel> tags;

	try {
		std::unique_ptr<sql::Statement> stmt(m_connectionManager->createStatement());
		std::unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM tags"));

		while (res->next()) {
			int id = res->getInt("tag_id");
			std::string name = res->getString("tag_name");

			TagModel tag(id, name);
			tags.push_back(tag);
		}

	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL error: Failed to get tags from database " << e.what() << std::endl;
	}

	return tags;

}