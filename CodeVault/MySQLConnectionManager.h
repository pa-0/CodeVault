#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <memory>
#include <mutex>
#include <string>
#include <iostream>
#include <cstdlib>

class MySQLConnectionManager
{
public:
    // Delete copy constructor and assignment operator
    MySQLConnectionManager(const MySQLConnectionManager&) = delete;
    MySQLConnectionManager& operator=(const MySQLConnectionManager&) = delete;

    // Static method to get the instance
    static MySQLConnectionManager* Instance()
    {
        // First check (without locking)
        if (_instance == nullptr)
        {
            // Locking
            std::lock_guard<std::mutex> lock(_mutex);	const std::string m_server = "tcp://127.0.0.1:3306";
            const std::string m_username = "root";
            const std::string m_schema = "codevaultdb";
            // Second check (with locking)
            if (_instance == nullptr)
            {
                // Instance creation
                _instance = new MySQLConnectionManager(m_server, m_username);
            }
        }
        return _instance;
    }

    void setSchema(const std::string& schema)
    {
        m_connection->setSchema(schema);
    }

    std::unique_ptr<sql::Statement> createStatement()
    {
        return std::unique_ptr<sql::Statement>(m_connection->createStatement());
    }

    std::unique_ptr<sql::PreparedStatement> prepareStatement(const std::string& query)
    {
        return std::unique_ptr<sql::PreparedStatement>(m_connection->prepareStatement(query));
    }

private:
    // Private constructor to prevent instantiation
    MySQLConnectionManager(const std::string& server, const std::string& username)
        : m_server(server), m_username(username)
    {

       
        m_password = GetEnvVar("MYSQL_PASSWORD"); // Retrieve environment variable
     
        if (m_password == "") {
            std::cerr << "Environment variable MYSQL_PASSWORD is not set!" << std::endl;
            return; // Exit the application or handle the error as needed
        }

       // m_password = password_env;
        try
        {
            m_driver = get_driver_instance();
            m_connection = std::unique_ptr<sql::Connection>(m_driver->connect(m_server, m_username, m_password));
        }
        catch (sql::SQLException& e)
        {
            std::cerr << "Could not connect to server. Error message: " << e.what() << std::endl;
            throw;
        }
    }

    std::string GetEnvVar(const std::string& var)
    {
        char* buffer = nullptr;
        size_t size = 0;
        if (_dupenv_s(&buffer, &size, var.c_str()) == 0 && buffer != nullptr) {
            std::string value(buffer);
            free(buffer); // Free the allocated buffer
            return value;
        }
        return "";
    }

    const std::string m_server = "tcp://127.0.0.1:3306";
    const std::string m_username = "root";
    std::string m_password;
    sql::Driver* m_driver;
    std::unique_ptr<sql::Connection> m_connection;

    //Defining Static Members 
    static MySQLConnectionManager* _instance;
    static std::mutex _mutex;
};




//OLD IMPLEMENTATION

//class MySQLConnectionManager
//{
//public:
//    MySQLConnectionManager(const std::string& server, const std::string& username, const std::string& password)
//        : m_server(server), m_username(username), m_password(password)
//    {
//        try
//        {
//            
//            m_driver = get_driver_instance();
//            m_connection = std::unique_ptr<sql::Connection>(m_driver->connect(m_server, m_username, m_password));
//        }
//        catch (sql::SQLException& e)
//        {
//            std::cerr << "Could not connect to server. Error message: " << e.what() << std::endl;
//            throw;
//        }
//    }
//
//    void setSchema(const std::string& schema)
//    {
//        m_connection->setSchema(schema);
//    }
//
//    std::unique_ptr<sql::Statement> createStatement()
//    {
//        return std::unique_ptr<sql::Statement>(m_connection->createStatement());
//    }
//
//    std::unique_ptr<sql::PreparedStatement> prepareStatement(const std::string& query)
//    {
//        return std::unique_ptr<sql::PreparedStatement>(m_connection->prepareStatement(query));
//    }
//
//private:
//    std::string m_server;
//    std::string m_username;
//    std::string m_password;
//    sql::Driver* m_driver;
//    std::unique_ptr<sql::Connection> m_connection;
//};