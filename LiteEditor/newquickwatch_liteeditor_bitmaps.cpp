//
// This file was automatically generated by wxrc, do not edit by hand.
//

#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include <wx/filesys.h>
#include <wx/fs_mem.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_all.h>

#if wxCHECK_VERSION(2,8,5) && wxABI_VERSION >= 20805
    #define XRC_ADD_FILE(name, data, size, mime) \
        wxMemoryFSHandler::AddFileWithMimeType(name, data, size, mime)
#else
    #define XRC_ADD_FILE(name, data, size, mime) \
        wxMemoryFSHandler::AddFile(name, data, size)
#endif

static size_t xml_res_size_0 = 520;
static unsigned char xml_res_file_0[] = {
137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,16,0,0,0,16,8,6,0,0,
0,31,243,255,97,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,
65,100,111,98,101,32,73,109,97,103,101,82,101,97,100,121,113,201,101,60,
0,0,1,170,73,68,65,84,120,218,98,252,255,255,63,3,37,128,137,129,66,192,
2,99,56,206,127,53,19,72,25,35,75,2,93,151,14,164,206,162,107,186,115,241,
34,195,147,137,110,168,6,252,249,243,199,56,214,91,202,248,246,131,159,
95,84,21,216,121,182,29,126,115,235,221,231,223,24,54,62,191,127,31,187,
11,126,255,252,201,112,249,250,151,47,18,34,156,60,27,86,156,96,120,199,
42,182,230,247,175,95,103,127,253,248,193,240,243,251,119,134,95,63,190,
3,233,31,12,204,44,44,216,195,0,100,128,166,42,55,207,145,221,167,24,140,
172,12,24,184,217,153,66,128,94,40,32,58,16,65,54,45,91,127,243,214,211,
95,92,109,7,78,62,184,101,160,42,162,198,197,202,152,73,200,16,184,123,
254,254,249,147,254,238,195,23,144,19,207,190,126,243,225,245,161,147,63,
50,45,245,101,213,78,92,124,148,249,19,18,213,19,8,69,227,89,88,136,3,109,
157,240,230,237,251,233,135,78,222,186,101,172,33,174,198,141,234,18,99,
228,216,98,193,229,52,144,33,175,222,124,96,216,127,226,71,166,153,169,
154,218,201,179,119,50,129,129,40,202,205,205,30,242,233,227,215,207,64,
37,38,4,19,18,216,37,175,223,79,63,120,244,218,45,101,83,77,53,22,46,142,
16,15,63,99,181,95,192,88,193,233,130,183,207,159,51,252,249,253,27,20,
38,16,252,251,247,132,31,223,191,139,158,218,127,46,68,206,213,70,109,221,
133,55,95,126,1,99,12,107,82,6,105,126,243,236,25,195,135,215,175,25,62,
191,127,207,240,237,243,103,134,159,63,126,24,255,17,18,10,49,139,116,85,
187,249,252,227,23,93,125,89,158,223,72,6,176,160,27,128,13,252,125,244,
232,243,206,246,57,224,0,222,185,133,129,129,145,145,17,158,188,25,7,60,
55,2,4,24,0,102,229,224,119,239,71,189,20,0,0,0,0,73,69,78,68,174,66,96,
130};

static size_t xml_res_size_1 = 208;
static unsigned char xml_res_file_1[] = {
60,63,120,109,108,32,118,101,114,115,105,111,110,61,34,49,46,48,34,32,101,
110,99,111,100,105,110,103,61,34,85,84,70,45,56,34,63,62,10,60,114,101,
115,111,117,114,99,101,32,120,109,108,110,115,61,34,104,116,116,112,58,
47,47,119,119,119,46,119,120,119,105,110,100,111,119,115,46,111,114,103,
47,119,120,120,114,99,34,62,10,32,32,60,111,98,106,101,99,116,32,99,108,
97,115,115,61,34,119,120,66,105,116,109,97,112,34,32,110,97,109,101,61,
34,114,101,115,105,122,101,34,62,110,101,119,113,117,105,99,107,119,97,
116,99,104,95,108,105,116,101,101,100,105,116,111,114,95,98,105,116,109,
97,112,115,46,99,112,112,36,46,46,95,105,99,111,110,115,95,114,101,115,
105,122,101,46,112,110,103,60,47,111,98,106,101,99,116,62,10,60,47,114,
101,115,111,117,114,99,101,62,10};

void wxCB786InitBitmapResources()
{

    // Check for memory FS. If not present, load the handler:
    {
        wxMemoryFSHandler::AddFile(wxT("XRC_resource/dummy_file"), wxT("dummy one"));
        wxFileSystem fsys;
        wxFSFile *f = fsys.OpenFile(wxT("memory:XRC_resource/dummy_file"));
        wxMemoryFSHandler::RemoveFile(wxT("XRC_resource/dummy_file"));
        if (f) delete f;
        else wxFileSystem::AddHandler(new wxMemoryFSHandlerBase);
    }

    XRC_ADD_FILE(wxT("XRC_resource/newquickwatch_liteeditor_bitmaps.cpp$.._icons_resize.png"), xml_res_file_0, xml_res_size_0, wxT("image/png"));
    XRC_ADD_FILE(wxT("XRC_resource/newquickwatch_liteeditor_bitmaps.cpp$_home_david_devel_git_CL_LiteEditor_newquickwatch_liteeditor_bitmaps.xrc"), xml_res_file_1, xml_res_size_1, wxT("text/xml"));
    wxXmlResource::Get()->Load(wxT("memory:XRC_resource/newquickwatch_liteeditor_bitmaps.cpp$_home_david_devel_git_CL_LiteEditor_newquickwatch_liteeditor_bitmaps.xrc"));
}
