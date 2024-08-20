#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/wrapsizer.h>
#include <wx/bitmap.h>



MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {


	SetupSizer();
	CreateControls();


}

void MainFrame::SetupSizer() {

	wxFont healineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));


	topStripPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 50));
	topStripPanel->SetBackgroundColour(vaultViewColor);

	sidePanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	sidePanel->SetBackgroundColour(sidePanelColor);
	sidePanel->SetFont(mainFont);


	addSnippetBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);
	groupsBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);
	favoritesBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);
	profileBtnSizer_H = new wxBoxSizer(wxHORIZONTAL);



	vaultViewPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	vaultViewPanel->SetBackgroundColour(vaultViewColor);

	tier1Sizer_H = new wxBoxSizer(wxHORIZONTAL);
	tier2Sizer_V = new wxBoxSizer(wxVERTICAL);
	sidePanelSizer_V = new wxBoxSizer(wxVERTICAL);

	tier1Sizer_H->Add(sidePanel, 1, wxEXPAND);
	tier1Sizer_H->Add(tier2Sizer_V, 4, wxEXPAND);

	tier2Sizer_V->Add(topStripPanel, 1, wxEXPAND);
	tier2Sizer_V->Add(vaultViewPanel, 9, wxEXPAND);

	sidePanelSizer_V->Add(addSnippetBtnSizer_H, 0, wxEXPAND | wxTOP, 80);
	sidePanelSizer_V->Add(groupsBtnSizer_H, 0, wxEXPAND);
	sidePanelSizer_V->Add(favoritesBtnSizer_H, 0, wxEXPAND);
	sidePanelSizer_V->AddStretchSpacer(1);
	sidePanelSizer_V->Add(profileBtnSizer_H, 0, wxEXPAND);
	sidePanel->SetSizerAndFit(sidePanelSizer_V);

	this->SetSizerAndFit(tier1Sizer_H);

}

void MainFrame::CreateControls()
{

	SetupSidePanelUI();


	//wxTextCtrl* codeSearchBarcus = new wxTextCtrl(vaultViewPanel, wxID_ANY,"", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);


	//closeSideBarBtn = new wxButton(panel, wxID_ANY, "CloseSideBar");
	////defining size for Language Vaults
	//wxSize buttonSize(200, 240);

	//
	//wxImage pythonImage(wxT("assets/images/pythonimage.png"), wxBITMAP_TYPE_PNG);
	//wxImage cImage(wxT("assets/images/cimage.png"), wxBITMAP_TYPE_PNG);
	//wxImage csharpImage(wxT("assets/images/csharpimage.png"), wxBITMAP_TYPE_PNG);
	//wxImage cplusplusImage(wxT("assets/images/cplusplusimage.png"), wxBITMAP_TYPE_PNG);
	////hover
	//wxImage cplusplusHoverImage(wxT("assets/images/cplusplushoverimage.png"), wxBITMAP_TYPE_PNG);

	////scaling images to Button Sizes
	//wxImage scaledPythoneImage = pythonImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
	//wxImage scaledCImage = cImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
	//wxImage scaledCSharpImage = csharpImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
	//wxImage scaledCPlusPlusImage = cplusplusImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);
	//wxImage scaledCPlusPlusHoverImage = cplusplusHoverImage.Scale(buttonSize.GetWidth(), buttonSize.GetHeight(), wxIMAGE_QUALITY_HIGH);



	////Reconverting to Bitmaps
	//wxBitmap scaledPythonBitmap(scaledPythoneImage);
	//wxBitmap scaledCBitmap(scaledCImage);
	//wxBitmap scaledCSharpBitmap(scaledCSharpImage);
	//wxBitmap scaledCPlusPlusBitmap(scaledCPlusPlusImage);



	//wxBitmap scaledCPlusPlusHoverBitmap(scaledCPlusPlusHoverImage);

	//pythonVaultBtn = new wxBitmapButton(panel, wxID_ANY, scaledPythonBitmap, wxPoint(50, 50),buttonSize);
	//cVaultBtn = new wxBitmapButton(panel, wxID_ANY, scaledCBitmap, wxPoint(50, 50), buttonSize);
	//csharpVaultBtn = new wxBitmapButton(panel, wxID_ANY, scaledCSharpBitmap, wxPoint(50, 50), buttonSize);
	//cplusplusVaultBtn = new wxBitmapButton(panel, wxID_ANY, scaledCPlusPlusBitmap, wxPoint(50, 50), buttonSize);

	//cplusplusVaultBtn->Bind(wxEVT_ENTER_WINDOW, [=](wxMouseEvent&) { cplusplusVaultBtn->SetBitmap(scaledCPlusPlusHoverBitmap); });
	//cplusplusVaultBtn->Bind(wxEVT_LEAVE_WINDOW, [=](wxMouseEvent&) { cplusplusVaultBtn->SetBitmap(scaledCPlusPlusBitmap); });



}

void MainFrame::SetupSidePanelUI()
{
	wxImage::AddHandler(new wxPNGHandler());


	addSnippetBtn = new wxButton(sidePanel, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 40), wxBORDER_NONE);
	groupsBtn = new wxButton(sidePanel, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 40), wxBORDER_NONE);
	favouritesBtn = new wxButton(sidePanel, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 40), wxBORDER_NONE);
	profileBtn = new wxButton(sidePanel, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 40), wxBORDER_NONE);


	wxStaticText* addSnippetBtnLabel = new wxStaticText(addSnippetBtn, wxID_ANY, "  AddSnippet", wxPoint(-1, 10), wxDefaultSize, wxALIGN_LEFT);
	addSnippetBtnLabel->SetForegroundColour(wxColor(255, 255, 255));
	addSnippetBtnLabel->SetFont(sidePanelButtonfont);

	wxStaticText* addSnippetLabelFiller = new wxStaticText(addSnippetBtn, wxID_ANY, " ", wxPoint(-1, 10), wxDefaultSize);
	addSnippetBtnLabel->SetForegroundColour(wxColor(255, 255, 255));
	addSnippetBtnLabel->SetFont(sidePanelButtonfont);

	wxStaticText* groupsBtnLabel = new wxStaticText(groupsBtn, wxID_ANY, "  Groups", wxPoint(-1, 10), wxDefaultSize, wxALIGN_LEFT);
	groupsBtnLabel->SetForegroundColour(wxColor(255, 255, 255));
	groupsBtnLabel->SetFont(sidePanelButtonfont);

	wxStaticText* groupsBtnLabelFiller = new wxStaticText(groupsBtn, wxID_ANY, " ", wxPoint(-1, 10), wxDefaultSize);
	groupsBtnLabelFiller->SetForegroundColour(wxColor(255, 255, 255));
	groupsBtnLabelFiller->SetFont(sidePanelButtonfont);

	wxStaticText* favouritesBtnLabel = new wxStaticText(favouritesBtn, wxID_ANY, "  Favourites", wxPoint(-1, 10), wxDefaultSize, wxALIGN_LEFT);
	favouritesBtnLabel->SetForegroundColour(wxColor(255, 255, 255));
	favouritesBtnLabel->SetFont(sidePanelButtonfont);

	wxStaticText* favouritesBtnLabelFiller = new wxStaticText(favouritesBtn, wxID_ANY, " ", wxPoint(-1, 10), wxDefaultSize);
	favouritesBtnLabelFiller->SetForegroundColour(wxColor(255, 255, 255));
	favouritesBtnLabelFiller->SetFont(sidePanelButtonfont);

	wxStaticText* profileBtnLabel = new wxStaticText(profileBtn, wxID_ANY, "  Profile", wxPoint(-1, 10), wxDefaultSize, wxALIGN_LEFT);
	profileBtnLabel->SetForegroundColour(wxColor(255, 255, 255));
	profileBtnLabel->SetFont(sidePanelButtonfont);

	wxStaticText* profileBtnLabelFiller = new wxStaticText(profileBtn, wxID_ANY, " ", wxPoint(-1, 10), wxDefaultSize);
	profileBtnLabelFiller->SetForegroundColour(wxColor(255, 255, 255));
	profileBtnLabelFiller->SetFont(sidePanelButtonfont);





	wxBitmap addSnippetIconBitmap(wxT("assets/icons/addsnippeticon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* addSnippetIcon = new wxStaticBitmap(sidePanel, wxID_ANY, addSnippetIconBitmap, wxDefaultPosition, wxSize(40, 40));
	
	wxBitmap groupsIconBitmap(wxT("assets/icons/groupsicon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* groupsBtnIcon = new wxStaticBitmap(sidePanel, wxID_ANY, groupsIconBitmap, wxDefaultPosition, wxSize(30, 30));
	
	wxBitmap favouritesIconBitmap(wxT("assets/icons/favouritesicon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* favouritesBtnIcon = new wxStaticBitmap(sidePanel, wxID_ANY, favouritesIconBitmap, wxDefaultPosition, wxSize(30, 30));

	wxBitmap profileIconBitmap(wxT("assets/icons/profileicon.png"), wxBITMAP_TYPE_PNG);
	wxStaticBitmap* profileIcon = new wxStaticBitmap(sidePanel, wxID_ANY, profileIconBitmap, wxDefaultPosition, wxSize(70,70));
	
	buttonControlSets.push_back(ControlSet(addSnippetBtn, addSnippetIcon, addSnippetBtnLabel, addSnippetLabelFiller));
	buttonControlSets.push_back(ControlSet(groupsBtn, groupsBtnIcon, groupsBtnLabel, groupsBtnLabelFiller));
	buttonControlSets.push_back(ControlSet(favouritesBtn, favouritesBtnIcon, favouritesBtnLabel, favouritesBtnLabelFiller));

	std::vector<wxButton*> sidePanelButtons;

	sidePanelButtons.push_back(addSnippetBtn);
	sidePanelButtons.push_back(groupsBtn);
	sidePanelButtons.push_back(favouritesBtn);
	sidePanelButtons.push_back(profileBtn);



	SetSidPanelUIProfile(sidePanelButtons, sidePanelColor, sidePanelButtonfont);



	addSnippetBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
		wxMessageBox("Button Pressed!", "Info", wxOK | wxICON_INFORMATION);
		});




	BindButtonEvents(buttonControlSets, sidePanelColor, sidePanelButtonHoverColor);
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




	addSnippetBtnSizer_H->Add(addSnippetIcon, 1);
	addSnippetBtnSizer_H->Add(addSnippetBtn, 8);

	groupsBtnSizer_H->Add(groupsBtnIcon, 1,  wxLEFT | wxRIGHT  , 5);
	groupsBtnSizer_H->Add(groupsBtn, 8);

	favoritesBtnSizer_H->Add(favouritesBtnIcon, 1,wxLEFT | wxRIGHT, 5);
	favoritesBtnSizer_H->Add(favouritesBtn, 8);

	profileBtnSizer_H->Add(profileIcon, 1);
	profileBtnSizer_H->Add(profileBtn, 5,wxALIGN_CENTER_VERTICAL );






	
}

void MainFrame::BindButtonEvents(const std::vector<ControlSet>& controls, wxColor mainColor, wxColor hoverColor)
{
	for (const auto& controlSet : controls) {

		// Capture the controlSet by value so that each lambda has its own copy
		controlSet.button->Bind(wxEVT_LEAVE_WINDOW, [mainColor, controlSet](wxMouseEvent& event) mutable {
			controlSet.button->SetBackgroundColour(mainColor); // Original color
			controlSet.button->Refresh();
			event.Skip();
			});

		controlSet.button->Bind(wxEVT_ENTER_WINDOW, [hoverColor, controlSet](wxMouseEvent& event) mutable {
			controlSet.button->SetBackgroundColour(hoverColor); // Slightly darker on hover
			controlSet.button->Refresh();
			event.Skip();
			});

		controlSet.button->SetForegroundColour(wxColour(255, 255, 255));
	}
}

void MainFrame::SetSidPanelUIProfile(const std::vector<wxButton*>& buttons, wxColor backgroundColor, wxFont font)
{
	for (wxButton* button : buttons) {
		button->SetBackgroundColour(backgroundColor);
		button->SetFont(font);
	}
}


