#pragma once
#include <wx/wx.h>
#include <wx/hyperlink.h>

class SignUpFrame : public wxFrame
{
public:
    SignUpFrame(const wxString& title);

private:
    void SetupSizer();
    void CreateControls();
    void OnRegister(wxCommandEvent& event);
    void OnLoginNow(wxHyperlinkEvent& event);

    wxPanel* panel;
    wxTextCtrl* usernameCtrl;
    wxTextCtrl* emailCtrl;
    wxTextCtrl* passwordCtrl;
    wxTextCtrl* confirmPasswordCtrl;
    wxButton* profilePictureButton;
    wxButton* registerButton;
    wxHyperlinkCtrl* loginNowLink;
};


