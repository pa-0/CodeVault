#include "LoginFrame.h"
#include "MainFrame.h"
#include "App.h"
#include "SignUpFrame.h"

SignUpFrame::SignUpFrame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition)
{
    SetBackgroundColour(wxColour(15, 58, 102));
    CreateControls();
    SetupSizer();
    SetMinSize(wxSize(400, 600));
    Centre(wxBOTH);
}

void SignUpFrame::SetupSizer()
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* header = new wxStaticText(panel, wxID_ANY, "REGISTER");
    header->SetForegroundColour(wxColour(255, 255, 255));
    wxFont headerFont = header->GetFont();
    headerFont.SetPointSize(24);
    headerFont.SetWeight(wxFONTWEIGHT_BOLD);
    header->SetFont(headerFont);

    mainSizer->Add(header, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 20);

    wxStaticText* usernameLabel = new wxStaticText(panel, wxID_ANY, "Username*");
    usernameLabel->SetForegroundColour(wxColour(255, 255, 255));
    mainSizer->Add(usernameLabel, 0, wxLEFT | wxTOP, 20);

    mainSizer->Add(usernameCtrl, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxStaticText* emailLabel = new wxStaticText(panel, wxID_ANY, "Email*");
    emailLabel->SetForegroundColour(wxColour(255, 255, 255));
    mainSizer->Add(emailLabel, 0, wxLEFT | wxTOP, 20);

    mainSizer->Add(emailCtrl, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxStaticText* passwordLabel = new wxStaticText(panel, wxID_ANY, "Password*");
    passwordLabel->SetForegroundColour(wxColour(255, 255, 255));
    mainSizer->Add(passwordLabel, 0, wxLEFT | wxTOP, 20);

    mainSizer->Add(passwordCtrl, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    wxStaticText* confirmPasswordLabel = new wxStaticText(panel, wxID_ANY, "Confirm Password*");
    confirmPasswordLabel->SetForegroundColour(wxColour(255, 255, 255));
    mainSizer->Add(confirmPasswordLabel, 0, wxLEFT | wxTOP, 20);

    mainSizer->Add(confirmPasswordCtrl, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

    mainSizer->Add(profilePictureButton, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

    mainSizer->Add(registerButton, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 20);

    mainSizer->Add(loginNowLink, 0, wxALIGN_CENTER_HORIZONTAL | wxBOTTOM, 10);

    panel->SetSizer(mainSizer);

}

void SignUpFrame::CreateControls()
{
    panel = new wxPanel(this);

    usernameCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    emailCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
    passwordCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    confirmPasswordCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    profilePictureButton = new wxButton(panel, wxID_ANY, "Profile Picture");
    registerButton = new wxButton(panel, wxID_ANY, "Register", wxDefaultPosition, wxSize(100, 30));
    loginNowLink = new wxHyperlinkCtrl(panel, wxID_ANY, "Already Registered? Log-in now!", wxEmptyString);
    registerButton->Bind(wxEVT_BUTTON, &SignUpFrame::OnRegister, this);
    loginNowLink->Bind(wxEVT_HYPERLINK, &SignUpFrame::OnLoginNow, this);
}

void SignUpFrame::OnRegister(wxCommandEvent& event)
{
    this->Close();
}

void SignUpFrame::OnLoginNow(wxHyperlinkEvent& event)
{
    this->Hide();
    if (App* app = wxDynamicCast(wxApp::GetInstance(), App)) {
        app->SetLoginFrameVisibility(true);
    }
	
}
