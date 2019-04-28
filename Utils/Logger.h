#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>

#ifdef _DEBUG
#include <ios>
#include <iostream>
#include <streambuf>
#include <iosfwd>
#endif

#include <windows.storage.h>
#include <wrl.h>
#include <mutex>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Utils.h"
#include <vector>

#pragma comment(lib,"runtimeobject")

#ifndef logF 
#define logF Logger::WriteLogFileF
#endif

using namespace ABI::Windows::Storage;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

struct TextForPrint {
	char text[80];
	char f = 0;
	size_t length;
};

class Logger {
private:
	static std::wstring GetRoamingFolderPath();
public:
	static void WriteLogFileF(const char* fmt, ...);
	static std::vector<TextForPrint*> GetTextToPrint();
	static CRITICAL_SECTION* GetTextToPrintSection();
	//static std::vector<TextForPrint*> stringPrintVector;
	static void Disable();
};

extern char logPath[200];
extern bool yeet;
extern CRITICAL_SECTION loggerLock;
extern CRITICAL_SECTION vecLock;
extern std::vector<TextForPrint*> stringPrintVector;