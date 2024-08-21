#include "App.h"
#include "LoginFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    LoginFrame* loginFrame = new LoginFrame("Code Vault");
    loginFrame->SetClientSize(400, 300);
    loginFrame->Show();
    return true;
}
