#pragma once
#include <wx/wx.h>
#include <vector>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

struct ControlSet {
	wxButton* button;
	wxStaticBitmap* icon;
	wxStaticText* buttonText;
	wxStaticText* btnSpacer;

	// Constructor
	ControlSet(wxButton* btn, wxStaticBitmap* bmp, wxStaticText* btnText, wxStaticText* btnSpacer)
		: button(btn), icon(bmp), buttonText(btnText), btnSpacer(btnSpacer) {}
};

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);


private:
	void SetupSizer();
	void CreateControls();
	void SetupSidePanelUI();
	void BindButtonEvents(const std::vector<ControlSet>& controls,wxColor mainColor,wxColor hoverColor);
	void SetSidPanelUIProfile(const std::vector<wxButton*>& buttons,wxColor backgroundColor, wxFont font);

	//Panels
	wxPanel* topStripPanel;
	wxPanel* sidePanel;
	wxPanel* vaultViewPanel;
	wxPanel* secondaryPanel;


	//Sizers
	wxBoxSizer* tier1Sizer_H;
	wxBoxSizer* tier2Sizer_V;
	wxBoxSizer* sidePanelSizer_V;
	wxBoxSizer* addSnippetBtnSizer_H;
	wxBoxSizer* groupsBtnSizer_H;
	wxBoxSizer* favoritesBtnSizer_H;
	wxBoxSizer* profileBtnSizer_H;
	wxBoxSizer* sidePanelspacerSizer_H;

	//Controls
	std::vector<ControlSet> buttonControlSets;
	wxButton* closeSideBarBtn;
	wxButton* addSnippetBtn;
	
	wxButton* groupsBtn;
	wxButton* favouritesBtn;
	wxButton* profileBtn;
	wxButton* logoutBtn;
	wxTextCtrl* codeSearchBar;
	wxBitmap* pythonImage;
	wxBitmapButton* pythonVaultBtn;
	wxBitmapButton*	cVaultBtn;
	wxBitmapButton* csharpVaultBtn;
	wxBitmapButton* cplusplusVaultBtn;

	
	//Colors
	wxColor sidePanelColor = wxColor(43, 52, 69);
	wxColor sidePanelButtonHoverColor = wxColor(36, 34, 46);

	wxColor vaultViewColor = wxColor(47, 45, 61);

	//fonts
	wxFont sidePanelButtonfont = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
};

