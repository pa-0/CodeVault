#pragma once
#include <wx/wx.h>


class CVGradientPanel : public wxPanel
{
public:
	CVGradientPanel(wxWindow* parent,
		wxWindowID winid = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		const wxColour& startColor = *wxBLACK,
		const wxColour& endColor = *wxWHITE,
		const wxDirection& gradientDirection = wxSOUTH,
		bool bShouldDrawBorder = false,
		const wxColour& borderColor = *wxWHITE,
		int borderThickness = 2,
		long style = wxTAB_TRAVERSAL | wxNO_BORDER,
		const wxString& name = wxASCII_STR(wxPanelNameStr))
		: wxPanel(parent, winid, pos, size, style, name),
		gradStartColor(startColor), gradEndColor(endColor), gradDirection(gradientDirection), m_borderColor(borderColor), m_borderThickness(borderThickness),m_bShouldDrawBorder(bShouldDrawBorder)
	{
		// Bind the paint event to the OnPaint method
		Bind(wxEVT_PAINT, &CVGradientPanel::OnPaint, this);
	}

private:
	wxColour gradStartColor;
	wxColour gradEndColor;
	wxDirection gradDirection;
	bool m_bShouldDrawBorder;
	wxColour m_borderColor;
	int m_borderThickness;
	void OnPaint(wxPaintEvent& event)
	{
		wxPaintDC dc(this);

		// Get the size of the panel
		wxSize size = GetSize();

		// Define the start and end colors for the gradient
		//wxColour gradientstartColour = ; // Red
		//wxColour endColour(56, 53, 72);   // Blue

		// Draw the gradient from top to bottom
		dc.GradientFillLinear(wxRect(0, 0, size.GetWidth(), size.GetHeight()),
			gradStartColor, gradEndColor, gradDirection);

		if (m_bShouldDrawBorder) {
			dc.SetPen(wxPen(m_borderColor, m_borderThickness));

			// Draw the bottom border
			dc.DrawLine(0, size.GetHeight() - m_borderThickness, size.GetWidth(), size.GetHeight() - m_borderThickness);
		}
		

		// Skip the default event handler to prevent flickering
		event.Skip();
	}
};



class CVGradientTxtCtrl : public wxTextCtrl
{
public:
	CVGradientTxtCtrl(wxWindow* parent,
		wxWindowID id,
		const wxString& value = wxEmptyString,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		const wxColour& startColor = *wxBLACK,
		const wxColour& endColor = *wxWHITE,
		const wxDirection& gradientDirection = wxSOUTH,
		long style = 0,
		const wxValidator& validator = wxDefaultValidator,
		const wxString& name = wxASCII_STR(wxTextCtrlNameStr))
		:wxTextCtrl(parent, id, value, pos, size, style, validator, name),
		gradStartColor(startColor), gradEndColor(endColor), gradDirection(gradientDirection)

	{
		// Bind the paint event to the OnPaint method
		Bind(wxEVT_PAINT, &CVGradientTxtCtrl::OnPaint, this);
	}


private:
	wxColour gradStartColor;
	wxColour gradEndColor;
	wxDirection gradDirection;

	void OnPaint(wxPaintEvent& event)
	{
		wxPaintDC dc(this);

		// Get the size of the panel
		wxSize size = GetSize();

		// Define the start and end colors for the gradient
		//wxColour gradientstartColour = ; // Red
		//wxColour endColour(56, 53, 72);   // Blue

		// Draw the gradient from top to bottom
		dc.GradientFillLinear(wxRect(0, 0, size.GetWidth(), size.GetHeight()),
			gradStartColor, gradEndColor, gradDirection);


		// Skip the default event handler to prevent flickering
		event.Skip();
	}


};