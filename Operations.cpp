#include <iostream>
#include <string>
#define rdtsc __asm __emit 0fh __asm __emit 031h
#define cpuid __asm __emit 0fh __asm __emit 0a2h
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <thread>
#include <random>

using std::string;
using namespace std;

float get_random()
{
	static std::default_random_engine e;
	static std::uniform_real_distribution<> dis(0, 1000); // rage 0 - 1
	return dis(e);
}

string andFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);


	for (int i = 0; i < nrOfTimes; i++) {

		int firstNumber, secondNumber;
		firstNumber = rand() % 1000;
		secondNumber = rand() % 1000;

		__asm {
			mov ebx, firstNumber
			mov ecx, secondNumber
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 1000
			loop1:
			and ebx,ecx
				loop loop1
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}


		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles/1000;
		if (min > total_cycles / 1000) {

			min = total_cycles / 1000;
		}
		if (max < total_cycles / 1000) {
			max = total_cycles / 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;
}
string orFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);


	for (int i = 0; i < nrOfTimes; i++) {

		int firstNumber, secondNumber;
		firstNumber = rand() % 1000;
		secondNumber = rand() % 1000;

		__asm {
			mov ebx,firstNumber
			mov ecx,secondNumber
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 1000
			loop1:
			or ebx,eax
				loop loop1
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}


		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles/1000;
		if (min > total_cycles / 1000) {

			min = total_cycles / 1000;
		}
		if (max < total_cycles / 1000) {
			max = total_cycles / 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;
}
string mulFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);


	for (int i = 0; i < nrOfTimes; i++) {

		int firstNumber, secondNumber;
		firstNumber = rand() % 1000;
		secondNumber = rand() % 1000;

		__asm {
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 1000
			loop1:
			mov eax, firstNumber
			mul secondNumber
				loop loop1
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}


		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles/1000;
		if (min > total_cycles / 1000) {

			min = total_cycles / 1000;
		}
		if (max < total_cycles / 1000) {
			max = total_cycles / 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;
}
string subFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);


	for (int i = 0; i < nrOfTimes; i++) {

		int firstNumber, secondNumber;
		firstNumber = rand() % 1000;
		secondNumber = rand() % 1000;

		__asm {
			mov ebx, firstNumber
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 1000
			loop1:
				sub ebx, ecx
				loop loop1;
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}


		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles/1000;
		if (min > total_cycles / 1000) {

			min = total_cycles / 1000;
		}
		if (max < total_cycles / 1000) {
			max = total_cycles / 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;
}

string addFunction(int nrOfTimes){
		unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
		unsigned cycles_high2 = 0, cycles_low2 = 0;
		unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
		__int64 total_cycles = 0;
		

		int max = 0;
		int min = 1000000;
		long long medie = 0;
		int first = 0;
		HANDLE process = GetCurrentProcess();

		DWORD_PTR processAffinityMask;
		DWORD_PTR systemAffinityMask;


		GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
		int core = 2;
		DWORD_PTR mask = 0x1;
		for (int bit = 0, currentCore = 1; bit < 64; bit++)
		{
			if (mask & processAffinityMask)
			{
				if (currentCore != core)
				{
					processAffinityMask &= ~mask;
				}
				else
				{
					if (!(systemAffinityMask & mask))
					{
						cerr << "Core " << core << " not enabled in system." << endl;
					}
				}
				currentCore++;
			}
			mask = mask << 1;
		}
		SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);


		for (int i = 0; i < nrOfTimes; i++) {

			int firstNumber, secondNumber;
			firstNumber = rand() % 1000;
			secondNumber = rand() % 1000;

			__asm {
				mov ebx, firstNumber
				mov ecx, secondNumber
				cpuid
				rdtsc
				mov cycles_high1, edx
				mov cycles_low1, eax
				mov ecx, 1000
				loop1:
					add ebx, ecx
					loop loop1
				rdtsc
				mov cycles_high2, edx
				mov cycles_low2, eax
			}


			temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
			temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
			total_cycles = temp_cycles2 - temp_cycles1;



			medie += total_cycles;
			if (first == 0 ) 
				first = total_cycles/ 1000;
			if (min > total_cycles/ 1000) {

				min = total_cycles/ 1000;
			}
			if (max < total_cycles/ 1000) {
				max = total_cycles/ 1000;
			}

		}
		
		medie = medie / (nrOfTimes* 1000);
		string firstAction = to_string(first);
		string minAction=to_string(min);
		string maxAction = to_string(max);
		string medieAction = to_string(medie);
		string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;
		
		return total;
	}

string divFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);

	
	for (int i = 0; i < nrOfTimes; i++) {
		__asm {
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 1000
			loop1:
			mov edx,0
			mov ebx, 50
			mov eax, 1000
			idiv ebx
				loop loop1
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}
		


		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles/ 1000;
		if (min > total_cycles/ 1000) {

			min = total_cycles/ 1000;
		}
		if (max < total_cycles/ 1000) {
			max = total_cycles/ 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;
	
}
string floatAddFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);
	


	for (int i = 0; i < nrOfTimes; i++) {
		double firstNumber = get_random();
		double secondNumber = get_random();
		__asm {
			fld secondNumber;
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 1000
			loop1:
			fadd firstNumber
				loop loop1;
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}



		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles/1000;
		if (min > total_cycles/1000) {

			min = total_cycles/1000;
		}
		if (max < total_cycles / 1000) {
			max = total_cycles / 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;

}
string floatSubFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);



	for (int i = 0; i < nrOfTimes; i++) {
		double firstNumber = get_random();
		double secondNumber = get_random();
		__asm {
			fld firstNumber
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 1000
			loop1:
			fsub secondNumber
				loop loop1
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}



		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles/1000;
		if (min > total_cycles / 1000) {

			min = total_cycles / 1000;
		}
		if (max < total_cycles / 1000) {
			max = total_cycles / 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;

}
string floatMulFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);



	for (int i = 0; i < nrOfTimes; i++) {
		double firstNumber = get_random();
		double secondNumber = get_random();
		__asm {
			fld firstNumber
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 1000
			loop1:
			fmul secondNumber
				loop loop1
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}



		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles / 1000;
		if (min > total_cycles / 1000) {

			min = total_cycles / 1000;
		}
		if (max < total_cycles / 1000) {
			max = total_cycles / 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;

}

string floatDivFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);



	for (int i = 0; i < nrOfTimes; i++) {
		double firstNumber = get_random();
		double secondNumber = get_random();
		__asm {
			fld firstNumber
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx,1000
			loop1:
			fdiv secondNumber
				loop loop1
			rdtsc
			mov cycles_high2, edx
			mov cycles_low2, eax
		}



		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
		if (first == 0)
			first = total_cycles / 1000;
		if (min > total_cycles / 1000) {

			min = total_cycles / 1000;
		}
		if (max < total_cycles / 1000) {
			max = total_cycles / 1000;
		}

	}

	medie = medie / (nrOfTimes*1000);
	string firstAction = to_string(first);
	string minAction = to_string(min);
	string maxAction = to_string(max);
	string medieAction = to_string(medie);
	string total = firstAction + " " + minAction + " " + maxAction + " " + medieAction;

	return total;

}


string transferDataFunction(int nrOfTimes) {
	unsigned cycles_high1 = 0, cycles_low1 = 0, cupid_time = 0;
	unsigned cycles_high2 = 0, cycles_low2 = 0;
	unsigned __int64 temp_cycles1 = 0, temp_cycles2 = 0;
	__int64 total_cycles = 0;


	int max = 0;
	int min = 1000000;
	long long medie = 0;
	int first = 0;
	HANDLE process = GetCurrentProcess();

	DWORD_PTR processAffinityMask;
	DWORD_PTR systemAffinityMask;


	GetProcessAffinityMask(process, &processAffinityMask, &systemAffinityMask);
	int core = 2;
	DWORD_PTR mask = 0x1;
	for (int bit = 0, currentCore = 1; bit < 64; bit++)
	{
		if (mask & processAffinityMask)
		{
			if (currentCore != core)
			{
				processAffinityMask &= ~mask;
			}
			else
			{
				if (!(systemAffinityMask & mask))
				{
					cerr << "Core " << core << " not enabled in system." << endl;
				}
			}
			currentCore++;
		}
		mask = mask << 1;
	}
	SetProcessAffinityMask(process, processAffinityMask & systemAffinityMask);


	for (int i = 0; i < nrOfTimes; i++) {
		int firstNumber = rand() % 10000;
		__asm {
			mov eax, firstNumber
			mov DWORD PTR[ESI], eax
			cpuid
			rdtsc
			mov cycles_high1, edx
			mov cycles_low1, eax
			mov ecx, 50
			loop1:
			mov eax, DWORD PTR[ESI]
				add ESI, 4
				mov DWORD PTR[ESI], eax
				loop loop1
				rdtsc
				mov cycles_high2, edx
				mov cycles_low2, eax
		}



		temp_cycles1 = ((unsigned __int64)cycles_high1 << 32) | cycles_low1;
		temp_cycles2 = ((unsigned __int64)cycles_high2 << 32) | cycles_low2;
		total_cycles = temp_cycles2 - temp_cycles1;



		medie += total_cycles;
	}
	string total = to_string(medie/nrOfTimes);
	medie = medie / (nrOfTimes*50);
	string medieAction = to_string(medie);
	string result = total + " " + medieAction;

	return result;
}


