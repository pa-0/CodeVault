#pragma once
#include <wx/wx.h>

class MySQLConnectionManager;

class App : public wxApp
{
public:;
	  bool OnInit();

	  void RedirectstdoutToConsole(bool bShouldSetConsoleRedirection);

private:
	bool InitializeDatabaseManager(std::unique_ptr<MySQLConnectionManager>& dbManager);

	const std::string m_server = "tcp://127.0.0.1:3306";
	const std::string m_username = "root";
};

