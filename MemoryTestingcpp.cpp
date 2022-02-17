#include "cMain.h"
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <intrin.h>
#define _WIN32_DCOM
#include <comdef.h>
#include <WbemIdl.h>
#include <string.h>
#include "FunctionsHeader.h"
#pragma comment(lib, "wbemuuid.lib")
#define MB 1048576
using std::string;
using namespace std;

MEMORYSTATUSEX statex;
SYSTEM_INFO sysInfo2;
MEMORYSTATUSEX memStat;

string totalMemFunction() {
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	return std::to_string(((statex.ullTotalPhys / 1024) / 1024));
}
string pageFileFunction() {
	GetNativeSystemInfo(&sysInfo2);
	return std::to_string(sysInfo2.dwPageSize);
}
string memoryLoadFunction() {
	memStat.dwLength = sizeof(memStat);
	GlobalMemoryStatusEx(&memStat);
	return std::to_string(memStat.dwMemoryLoad);
}
string remainingMemFunction() {
	memStat.dwLength = sizeof(memStat);
	GlobalMemoryStatusEx(&memStat);
	return std::to_string(memStat.ullAvailPhys/MB);
}
string totalPageFileFunction() {
	memStat.dwLength = sizeof(memStat);
	GlobalMemoryStatusEx(&memStat);
	return std::to_string(memStat.ullTotalPageFile / MB);
}
string remainingPageFileFunction() {
	memStat.dwLength = sizeof(memStat);
	GlobalMemoryStatusEx(&memStat);
	return std::to_string(memStat.ullAvailPageFile / MB);
}
string totalVirtualMemFunction() {
	memStat.dwLength = sizeof(memStat);
	GlobalMemoryStatusEx(&memStat);
	return std::to_string(memStat.ullTotalVirtual / MB);
}
string remainingVirtualMemFunction() {
	memStat.dwLength = sizeof(memStat);
	GlobalMemoryStatusEx(&memStat);
	return std::to_string(memStat.ullAvailVirtual / MB);
}

