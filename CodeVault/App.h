// App.h
#ifndef APP_H
#define APP_H

#include <wx/wx.h>
#include "LoginFrame.h"
#include "MainFrame.h"
#include "SignUpFrame.h"

class App : public wxApp
{
public:
    virtual bool OnInit();
    static LoginFrame* GetLoginFrame() { return m_loginFrame; }
    static MainFrame* GetMainFrame() { return m_mainFrame; }
    static SignUpFrame* GetSignUpFrame() { return m_signUpFrame; }

private:
    static LoginFrame* m_loginFrame;
    static MainFrame* m_mainFrame;
    static SignUpFrame* m_signUpFrame;
};

#endif // APP_H
