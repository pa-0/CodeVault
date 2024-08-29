#pragma once
#include <wx/wx.h>
#include <wx/hyperlink.h>


class LoginFrame : public wxFrame
{
public:
    LoginFrame(const wxString& title);

private:
    void SetupSizer();
    void CreateControls();
    void OnLogin(wxCommandEvent& event);
    void OnSignUp(wxHyperlinkEvent& event);

    wxPanel* panel;
    wxTextCtrl* usernameCtrl;
    wxTextCtrl* passwordCtrl;
    wxButton* loginButton;
    wxHyperlinkCtrl* forgotPasswordLink;
    wxHyperlinkCtrl* signupLink;
};
