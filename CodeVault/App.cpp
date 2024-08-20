#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	MainFrame* mainFrame = new MainFrame("C++ GUI");
	mainFrame->SetClientSize(1200, 800);
	mainFrame->SetMinSize(wxSize(800,600));
	wxImage::AddHandler(new wxPNGHandler);
	mainFrame->Show();
	return true;
}