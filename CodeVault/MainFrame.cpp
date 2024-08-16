#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr,wxID_ANY,title) {

	CreateControls();
	SetupSizer();
}

void MainFrame::SetupSizer(){


}

void MainFrame::CreateControls()
{
	wxFont healineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));


	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	CodeSearchBar = new wxTextCtrl(panel, wxID_ANY,"", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
	addSinppetBtn = new wxButton(panel, wxID_ANY, "AddSnippet");
	groupsBtn = new wxButton(panel, wxID_ANY, "Groups");
	favoritesBtn = new wxButton(panel, wxID_ANY, "Favourites");
	profileBtn = new wxButton(panel, wxID_ANY, "Profile");
	logoutBtn = new wxButton(panel, wxID_ANY, "Logout");


}
