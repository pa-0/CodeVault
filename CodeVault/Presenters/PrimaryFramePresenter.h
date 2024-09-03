#pragma once
#include "BasePresenter.h"


//Forward Declarations
class MainFrame;
class wxArrayString;
class LanguageRepository;
class TagsRepository;

class PrimaryFramePresenter :
    public BasePresenter
{
    public:
	PrimaryFramePresenter();
	~PrimaryFramePresenter()override = default;


	void SetControlledFrame(wxFrame* Frame) override;
	void TestPrint();

	//Repository Functions
		//language functions
	wxArrayString RetrieveAllLanguages();

		//Tags Functions
	void SetTagContainer();


private:
	MainFrame* m_mainFrame;
	LanguageRepository* m_languageRepository;
	TagsRepository* m_TagsRepository;


};

