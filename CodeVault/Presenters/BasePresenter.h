#pragma once

class wxFrame;
class BasePresenter
{
public:
	BasePresenter() {};
	virtual ~BasePresenter() = default;
	virtual void SetControlledFrame(wxFrame* Frame) = 0;

	private:
		wxFrame* m_controlledFrame;
};

