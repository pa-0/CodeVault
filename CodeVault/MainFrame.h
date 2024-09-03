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
class BasePresenter;
class PrimaryFramePresenter;
class wxListViewComboPopup;

namespace sql {
	class PreparedStatement;
}


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, MySQLConnectionManager*  MySQLManager , std::unique_ptr<BasePresenter>& presenterPtr);


	//UI Functions
	void SetLanguageChoice(wxArrayString Languages);
	void InsertItemToTagsWindow(std::string tag);

private:
	void SetPresenter();
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
	BasePresenter& m_presenter;
	PrimaryFramePresenter& m_PrimaryFramePresenter;

	std::vector<wxButton*> sidePanelButtons;
	std::vector<wxBitmapButton*> languageButtons;
	wxArrayString languageList;
	MySQLConnectionManager* m_MySQLConnectionManager;
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

	wxButton* closeSideBarBtn;
	wxButton* addSnippetBtn;
	
	wxButton* groupsBtn;
	wxButton* favouritesBtn;
	wxButton* profileBtn;
	wxButton* logoutBtn;
	wxButton* tagsBtn;


		//VaultViewControls
	CVGradientTxtCtrl* codeSearchBar;
	wxBitmap* pythonImage;
	wxBitmapButton* pythonVaultBtn;
	wxBitmapButton*	cVaultBtn;
	wxBitmapButton* csharpVaultBtn;
	wxBitmapButton* cplusplusVaultBtn;

		//SnippetFormControls
	
	wxTextCtrl* snippetNameInput;
	wxTextCtrl* codeBlockInput;
	wxTextCtrl* snippetDescInput;
	wxComboCtrl* tagSelectionComboCtrl;
	wxListViewComboPopup* tagSelectpopupCtrl;
	wxChoice* languagesChoice;
	wxButton* addCodeSnipBtn;

	
	//Colors
	wxColor sidePanelColor = wxColor(43, 52, 69);
	wxColor sidePanelButtonHoverColor = wxColor(36, 34, 46);



	wxColor vaultViewGradientStart = wxColor(47, 45, 61);
	wxColor vaultViewGradientEnd = wxColour(56, 53, 72);
	wxColor vaultViewColor = wxColor(47, 45, 61);
	wxColor vaultButtonsColor = wxColor(36, 35, 47);
	wxColor vaultButtonsOnHoverColor = wxColor(38,37,50);
	//fonts
	wxFont sidePanelButtonfont = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);


	//SQL Quries
	std::unique_ptr<sql::PreparedStatement>  insertCodeBlockpstmt = nullptr;
	std::unique_ptr<sql::PreparedStatement>  insertSnippetTagpstmt = nullptr;
	std::unique_ptr<sql::PreparedStatement>  retrieveTagidForTagpstmt = nullptr;
	std::unique_ptr<sql::PreparedStatement>  retrievelanguageidForGivenName = nullptr;
};

