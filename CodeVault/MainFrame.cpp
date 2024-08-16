#include "MainFrame.h"
#include <wx/wx.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

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

	// TODO: Cleanup and use proper wxWidgets controls
    codeViewVerticalSizer->Add(codeSnippetInput, wxSizerFlags().Proportion(1).Expand().Border(wxALL, 10));
    codeViewVerticalSizer->Add(languageLabel, wxSizerFlags().Expand().Border(wxALL, 10));
    codeViewVerticalSizer->Add(identifyLanguageBtn, wxSizerFlags().Center().Border(wxALL, 10));

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
	
	// TODO: Cleanup and use proper wxWidgets controls
    codeSnippetInput = new wxTextCtrl(panel, wxID_ANY, "Enter code snippet here...", wxDefaultPosition, wxSize(400, 200), wxTE_MULTILINE);
    languageLabel = new wxStaticText(panel, wxID_ANY, "Likely Language: Unknown", wxDefaultPosition, wxDefaultSize);
    identifyLanguageBtn = new wxButton(panel, wxID_ANY, "Identify Language");

    identifyLanguageBtn->Bind(wxEVT_BUTTON, &MainFrame::OnIdentifyLanguage, this);
}

/**
 * Check if the snippet contains any of the language's patterns
 *
 * @param code code snippet to check
 * @param patterns list of patterns to match
 * @return number of matches found
 */
int matchPatterns(const std::string& code, const std::vector<std::string>& patterns) {
    int matches = 0;
    for (const auto& pattern : patterns) {
        if (code.find(pattern) != std::string::npos) {
            matches++;
        }
    }
    return matches;
}

/**
 * Identify the likely programming language of given code snippet
 *
 * The likelyhood of a language is determined by the number of patterns
 * found in the code snippet.
 * 
 * @param code code snippet to analyze
 * @return name of the most likely programming language
 */
std::string identifyLanguage(const std::string& code) {
    // TODO: store patterns in an external file or database
    std::map<std::string, std::vector<std::string>> languagePatterns;
    languagePatterns["Python"] = {"def ", "import ", "self", ":", "#"};
    languagePatterns["C++"] = {"#include", "int ", "::", "->", "#define"};
    languagePatterns["JavaScript"] = {"function", "const", "let", "var", "=>"};

    std::string likelyLanguage = "Unknown";
    int maxMatches = 0;

    // Compare code snippet with each language's patterns
    for (const auto& language : languagePatterns) {
        int matches = matchPatterns(code, language.second);
        if (matches > maxMatches) {
            maxMatches = matches;
            likelyLanguage = language.first;
        }
    }
    return likelyLanguage;
}

void MainFrame::OnIdentifyLanguage(wxCommandEvent& event) {
    std::string codeSnippet = std::string(codeSnippetInput->GetValue().mb_str());
    std::string likelyLanguage = identifyLanguage(codeSnippet);
    languageLabel->SetLabel("Likely Language: " + likelyLanguage);
}
