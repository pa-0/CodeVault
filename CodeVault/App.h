// App.h
#include <wx/wx.h>
#include "LoginFrame.h"
#include "MainFrame.h"
#include "SignUpFrame.h"
#define APP_H

class MySQLConnectionManager;

class App : public wxApp
{
public:;
	bool OnInit();
	void RedirectstdoutToConsole(bool bShouldSetConsoleRedirection);

	void SetMainFrameVisibility(bool val);
	void SetLoginFrameVisibility(bool val);
	void SetSignupFrameVisibility(bool val);
private:
	bool InitializeDatabaseManager(std::unique_ptr<MySQLConnectionManager>& dbManager);
    LoginFrame* m_loginFrame;
    MainFrame* m_mainFrame;
    SignUpFrame* m_signUpFrame;
	const std::string m_server = "tcp://127.0.0.1:3306";
	const std::string m_username = "root";
	const std::string m_schema = "codevaultdb";
};

