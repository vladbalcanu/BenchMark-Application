#include "cMain.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "time.h"
#include <windows.h>
#include <intrin.h>
#define _WIN32_DCOM
#include <iostream>
#include <comdef.h>
#include <WbemIdl.h>
#include <string.h>
#include "FunctionsHeader.h"
#pragma comment(lib, "wbemuuid.lib")
#define MB 1048576
using std::string;

using namespace std;
SYSTEM_INFO sysInfo;
static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	static unsigned long long _previousTotalTicks = 0;
	static unsigned long long _previousIdleTicks = 0;

	unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
	unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;


	float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

	_previousTotalTicks = totalTicks;
	_previousIdleTicks = idleTicks;
	return ret;
}

static unsigned long long FileTimeToInt64(const FILETIME& ft)
{
	return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime);
}

// Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
// You'll need to call this at regular intervals, since it measures the load between
// the previous call and the current one.  Returns -1.0 on error.
float GetCPULoad()
{
	FILETIME idleTime, kernelTime, userTime;
	return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
}

string CpuLoadFunction() {
	int result = (GetCPULoad() * 100);
	return std::to_string(result);
}

string cpuNameFunction()
{
	int CPUInfo[4] = { -1 };
	unsigned   nExIds, i = 0;
	char CPUBrandString[0x40];
	// Get the information associated with each extended ID.
	__cpuid(CPUInfo, 0x80000000);
	nExIds = CPUInfo[0];
	for (i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		// Interpret CPU brand string
		if (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}

	return CPUBrandString;
}
string cpuArchitectureNrFunction() {
	GetNativeSystemInfo(&sysInfo);
	return std::to_string(sysInfo.wProcessorArchitecture);
}
string cpuArchitectureFunction() {
	string CpuArch;
	GetNativeSystemInfo(&sysInfo);
	if (sysInfo.wProcessorArchitecture == 9) {
		CpuArch = "PROCESSOR_ARCHITECTURE_AMD64 - x64(AMD or Intel)";
	}
	else if (sysInfo.wProcessorArchitecture == 5) {
		CpuArch = "PROCESSOR_ARCHITECTURE_ARM - ARM";
	}
	else if (sysInfo.wProcessorArchitecture == 12) {
		CpuArch = "PROCESSOR_ARCHITECTURE_ARM64 - ARM64";
	}
	else if (sysInfo.wProcessorArchitecture == 6) {
		CpuArch = "PROCESSOR_ARCHITECTURE_IA64 - Intel Itanium-based";
	}
	else if (sysInfo.wProcessorArchitecture == 0) {
		CpuArch = "PROCESSOR_ARCHITECTURE_INTEL - x86";
	}
	else
	{
		CpuArch = "PROCESSOR_ARCHITECTURE_UNKNOWN - Unknown architecture.";
	}
	return CpuArch;
}
string cpuTypeNr() {
	GetNativeSystemInfo(&sysInfo);
	return std::to_string(sysInfo.dwProcessorType);
}
string cpuTypeFunction() {
	string CpuType;
	GetNativeSystemInfo(&sysInfo);
	if (sysInfo.dwProcessorType == 386) {
		CpuType = "PROCESSOR_INTEL_386";
	}
	else if (sysInfo.dwProcessorType == 486) {
		CpuType = "PROCESSOR_INTEL_486";
	}
	else if (sysInfo.dwProcessorType == 586) {
		CpuType = "PROCESSOR_INTEL_PENTIUM";
	}
	else if (sysInfo.dwProcessorType == 2200) {
		CpuType = "PROCESSOR_INTEL_IA64";
	}
	else if (sysInfo.dwProcessorType == 8664) {
		CpuType = "PROCESSOR_INTEL_X8664";
	}
	else {CpuType = "PROCESSOR_ARM";}

	return CpuType;
}
string nrOfProcFunction() {
	GetNativeSystemInfo(&sysInfo);
	string nrOfProc = std::to_string(sysInfo.dwNumberOfProcessors);
	return nrOfProc;
}