#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);


private:
	void SetupSizer();
	void CreateControls();
	void OnIdentifyLanguage(wxCommandEvent& event);


	wxPanel* panel;
	wxButton* closeSideBarBtn;
	wxButton* addSinppetBtn;
	wxButton* groupsBtn;
	wxButton* favoritesBtn;
	wxButton* profileBtn;
	wxButton* logoutBtn;
	wxTextCtrl* codeSearchBar;

	// New controls for code snippet language identification.
	// TODO: Cleanup and use proper wxWidgets controls
    wxTextCtrl* codeSnippetInput;
    wxStaticText* languageLabel;
    wxButton* identifyLanguageBtn;

};

