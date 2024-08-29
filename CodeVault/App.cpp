// App.cpp
#include "App.h"
#include "LoginFrame.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include"MySQLConnectionManager.h"
#include "SignUpFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	RedirectstdoutToConsole(true);
	std::unique_ptr<MySQLConnectionManager>	dbmanager;

	if (!InitializeDatabaseManager(dbmanager)) {
		return false; // Exit if the database initialization fails
	}

    m_loginFrame = new LoginFrame("Code Vault");
    m_loginFrame->SetClientSize(400, 300);
    m_loginFrame->Show();

    m_mainFrame = new MainFrame("Code Vault",std::move(dbmanager));
    m_mainFrame->SetClientSize(1200, 800);
	m_mainFrame->SetMinSize(wxSize(800,600));

    m_signUpFrame = new SignUpFrame("Sign Up");
    m_signUpFrame->SetClientSize(400, 600);

	return true;
}

void App::RedirectstdoutToConsole(bool bShouldSetConsoleRedirection)
{
	if (!bShouldSetConsoleRedirection) return;
	AllocConsole(); // Create a console window
	freopen("CONOUT$", "w", stdout); // Redirect stdout to the console
	std::cout << "Console output enabled!" << std::endl;
}



bool App::InitializeDatabaseManager(std::unique_ptr<MySQLConnectionManager>& dbManager) {
	

	const char* password_env = std::getenv("MYSQL_PASSWORD"); // Retrieve environment variable

	if (!password_env) {
		std::cerr << "Environment variable MYSQL_PASSWORD is not set!" << std::endl;
		return false; // Exit the application or handle the error as needed
	}

	const std::string password = password_env; // Convert to std::string if valid
	

	try {
		dbManager = std::make_unique<MySQLConnectionManager>(m_server, m_username, password);
		dbManager->setSchema(m_schema);
	}
	catch (sql::SQLException& e) {
		std::cerr << "Database error: " << e.what() << std::endl;
		return false;
	}

	return true;
}

void App::SetMainFrameVisibility(bool val)
{
	if (val) {
		m_mainFrame->Show();
		m_mainFrame->Center();
	}
	else {
		m_mainFrame->Hide();
	}
	
}

void App::SetLoginFrameVisibility(bool val)
{
	if (val) {
		m_loginFrame->Show();
	}
	else {
		m_loginFrame->Hide();
	}
	
}

void App::SetSignupFrameVisibility(bool val)
{
	if (val) {
		m_signUpFrame->Show();
	}
	else {
		m_signUpFrame->Hide();
	}
}
