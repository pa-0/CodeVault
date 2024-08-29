#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);


private:
	void SetupSizer();
	void CreateControls();


	wxPanel* panel;
	wxButton* closeSideBarBtn;
	wxButton* addSinppetBtn;
	wxButton* groupsBtn;
	wxButton* favoritesBtn;
	wxButton* profileBtn;
	wxButton* logoutBtn;
	wxTextCtrl* codeSearchBar;



};

