#ifndef TOGGLEBUTTONWRAPPER_H
#define TOGGLEBUTTONWRAPPER_H

#include "wxc_widget.h" // Base class: WrapperBase

class ToggleButtonWrapper : public wxcWidget
{

public:
    ToggleButtonWrapper();
    virtual ~ToggleButtonWrapper();

public:
    virtual wxcWidget* Clone() const;
    virtual wxString CppCtorCode() const;
    virtual void GetIncludeFile(wxArrayString& headers) const;
    virtual wxString GetWxClassName() const;
    virtual void LoadPropertiesFromXRC(const wxXmlNode* node);
    virtual void LoadPropertiesFromwxFB(const wxXmlNode* node);
    virtual void LoadPropertiesFromwxSmith(const wxXmlNode* node);
    virtual void ToXRC(wxString& text, XRC_TYPE type) const;
};

#endif // TOGGLEBUTTONWRAPPER_H
