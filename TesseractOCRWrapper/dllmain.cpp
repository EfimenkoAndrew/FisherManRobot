// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		char tesseractPath[256];
		if (::GetEnvironmentVariableA("TESSDATA_PREFIX", tesseractPath, 256) <= 0)
		{
			throw std::exception("TESSDATA_PREFIX (path to tesseract language) environment variable is not set. Download language https://github.com/tesseract-ocr/tessdata and set environment variable.");
		}
	}
	break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

