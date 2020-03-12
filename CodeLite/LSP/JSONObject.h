#ifndef JSONObject_H
#define JSONObject_H

#include "JSON.h"
#include "codelite_exports.h"
#include "IPathConverter.hpp"

namespace LSP
{
//===-----------------------------------------------------------------------------------
// Base type class
//===-----------------------------------------------------------------------------------
class WXDLLIMPEXP_CL Serializable
{
public:
    Serializable() {}
    virtual ~Serializable() {}
    virtual JSONItem ToJSON(const wxString& name, IPathConverter::Ptr_t pathConverter) const = 0;
    virtual void FromJSON(const JSONItem& json, IPathConverter::Ptr_t pathConverter) = 0;
};

};     // namespace LSP
#endif // JSONObject_H
