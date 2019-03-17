// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TESSERACTOCRWRAPPER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TESSERACTOCRWRAPPER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TESSERACTOCRWRAPPER_EXPORTS
#define TESSERACTOCRWRAPPER_API __declspec(dllexport)
#else
#define TESSERACTOCRWRAPPER_API __declspec(dllimport)
#endif

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <string>
// This class is exported from the TesseractOCRWrapper.dll
class TESSERACTOCRWRAPPER_API CTesseractOCRWrapper 
{
private:
	tesseract::TessBaseAPI _tessApi;
public:
	CTesseractOCRWrapper();
	~CTesseractOCRWrapper();
	CTesseractOCRWrapper(const std::string& lang);
	std::string GetText(const std::string& imagePath);
};
typedef CTesseractOCRWrapper ocr;
