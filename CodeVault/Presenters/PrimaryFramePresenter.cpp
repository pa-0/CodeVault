#include "PrimaryFramePresenter.h"
#include <wx/wx.h>
#include <iostream>
#include "../ServiceLayer/LanguageRepository.h"
#include "../ServiceLayer/TagsRepository.h"
#include "../MainFrame.h"

PrimaryFramePresenter::PrimaryFramePresenter() {

	m_languageRepository = new LanguageRepository();
	m_TagsRepository = new TagsRepository();
}

void PrimaryFramePresenter::SetControlledFrame(wxFrame* Frame) {
	m_mainFrame = dynamic_cast<MainFrame*>(Frame);
}


void PrimaryFramePresenter::TestPrint()
{
	std::cout << "PrimaryFramePresenter::TestPrint" << std::endl;
}

wxArrayString  PrimaryFramePresenter::RetrieveAllLanguages() {


	std::vector<LanguageModel> stdlanguages =  m_languageRepository->GetAll();
	wxArrayString wxlanguages;
	for(auto language : stdlanguages) {
		wxlanguages.Add(language.getLanguageName());
	}

	m_mainFrame->SetLanguageChoice(wxlanguages);
	return wxlanguages;


}

void PrimaryFramePresenter::SetTagContainer() {
	std::vector<TagModel> tags = m_TagsRepository->GetAll();

	for (auto tag : tags) {
		std::string tagName = tag.getTagName();
		m_mainFrame->InsertItemToTagsWindow(tagName);
	}
	

}