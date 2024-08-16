#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr,wxID_ANY,title) {

	CreateControls();
	SetupSizer();
}

void MainFrame::SetupSizer(){

	

	wxBoxSizer* primaryHorizontalSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* sideMenuVerticalSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* codeViewVerticalSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* codeSearchBarSizer= new wxBoxSizer(wxHORIZONTAL);
	
	sideMenuVerticalSizer->Add(closeSideBarBtn, wxSizerFlags().Left());
	sideMenuVerticalSizer->Add(addSinppetBtn, wxSizerFlags().Left());
	sideMenuVerticalSizer->Add(groupsBtn, wxSizerFlags().Left());
	sideMenuVerticalSizer->Add(favoritesBtn, wxSizerFlags().Left());
	sideMenuVerticalSizer->Add(logoutBtn, wxSizerFlags().Left());


	primaryHorizontalSizer->Add(sideMenuVerticalSizer, wxSizerFlags().Proportion(0).Expand());
	primaryHorizontalSizer->Add(codeViewVerticalSizer, wxSizerFlags().Proportion(1).Expand());
	codeSearchBarSizer->Add(codeSearchBar, wxSizerFlags().Proportion(1).Expand());

	codeViewVerticalSizer->Add(codeSearchBarSizer,wxSizerFlags().Expand());

	panel->SetSizer(primaryHorizontalSizer);
	primaryHorizontalSizer->SetSizeHints(this);
}

void MainFrame::CreateControls()
{
	wxFont healineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));


	panel = new wxPanel(this);
	panel->SetFont(mainFont);

	codeSearchBar = new wxTextCtrl(panel, wxID_ANY,"", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);

	closeSideBarBtn = new wxButton(panel, wxID_ANY, "CloseSideBar");
	addSinppetBtn = new wxButton(panel, wxID_ANY, "AddSnippet");
	groupsBtn = new wxButton(panel, wxID_ANY, "Groups");
	favoritesBtn = new wxButton(panel, wxID_ANY, "Favourites");
	profileBtn = new wxButton(panel, wxID_ANY, "Profile");
	logoutBtn = new wxButton(panel, wxID_ANY, "Logout");
	

}
