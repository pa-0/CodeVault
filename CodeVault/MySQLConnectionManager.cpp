#include "MySQLConnectionManager.h"

// Initializiation of static members
MySQLConnectionManager* MySQLConnectionManager::_instance = nullptr;
std::mutex MySQLConnectionManager::_mutex;
