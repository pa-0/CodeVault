// App.h
#include <wx/wx.h>
#include "LoginFrame.h"
#include "MainFrame.h"
#include "SignUpFrame.h"


class MySQLConnectionManager;
class BasePresenter;

class App : public wxApp
{
public:;
	bool OnInit();
	void RedirectstdoutToConsole(bool bShouldSetConsoleRedirection);

	void SetMainFrameVisibility(bool val);
	void SetLoginFrameVisibility(bool val);
	void SetSignupFrameVisibility(bool val);
	void InitDB();
	
private:
	//Frames
    LoginFrame* m_loginFrame;
    MainFrame* m_mainFrame;
    SignUpFrame* m_signUpFrame;

	//Presenters
	std::unique_ptr<BasePresenter> MainFramePresenter;

	MySQLConnectionManager*	dbManager;
	const std::string m_schema = "codevaultdb";
};

