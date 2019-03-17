// TesseractOCRWrapper.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "TesseractOCRWrapper.h"

// This is the constructor of a class that has been exported.
// see TesseractOCRWrapper.h for the class definition
CTesseractOCRWrapper::CTesseractOCRWrapper()
{
	this->_tessApi.Init(NULL, NULL);
}

CTesseractOCRWrapper::~CTesseractOCRWrapper()
{
	this->_tessApi.End();
}

CTesseractOCRWrapper::CTesseractOCRWrapper(const std::string& lang)
{
	this->_tessApi.Init(NULL, lang.c_str());
}

std::string CTesseractOCRWrapper::GetText(const std::string& imagePath)
{
	Pix* image = pixRead(imagePath.c_str());
	std::string outText = "";
	this->_tessApi.SetImage(image);
	outText = this->_tessApi.GetUTF8Text();
	pixDestroy(&image);
	return outText;
}
