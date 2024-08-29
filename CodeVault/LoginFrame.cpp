#include "LoginFrame.h"
#include "MainFrame.h"
#include "App.h"
#include "SignUpFrame.h"

LoginFrame::LoginFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition)
{
    SetBackgroundColour(wxColour(15, 58, 102));
    CreateControls();
    SetupSizer();
    SetMinSize(wxSize(400, 400));
    Centre(wxBOTH);
}


void LoginFrame::SetupSizer()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* title = new wxStaticText(panel, wxID_ANY, "LOGIN");
    title->SetForegroundColour(wxColour(255, 255, 255));
    title->SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    mainSizer->Add(title, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);

    wxStaticText* usernameLabel = new wxStaticText(panel, wxID_ANY, "Username");
    usernameLabel->SetForegroundColour(wxColour(255, 255, 255));
    mainSizer->Add(usernameLabel, 0, wxLEFT | wxTOP, 20);

    mainSizer->Add(usernameCtrl, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password");
    passwordLabel->SetForegroundColour(wxColour(255, 255, 255));
    mainSizer->Add(passwordLabel, 0, wxLEFT | wxTOP, 20);

    mainSizer->Add(passwordCtrl, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    mainSizer->Add(forgotPasswordLink, 0, wxALIGN_LEFT | wxLEFT | wxTOP, 10);

    mainSizer->Add(loginButton, 0, wxALIGN_LEFT | wxLEFT | wxTOP, 10);

    mainSizer->Add(signupLink, 0, wxALIGN_LEFT | wxLEFT | wxRIGHT | wxTOP, 10);

    panel->SetSizer(mainSizer);
}

void LoginFrame::CreateControls()
{
    panel = new wxPanel(this);

    usernameCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0);
    passwordCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    loginButton = new wxButton(panel, wxID_ANY, "Login", wxDefaultPosition, wxSize(100, 30));
    forgotPasswordLink = new wxHyperlinkCtrl(panel, wxID_ANY, "Forgot Password", wxEmptyString);
    signupLink = new wxHyperlinkCtrl(panel, wxID_ANY, "Don't have an Account? Sign-up now!", wxEmptyString);
    loginButton->Bind(wxEVT_BUTTON, &LoginFrame::OnLogin, this);
    signupLink->Bind(wxEVT_HYPERLINK, &LoginFrame::OnSignUp, this);
}

void LoginFrame::OnLogin(wxCommandEvent& event)
{
    this->Hide();
    MainFrame* mainFrame = App::GetMainFrame();
    if (mainFrame)
    {
        mainFrame->Show();
    }
}

void LoginFrame::OnSignUp(wxHyperlinkEvent& event)
{
    this->Hide();
	SignUpFrame* signUpFrame = App::GetSignUpFrame();
    if (signUpFrame)
	{
		signUpFrame->Show();
	}
}
