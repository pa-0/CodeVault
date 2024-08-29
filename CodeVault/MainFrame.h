#pragma once
#include <wx/wx.h>
#include <vector>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>
#include <wx/scrolwin.h>
#include <wx/wrapsizer.h>
#include "CodeVaultDataStructs.h"




//forward declarations
class CVGradientPanel;
class CVGradientTxtCtrl;
class wxComboCtrl;
class MySQLConnectionManager;

namespace sql {
	class PreparedStatement;
}



class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);


private:
	void SetupSizer();
	void CreateControls();
	void SetupSidePanelUI();
	void BindSidePanelButtonEvents(const std::vector<wxButton*>& sidePanelButtons);
	void BindVaultLanguageButtonEvents(const std::vector<wxBitmapButton*>& languageButtons);
	void SetSidPanelUIProfile(const std::vector<wxButton*>& buttons,wxColor backgroundColor, wxFont font);
	void SetVaultViewUI();
	void SetSnippetFormUI();

	//Data Functions
	void OnAddSnippetSubmit(wxCommandEvent& event);
	void OnLanguageButtonClicked(wxCommandEvent& event);


	//Data Variables
	std::vector<wxButton*> sidePanelButtons;
	std::vector<wxBitmapButton*> languageButtons;
	wxArrayString languageList;
	std::unique_ptr<MySQLConnectionManager>m_MySQLConnectionManager;
	std::vector<int> addedTagsList;
	ProgrammingLanguage lang;
	ProgrammingLanguage currentLangEnumVal;


	//Panels
		//HomeVault View
	CVGradientPanel* topStripPanel;
	wxPanel* sidePanel;
	CVGradientPanel* vaultViewPanel;
	wxPanel* secondaryPanel;

		//AddSnippet View
	CVGradientPanel* snippetFormPanel;
		
		//InsideLanguagePanel
	CVGradientPanel* snippetDisplayPanel;

	


	//Sizers
		//HomeVaultSizers
	wxBoxSizer* tier1Sizer_H;
	wxBoxSizer* primaryVaultSizer_V;
	wxBoxSizer* secondaryVaultSizer_V;
	wxBoxSizer* sidePanelSizer_V;
	wxBoxSizer* addSnippetBtnSizer_H;
	wxBoxSizer* groupsBtnSizer_H;
	wxBoxSizer* favoritesBtnSizer_H;
	wxBoxSizer* profileBtnSizer_H;
	wxBoxSizer* sidePanelspacerSizer_H;
	wxBoxSizer* tagsSizer_V;
	wxBoxSizer* tagsBtnSizer_H;
	wxBoxSizer* scrollViewsizer_V;
	wxWrapSizer* languageCompWrapper;

		//SnippetForm Sizers
	wxBoxSizer* snippetFormPanelSizer_V;
	wxBoxSizer* snippetNameSizer_H;
	wxBoxSizer* codeBlockSizer_H;
	wxBoxSizer* snippetDescSizer_H;
	wxBoxSizer* tagsandLanguageSizer_H;
	wxBoxSizer* tagsAndLanguageLabelsSizer_H;

		//SnippetGroup Sizers
	wxBoxSizer* snippetDisplaySizer_V;



	//Scrolview
	wxScrolledWindow* tagsWindow;

	//Controls
		//SidePanel Controls


	wxPanel* panel;
	wxButton* closeSideBarBtn;
	wxButton* addSinppetBtn;
	wxButton* groupsBtn;
	wxButton* favoritesBtn;
	wxButton* profileBtn;
	wxButton* logoutBtn;
	wxTextCtrl* codeSearchBar;



};

