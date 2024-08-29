#include "MainFrame.h"
#include <iostream>
#include <string>
#include <wx/wx.h>
#include <wx/bitmap.h>
#include "CVGradientPanel.h"
#include "CVCustomControls.h"
#include"MySQLConnectionManager.h"
#include "CodeVaultDataStructs.h"


MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr,wxID_ANY,title) {

	CreateControls();


}

void MainFrame::SetupSizer() {

	wxFont healineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	//Creating Panels

	topStripPanel = new CVGradientPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 50), vaultViewGradientStart, vaultViewGradientEnd,wxEAST,false,wxColor(70, 67, 91),1);
	topStripPanel->SetBackgroundColour(wxColor(200,100,100));

	sidePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 500));
	sidePanel->SetBackgroundColour(sidePanelColor);
	sidePanel->SetFont(mainFont);
	sidePanel->SetMaxSize(wxSize(200,-1));


	vaultViewPanel = new CVGradientPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100), vaultViewGradientStart, vaultViewGradientEnd, wxEAST);
	vaultViewPanel->SetBackgroundColour(vaultViewColor);

	snippetFormPanel = new CVGradientPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100), vaultViewGradientStart, vaultViewGradientEnd, wxEAST);


	snippetDisplayPanel = new CVGradientPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100), vaultViewGradientStart, vaultViewGradientEnd, wxEAST);

	//Creating Sizers
		//Primary Layout Sizers
	tier1Sizer_H = new wxBoxSizer(wxHORIZONTAL);
	primaryVaultSizer_V = new wxBoxSizer(wxVERTICAL);
	sidePanelSizer_V = new wxBoxSizer(wxVERTICAL);
	secondaryVaultSizer_V = new wxBoxSizer(wxVERTICAL);
		//SidePanel Sizers
	addSnippetBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);
	groupsBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);
	favoritesBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);
	profileBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);
	tagsSizer_V = new wxBoxSizer(wxVERTICAL);
	tagsBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);
	scrollViewsizer_V =  new wxBoxSizer(wxVERTICAL);

		//vaultViewSizers
	languageCompWrapper = new wxWrapSizer();

		//SnippetForm Sizers
	snippetFormPanelSizer_V = new wxBoxSizer(wxVERTICAL);
	snippetNameSizer_H = new wxBoxSizer(wxHORIZONTAL);
	codeBlockSizer_H = new wxBoxSizer(wxHORIZONTAL);
	snippetDescSizer_H = new wxBoxSizer(wxHORIZONTAL);
	tagsandLanguageSizer_H = new wxBoxSizer(wxHORIZONTAL);
	tagsAndLanguageLabelsSizer_H = new wxBoxSizer(wxHORIZONTAL);

		//Inside Language Sizers
	snippetDisplaySizer_V = new wxBoxSizer(wxVERTICAL);


	//Sizer Configurations

		//Primary Sizer Config
	tier1Sizer_H->Add(sidePanel, 1,wxEXPAND);
	tier1Sizer_H->Add(primaryVaultSizer_V, 4, wxEXPAND);

	primaryVaultSizer_V->Add(topStripPanel, 1, wxEXPAND);
	primaryVaultSizer_V->Add(vaultViewPanel, 9, wxEXPAND);
	primaryVaultSizer_V->Add(snippetFormPanel, 9, wxEXPAND);
	primaryVaultSizer_V->Add(snippetDisplayPanel, 9, wxEXPAND);
	snippetFormPanel->Hide();
	snippetDisplayPanel->Hide();

	vaultViewPanel->SetSizerAndFit(secondaryVaultSizer_V);

		//Sidepanel Sizer Config
	sidePanelSizer_V->Add(addSnippetBtnSizer_H, 0, wxEXPAND | wxTOP, 80);
	sidePanelSizer_V->Add(groupsBtnSizer_H, 0, wxEXPAND);
	sidePanelSizer_V->Add(favoritesBtnSizer_H, 0, wxEXPAND);
	sidePanelSizer_V->Add(tagsSizer_V, 0, wxEXPAND);
	sidePanelSizer_V->AddStretchSpacer(1);
	sidePanelSizer_V->Add(profileBtnSizer_H, 0, wxEXPAND);
	sidePanel->SetSizerAndFit(sidePanelSizer_V);
	tagsSizer_V->Add(tagsBtnSizer_H, 0, wxEXPAND);

		//SnippetForm Sizer Config
	snippetFormPanelSizer_V->Add(snippetNameSizer_H,0,wxEXPAND |wxBOTTOM , 20);
	snippetFormPanelSizer_V->Add(codeBlockSizer_H, 0, wxEXPAND | wxBOTTOM, 20);
	snippetFormPanelSizer_V->Add(snippetDescSizer_H, 0, wxEXPAND | wxBOTTOM, 20);
	snippetFormPanelSizer_V->Add(tagsAndLanguageLabelsSizer_H, 0, wxEXPAND | wxBOTTOM, 10);
	snippetFormPanelSizer_V->Add(tagsandLanguageSizer_H, 0, wxEXPAND | wxBOTTOM, 10);

	//

	snippetFormPanel->SetSizerAndFit(snippetFormPanelSizer_V);

	snippetDisplayPanel->SetSizerAndFit(snippetDisplaySizer_V);
	

	this->SetSizerAndFit(tier1Sizer_H);

}

void MainFrame::CreateControls()
{

	SetupSidePanelUI();
	SetVaultViewUI();
	SetSnippetFormUI();



}

void MainFrame::SetupSidePanelUI()
{
	wxImage::AddHandler(new wxPNGHandler());


	addSnippetBtn = new wxButton(sidePanel, wxID_ANY, "           AddSnippet", wxDefaultPosition, wxSize(-1, 40), wxBORDER_NONE |wxBU_LEFT );
	groupsBtn = new wxButton(sidePanel, wxID_ANY, "           Groups", wxDefaultPosition, wxSize(-1, 40), wxBORDER_NONE | wxBU_LEFT);
	favouritesBtn = new wxButton(sidePanel, wxID_ANY, "           Favourites", wxDefaultPosition, wxSize(-1, 40), wxBORDER_NONE | wxBU_LEFT);
	profileBtn = new wxButton(sidePanel, wxID_ANY, "                 Profile", wxDefaultPosition, wxSize(70,70), wxBORDER_NONE | wxBU_LEFT |wxBU_NOTEXT  );
	tagsBtn = new wxButton(sidePanel, wxID_ANY, "           Tags", wxDefaultPosition, wxSize(-1, 40), wxBORDER_NONE | wxBU_LEFT);



	



	wxBitmap addSnippetIconBitmap(wxT("assets/icons/addsnippeticon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* addSnippetIcon = new wxStaticBitmap(addSnippetBtn, wxID_ANY, addSnippetIconBitmap, wxDefaultPosition, wxSize(40, 40));

	
	wxBitmap groupsIconBitmap(wxT("assets/icons/groupsicon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* groupsBtnIcon = new wxStaticBitmap(groupsBtn, wxID_ANY, groupsIconBitmap, wxDefaultPosition, wxSize(40, 40));

	
	wxBitmap favouritesIconBitmap(wxT("assets/icons/favouritesicon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* favouritesBtnIcon = new wxStaticBitmap(favouritesBtn, wxID_ANY, favouritesIconBitmap, wxDefaultPosition, wxSize(40, 40));


	wxBitmap profileIconBitmap(wxT("assets/icons/profileicon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* profileIcon = new wxStaticBitmap(profileBtn, wxID_ANY, profileIconBitmap, wxDefaultPosition, wxSize(70,70));


	wxBitmap tagsIconBitmap(wxT("assets/icons/tagsicon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* tagsIcon = new wxStaticBitmap(tagsBtn, wxID_ANY, tagsIconBitmap, wxDefaultPosition, wxSize(40, 40));





	wxScrolledWindow* tagsScrollWindow = new wxScrolledWindow(sidePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
	tagsScrollWindow->SetMinSize(wxSize(200, 200));
	tagsScrollWindow->SetMaxSize(wxSize(250, 300));
	tagsScrollWindow->SetVirtualSize(wxSize(250, 100));
	tagsScrollWindow->SetScrollRate(10, 10); // Set the scroll rate (pixels per scroll step)
	//tagsScrollWindow->SetVirtualSize(250, 1000); // Set the virtual size (total content size)
	tagsScrollWindow->SetBackgroundColour(sidePanelColor);
	tagsScrollWindow->ShowScrollbars(wxSHOW_SB_DEFAULT, wxSHOW_SB_NEVER);




	wxStaticText* Tag1 = new wxStaticText(tagsScrollWindow, wxID_ANY, "#Tag1",wxDefaultPosition,wxDefaultSize,  wxALIGN_CENTER_HORIZONTAL);
	wxStaticText* Tag2 = new wxStaticText(tagsScrollWindow, wxID_ANY, "#Tag2", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	wxStaticText* Tag3 = new wxStaticText(tagsScrollWindow, wxID_ANY, "#Tag3", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	
	Tag1->SetForegroundColour(wxColor(255, 255, 255));
	Tag1->SetFont(sidePanelButtonfont);
	Tag2->SetForegroundColour(wxColor(255, 255, 255));
	Tag2->SetFont(sidePanelButtonfont);
	Tag3->SetForegroundColour(wxColor(255, 255, 255));
	Tag3->SetFont(sidePanelButtonfont);


	scrollViewsizer_V->Add(Tag1, 0,  wxLEFT ,45);
	scrollViewsizer_V->Add(Tag2, 0, wxLEFT, 45);
	scrollViewsizer_V->Add(Tag3, 0, wxLEFT, 45);

	//scrollViewsizer_V->Add(new wxStaticText(tagsScrollWindow, wxID_ANY, "Tag2"), 0, wxALIGN_CENTER_HORIZONTAL);




	
	tagsScrollWindow->SetSizerAndFit(scrollViewsizer_V);
	//tagsScrollWindow->SetVirtualSize(scrollViewsizer_V->GetSize());
	scrollViewsizer_V->FitInside(tagsScrollWindow);
	//scrollViewsizer_V->SetSizeHints(tagsScrollWindow);
	
	tagsSizer_V->Add(tagsScrollWindow, 1, wxEXPAND);
	



	sidePanelButtons.push_back(addSnippetBtn);
	sidePanelButtons.push_back(groupsBtn);
	sidePanelButtons.push_back(favouritesBtn);
	sidePanelButtons.push_back(profileBtn);
	sidePanelButtons.push_back(tagsBtn);


	SetSidPanelUIProfile(sidePanelButtons, sidePanelColor, sidePanelButtonfont);



	addSnippetBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
		
		//vaultViewPanel->Disable();
		std::cout << "Add Snippet Button Clicked" << std::endl;
		vaultViewPanel->Hide();
		snippetFormPanel->Show();
		Layout();

		});

	groupsBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
		
		//vaultViewPanel->Disable();
		vaultViewPanel->Show();
		snippetFormPanel->Hide();
		Layout();

		});




	BindSidePanelButtonEvents(sidePanelButtons);
	//iconCtrl->Bind(wxEVT_LEAVE_WINDOW, [this, iconCtrl](wxMouseEvent& event) {
	   // iconCtrl->SetBackgroundColour(wxColor(43, 52, 69));  // Original color
	   // iconCtrl->Refresh();
	   // event.Skip();
	   // });

	//iconCtrl->Bind(wxEVT_ENTER_WINDOW, [this, iconCtrl](wxMouseEvent& event) {
	   // iconCtrl->SetBackgroundColour(wxColor(36, 34, 46));  // Slightly darker on hover
	   // iconCtrl->Refresh();
	   // event.Skip();
	   // });




	//addSnippetBtnSizer_H->Add(addSnippetIcon, 1);
	addSnippetBtnSizer_H->Add(addSnippetBtn, 8);

	//groupsBtnSizer_H->Add(groupsBtnIcon, 1);
	groupsBtnSizer_H->Add(groupsBtn, 8);

	//favoritesBtnSizer_H->Add(favouritesBtnIcon, 1);
	favoritesBtnSizer_H->Add(favouritesBtn, 8);

	//profileBtnSizer_H->Add(profileIcon, 1);
	profileBtnSizer_H->Add(profileBtn, 5,wxALIGN_CENTER_VERTICAL );


	//tagsBtnSizer_H->Add(tagsIcon, 1);
	tagsBtnSizer_H->Add(tagsBtn, 8);
	
	




	

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


		button->SetForegroundColour(wxColour(255, 255, 255));
	}
}

void MainFrame::BindVaultLanguageButtonEvents(const std::vector<wxBitmapButton*>& languageButtons)
{
	for (auto& button : languageButtons) {

		button->Bind(wxEVT_ENTER_WINDOW, [this, button](wxMouseEvent& event) mutable {
			button->SetBackgroundColour(vaultButtonsOnHoverColor);
			button->Refresh();
			event.Skip();
			});

		button->Bind(wxEVT_LEAVE_WINDOW, [this, button](wxMouseEvent& event)mutable {
			button->SetBackgroundColour(vaultButtonsColor);
			button->Refresh();
			event.Skip();
			});

	//	button->Bind(wxEVT_BUTTON, &MainFrame::OnLanguageButtonClicked, this);


	}
}

void MainFrame::SetSidPanelUIProfile(const std::vector<wxButton*>& buttons, wxColor backgroundColor, wxFont font)
{
	for (wxButton* button : buttons) {
		button->SetBackgroundColour(backgroundColor);
		button->SetFont(font);
	}
}

void MainFrame::SetVaultViewUI()
{

	codeSearchBar = new CVGradientTxtCtrl(vaultViewPanel, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 30), vaultViewGradientStart, vaultViewGradientEnd, wxEAST, wxTE_PROCESS_ENTER | wxBG_STYLE_PAINT);
	codeSearchBar->SetBackgroundColour(vaultViewColor);
	codeSearchBar->SetForegroundColour(*wxWHITE);





	secondaryVaultSizer_V->Add(codeSearchBar, 0, wxEXPAND | wxLEFT | wxTOP | wxRIGHT, 20);
	secondaryVaultSizer_V->Add(languageCompWrapper, 1, wxEXPAND | wxTOP, 20);



	primaryHorizontalSizer->Add(sideMenuVerticalSizer, wxSizerFlags().Proportion(0).Expand());
	primaryHorizontalSizer->Add(codeViewVerticalSizer, wxSizerFlags().Proportion(1).Expand());
	codeSearchBarSizer->Add(codeSearchBar, wxSizerFlags().Proportion(1).Expand());


	////defining size for Language Vaults
	wxSize buttonSize(260, 300);

	//
	wxImage pythonImage(wxT("assets/images/pythonimage.png"), wxBITMAP_TYPE_PNG);
	wxImage cImage(wxT("assets/images/cimage.png"), wxBITMAP_TYPE_PNG);
	wxImage csharpImage(wxT("assets/images/csharpimage.png"), wxBITMAP_TYPE_PNG);
	wxImage cplusplusImage(wxT("assets/images/cplusplusimage.png"), wxBITMAP_TYPE_PNG);
	//hover


	//scaling images to Button Sizes
	wxImage scaledPythoneImage = pythonImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
	wxImage scaledCImage = cImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
	wxImage scaledCSharpImage = csharpImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
	wxImage scaledCPlusPlusImage = cplusplusImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);



	////Reconverting to Bitmaps
	wxBitmap scaledPythonBitmap(scaledPythoneImage);
	wxBitmap scaledCBitmap(scaledCImage);
	wxBitmap scaledCSharpBitmap(scaledCSharpImage);
	wxBitmap scaledCPlusPlusBitmap(scaledCPlusPlusImage);





	pythonVaultBtn = new wxBitmapButton(vaultViewPanel, static_cast<int>(ProgrammingLanguage::Python), scaledPythonBitmap, wxPoint(50, 50), buttonSize);
	pythonVaultBtn->SetBackgroundColour(vaultButtonsColor);




	cVaultBtn = new wxBitmapButton(vaultViewPanel, static_cast<int>(ProgrammingLanguage::C), scaledCBitmap, wxPoint(50, 50), buttonSize);
	cVaultBtn->SetBackgroundColour(vaultButtonsColor);

	currentLangEnumVal = getProgrammingLanguageFromIndex(1);
	std::cout << "Language for enum id 1 is : " << programmingLanguageToString(currentLangEnumVal) << std::endl;

	csharpVaultBtn = new wxBitmapButton(vaultViewPanel, wxID_ANY, scaledCSharpBitmap, wxPoint(50, 50), buttonSize);
	csharpVaultBtn->SetBackgroundColour(vaultButtonsColor);

	cplusplusVaultBtn = new wxBitmapButton(vaultViewPanel, wxID_ANY, scaledCPlusPlusBitmap, wxPoint(50, 50), buttonSize);
	cplusplusVaultBtn->SetBackgroundColour(vaultButtonsColor);


	languageButtons.push_back(pythonVaultBtn);
	languageButtons.push_back(cVaultBtn);
	languageButtons.push_back(csharpVaultBtn);
	languageButtons.push_back(cplusplusVaultBtn);

	BindVaultLanguageButtonEvents(languageButtons);

	//cplusplusVaultBtn->Bind(wxEVT_ENTER_WINDOW, [=](wxMouseEvent&) { cplusplusVaultBtn->SetBitmap(scaledCPlusPlusHoverBitmap); });
	//cplusplusVaultBtn->Bind(wxEVT_LEAVE_WINDOW, [=](wxMouseEvent&) { cplusplusVaultBtn->SetBitmap(scaledCPlusPlusBitmap); });


	languageCompWrapper->Add(pythonVaultBtn, 0, wxALL, 10);
	languageCompWrapper->Add(cVaultBtn, 0, wxALL, 10);
	languageCompWrapper->Add(csharpVaultBtn, 0, wxALL, 10);
	languageCompWrapper->Add(cplusplusVaultBtn, 0, wxALL, 10);

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


//void MainFrame::OnLanguageButtonClicked(wxCommandEvent& event, int wxID)
//{
//}




