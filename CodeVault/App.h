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
    static LoginFrame* GetLoginFrame() { return m_loginFrame; }
    static MainFrame* GetMainFrame() { return m_mainFrame; }
    static SignUpFrame* GetSignUpFrame() { return m_signUpFrame; }
	void RedirectstdoutToConsole(bool bShouldSetConsoleRedirection);

private:
	bool InitializeDatabaseManager(std::unique_ptr<MySQLConnectionManager>& dbManager);
    static LoginFrame* m_loginFrame;
    static MainFrame* m_mainFrame;
    static SignUpFrame* m_signUpFrame;
	const std::string m_server = "tcp://127.0.0.1:3306";
	const std::string m_username = "root";
	const std::string m_schema = "codevaultdb";
};

