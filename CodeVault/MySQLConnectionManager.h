#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/statement.h>
#include <memory>

class MySQLConnectionManager
{
public:
    MySQLConnectionManager(const std::string& server, const std::string& username, const std::string& password)
        : m_server(server), m_username(username), m_password(password)
    {
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
    std::string m_server;
    std::string m_username;
    std::string m_password;
    sql::Driver* m_driver;
    std::unique_ptr<sql::Connection> m_connection;
};