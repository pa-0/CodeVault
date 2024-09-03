#pragma once
#include <string>

struct DbConnectionParams {
	const std::string server = "tcp://127.0.0.1:3306";
	const std::string username = "root";
	const std::string schema = "codevaultdb";

};