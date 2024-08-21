// App.cpp
#include "App.h"
#include "LoginFrame.h"
#include "MainFrame.h"
#include "SignUpFrame.h"

wxIMPLEMENT_APP(App);

LoginFrame* App::m_loginFrame = nullptr;
MainFrame* App::m_mainFrame = nullptr;
SignUpFrame* App::m_signUpFrame = nullptr;

bool App::OnInit() {
    m_loginFrame = new LoginFrame("Code Vault");
    m_loginFrame->SetClientSize(400, 300);
    m_loginFrame->Show();

    m_mainFrame = new MainFrame("Code Vault");
    m_mainFrame->SetClientSize(1200, 800);

    m_signUpFrame = new SignUpFrame("Sign Up");
    m_signUpFrame->SetClientSize(400, 600);

    return true;
}
