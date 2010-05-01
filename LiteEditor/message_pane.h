#ifndef __message_pane__
#define __message_pane__

/**
@file
Subclass of MessagePaneBase, which is generated by wxFormBuilder.
*/

#include "messagepane_base.h"
#include <vector>

class ButtonDetails
{
public:
	wxString      buttonLabel;
	int           commandId;
	wxEvtHandler* window;
	bool          menuCommand;
	bool          isDefault;
	
public:
	ButtonDetails() : buttonLabel(wxT("")), commandId(wxNOT_FOUND), window(NULL), menuCommand(true)
	{}
	~ButtonDetails()
	{}
};

class MessageDetails
{
public:
	wxString      message;
	wxBitmap      bmp;
	ButtonDetails btn1;
	ButtonDetails btn2;
	ButtonDetails btn3;
	bool          showHideButton;
	
public:
	MessageDetails() : bmp(wxNullBitmap), showHideButton(true)
	{}
	
	~MessageDetails()
	{}
};

class MessagePaneData
{
	std::vector<MessageDetails> m_queue;
public:
	MessagePaneData() {}
	~MessagePaneData() {
		Clear();
	}

	void           PushMessage(const MessageDetails &msg);
	void           PopMessage();
	MessageDetails CurrentMessage();
	void           Clear();
	bool           IsEmpty();
};

/** Implementing MessagePaneBase */
class MessagePane : public MessagePaneBase
{
	MessagePaneData m_messages;
	
protected:
	// Handlers for MessagePaneBase events.
	void OnKeyDown( wxKeyEvent& event );
	void OnButtonClose( wxCommandEvent& event );
	void OnActionButton( wxCommandEvent& event );
	void OnActionButton1( wxCommandEvent& event );
	void OnActionButton2( wxCommandEvent& event );

	void OnEraseBG( wxEraseEvent& event );
	void OnPaint( wxPaintEvent& event );

	void DoHide();
	void DoShowNextMessage();
	void DoShowCurrentMessage();
	void DoPostEvent(ButtonDetails btn);
	
public:
	/** Constructor */
	MessagePane( wxWindow* parent );

	void ShowMessage(const wxString &message, bool showHideButton = true, const wxBitmap &bmp = wxNullBitmap, const ButtonDetails& btn1 = ButtonDetails(), const ButtonDetails& btn2 = ButtonDetails(), const ButtonDetails& btn3 = ButtonDetails());
};

#endif // __message_pane__
