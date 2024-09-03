// App.cpp
#include "App.h"
#include "LoginFrame.h"
#include "MainFrame.h"
#include <wx/wx.h>
#include"MySQLConnectionManager.h"
#include "SignUpFrame.h"
#include "Presenters/BasePresenter.h"
#include "Presenters/PrimaryFramePresenter.h"
wxIMPLEMENT_APP(App);

bool App::OnInit() {
	RedirectstdoutToConsole(true);

	InitDB();

    m_loginFrame = new LoginFrame("Code Vault");
    m_loginFrame->SetClientSize(400, 300);
    m_loginFrame->Show();

	std::unique_ptr<BasePresenter> mainFramePresenter = std::make_unique<PrimaryFramePresenter>();
    m_mainFrame = new MainFrame("Code Vault",dbManager,mainFramePresenter);



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

void App::InitDB()
{
	try {
		 dbManager = MySQLConnectionManager::Instance();

		if(!dbManager)
		{
			std::cerr << "Could not connect to the database!" << std::endl;
			return;
		}
		dbManager->setSchema(m_schema);
	}

	catch (const sql::SQLException& e) {
		std::cerr << "SQL error: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}


