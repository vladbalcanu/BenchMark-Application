#include "cMain.h"
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
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
using std::string;
using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector; using std::istringstream;
using std::stringstream;
#define rdtsc __asm __emit 0fh __asm __emit 031h
#define cpuid __asm __emit 0fh __asm __emit 0a2h

#include "FunctionsHeader.h"
#pragma comment(lib, "wbemuuid.lib")
#define MB 1048576
int nrOfTimes;



using namespace std;

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
EVT_BUTTON(10002, NextPageButtonClicked)
EVT_BUTTON(10003, BackToFirstPageButtonClicked)
EVT_BUTTON(10004, OpButtonClicked)
EVT_TIMER(10002, realTimeFunctionExec)
EVT_CHOICE(10020, ChoiceClicked)

wxEND_EVENT_TABLE()
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "PC BENCHMARK",wxPoint(50,50), wxSize(1200,600))
{
	constDataPanel = new wxPanel(this, 10010, wxDefaultPosition, wxSize(1200, 300));
	constDataPanel->SetBackgroundColour(wxColor(178, 102, 255));
	realTimeDataPanel = new wxPanel(this, 10011, wxPoint(0, 300), wxSize(800, 300));
	realTimeDataPanel->SetBackgroundColour(wxColor(102,179,202));
	nextPage = new wxPanel(this, 10012, wxPoint(800,300), wxSize(400,300));
	nextPage->SetBackgroundColour(wxColor(255, 102, 178));
	secondPage = new wxPanel(this, 10013, wxDefaultPosition, wxSize(1200, 300));
	secondPage->SetBackgroundColour(wxColor(178, 102, 255));
	secondPage->Show(false);
	floatingPoint = new wxPanel(this, 10014, wxPoint(0, 300), wxSize(1200,130));
	floatingPoint->SetBackgroundColour(wxColor(112, 87, 150));
	floatingPoint->Show(false);
	memSpeedPage=new wxPanel(this, 10015, wxPoint(0, 430), wxSize(1200, 170));
	memSpeedPage->SetBackgroundColour(wxColor(200, 50, 100));
	memSpeedPage->Show(false);

	wxFont myFont(16, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont secondFont(11, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);


	start_button = new wxButton(constDataPanel, 10001, "Start Benchmark", wxPoint(450, 10), wxSize(300, 100));
	start_button->SetFont(myFont);
	start_button->SetBackgroundColour(wxColor(255, 153, 51));
	start_button->SetExtraStyle(wxBORDER_NONE);
	
	nextPageButton = new wxButton(nextPage, 10002, "Arithmetic and Logical\n Operations Page", wxPoint(50,70), wxSize(300, 100));
	nextPageButton->SetFont(myFont);
	nextPageButton->SetBackgroundColour(wxColor(255,204,255));
	nextPageButton->SetExtraStyle(wxBORDER_NONE);

	backToFirstPageButton = new wxButton(secondPage, 10003, "Back to\nFirst Page", wxPoint(300,10), wxSize(300, 100));
	backToFirstPageButton->SetFont(myFont);
	backToFirstPageButton->SetBackgroundColour(wxColor(102, 179, 202));

	startButtonOp = new wxButton(secondPage, 10004, "Start Operations", wxPoint(605, 10), wxSize(300, 100));
	startButtonOp->SetFont(myFont);
	startButtonOp->SetBackgroundColour(wxColor(102, 179, 102));



	cpuName = new wxStaticText(constDataPanel, wxID_ANY, "CPU Name :", wxPoint(30, 120), wxSize(80, 20));
	cpuName->SetFont(secondFont);

	cpuNameText = new wxTextCtrl(constDataPanel, wxID_ANY, "", wxPoint(125, 118), wxSize(400, 20));
	cpuNameText->SetFont(secondFont);

	numberOfProcessors = new wxStaticText(constDataPanel, wxID_ANY, "Number of Processors :", wxPoint(620,120),wxSize(125,20));
	numberOfProcessors->SetFont(secondFont);

	nrOfProcText = new wxTextCtrl(constDataPanel, wxID_ANY, "", wxPoint(830 , 118), wxSize(30, 20));
	nrOfProcText->SetFont(secondFont);


	cpuType = new wxStaticText(constDataPanel, wxID_ANY, "CPU Type :", wxPoint(30, 180), wxSize(60, 20));
	cpuType->SetFont(secondFont);

	cpuTypeText = new wxTextCtrl(constDataPanel, wxID_ANY, "", wxPoint(125, 178), wxSize(60, 20));
	cpuTypeText->SetFont(secondFont);

	cpuTypeDef = new wxTextCtrl(constDataPanel, wxID_ANY, "", wxPoint(200, 178), wxSize(205, 20));
	cpuTypeDef->SetFont(secondFont);

	cpuArchitecture = new wxStaticText(constDataPanel, wxID_ANY, "CPU Architecture :", wxPoint(430, 180), wxSize(100, 20));
	cpuArchitecture->SetFont(secondFont);

	cpuArchitectureText = new wxTextCtrl(constDataPanel, wxID_ANY, "", wxPoint(600, 178), wxSize(45, 20));
	cpuArchitectureText->SetFont(secondFont);

	cpuArchitectureDef = new wxTextCtrl(constDataPanel, wxID_ANY, "", wxPoint(670, 178), wxSize(450, 20));
	cpuArchitectureDef->SetFont(secondFont);
	
	totalMem = new wxStaticText(constDataPanel, wxID_ANY, "Total Memory :", wxPoint(30, 240), wxSize(80, 20));
	totalMem->SetFont(secondFont);
	
	totalMemText = new wxTextCtrl(constDataPanel, wxID_ANY, "", wxPoint(165, 238), wxSize(100, 20));
	totalMemText->SetFont(secondFont);

	pageFile = new wxStaticText(constDataPanel, wxID_ANY, "Page Size :", wxPoint(340, 240), wxSize(60, 20));
	pageFile->SetFont(secondFont);

	pageFileText = new wxTextCtrl(constDataPanel, wxID_ANY, "", wxPoint(450, 238), wxSize(100, 20));
	pageFileText->SetFont(secondFont);

	
	cpuLoad = new wxStaticText(realTimeDataPanel, wxID_ANY, "CPU Load :", wxPoint(30, 10),wxSize(70,20));
	cpuLoad->SetFont(secondFont);

	cpuLoadText = new wxTextCtrl(realTimeDataPanel, wxID_ANY, "", wxPoint(125, 8), wxSize(40,20));
	cpuLoadText->SetFont(secondFont);

	memLoad = new wxStaticText(realTimeDataPanel, wxID_ANY, "Memory Load :", wxPoint(190, 10), wxSize(100, 20));
	memLoad->SetFont(secondFont);

	memLoadText = new wxTextCtrl(realTimeDataPanel, wxID_ANY, "", wxPoint(320,8),wxSize(40,20));
	memLoadText->SetFont(secondFont);

	availMem = new wxStaticText(realTimeDataPanel, wxID_ANY, "Available Memory :", wxPoint(390, 10), wxSize(102, 20));
	availMem->SetFont(secondFont);

	availMemText = new wxTextCtrl(realTimeDataPanel, wxID_ANY, "", wxPoint(570, 8), wxSize(100, 20));
	availMemText->SetFont(secondFont);

	totalVirtualMem = new wxStaticText(realTimeDataPanel, wxID_ANY, "Total Virtual Memory :", wxPoint(30, 80), wxSize(120, 20));
	totalVirtualMem->SetFont(secondFont);

	totalVirtualMemText = new wxTextCtrl(realTimeDataPanel, wxID_ANY, "", wxPoint(235, 78), wxSize(100, 20));
	totalVirtualMemText->SetFont(secondFont);

	availVirtualMem = new wxStaticText(realTimeDataPanel, wxID_ANY, "Available Virtual Memory :", wxPoint(390, 80), wxSize(140, 20));
	availVirtualMem->SetFont(secondFont);

	availVirtualMemText = new wxTextCtrl(realTimeDataPanel, wxID_ANY, "", wxPoint(635, 78), wxSize(100, 20));
	availVirtualMemText->SetFont(secondFont);

	totalPageFile = new wxStaticText(realTimeDataPanel, wxID_ANY, "Total Page File :", wxPoint(30, 150), wxSize(95, 20));
	totalPageFile->SetFont(secondFont);

	totalPageFileText = new wxTextCtrl(realTimeDataPanel, wxID_ANY, "", wxPoint(190, 148), wxSize(100, 20));
	totalPageFileText->SetFont(secondFont);

	availPageFile = new wxStaticText(realTimeDataPanel, wxID_ANY, "Available Page File :", wxPoint(390, 150), wxSize(115, 20));
	availPageFile->SetFont(secondFont);

	availPageFileText = new wxTextCtrl(realTimeDataPanel, wxID_ANY, "", wxPoint(600, 148), wxSize(100, 20));
	availPageFileText->SetFont(secondFont);

	integerOperations = new wxStaticText(secondPage, wxID_ANY, " OPERATIONS ON INTEGERS SECTION", wxPoint(470, 180), wxSize(100, 20));
	integerOperations->SetFont(secondFont);

	nrOfTimesArithAndLog = new wxStaticText(secondPage, wxID_ANY, "Introduce the number of times you wish to run the functions : ", wxPoint(30, 140), wxSize(200, 20));
	nrOfTimesArithAndLog->SetFont(secondFont);

	nrOfTimesArithAndLogText = new wxTextCtrl(secondPage, wxID_ANY, "", wxPoint(600,138), wxSize(100,20));
	nrOfTimesArithAndLogText->SetFont(secondFont);


	choices = new wxArrayString();
	choices->Add("ADD");
	choices->Add("SUB");
	choices->Add("DIV");
	choices->Add("MUL");
	choices->Add("OR");
	choices->Add("AND");

	selectionBar = new wxChoice(secondPage, 10020, wxPoint(710,135), wxSize(100, 20), *choices);
	selectionBar->SetFont(secondFont);
	
	firstOperation = new wxStaticText(secondPage, wxID_ANY, "First Run :", wxPoint(100,220), wxSize(50,20));
	firstOperation->SetFont(secondFont);

	firstOperationText = new wxTextCtrl(secondPage, wxID_ANY, "", wxPoint(220, 218), wxSize(50, 20));
	firstOperationText->SetFont(secondFont);

	minOperation = new wxStaticText(secondPage, wxID_ANY, "Minimum number of Clocks :", wxPoint(340, 220), wxSize(100, 20));
	minOperation->SetFont(secondFont);

	minOperationText = new wxTextCtrl(secondPage, wxID_ANY, "", wxPoint(590, 218), wxSize(100,20));
	minOperationText->SetFont(secondFont);

	maxOperation = new wxStaticText(secondPage, wxID_ANY, "Maximum number of Clocks :", wxPoint(750, 220), wxSize(150, 20));
	maxOperation->SetFont(secondFont);

	maxOperationText = new wxTextCtrl(secondPage, wxID_ANY, "", wxPoint(1000, 218), wxSize(100, 20));
	maxOperationText->SetFont(secondFont);

	avgOperation = new wxStaticText(secondPage, wxID_ANY, "Average number of Clocks :", wxPoint(450, 270), wxSize(150, 20));
	avgOperation->SetFont(secondFont);

	avgOperationText = new wxTextCtrl(secondPage, wxID_ANY, "", wxPoint(700, 268), wxSize(100, 20));
	avgOperationText->SetFont(secondFont);

	floatingPointText = new wxStaticText(floatingPoint, wxID_ANY, "FLOATING POINT OPEARTIONS SECTION", wxPoint(470, 10), wxSize(200,80));
	floatingPointText->SetFont(secondFont);

	floatingPointFirst = new wxStaticText(floatingPoint, wxID_ANY, "First Run : ", wxPoint(100, 40), wxSize(50, 20));
	floatingPointFirst->SetFont(secondFont);

	floatFirstText = new wxTextCtrl(floatingPoint, wxID_ANY, "", wxPoint(210, 38), wxSize(60, 20));
	floatFirstText->SetFont(secondFont);

	floatingPointMin = new wxStaticText(floatingPoint, wxID_ANY, "Minimum number of Clocks :", wxPoint(400,40), wxSize(150, 20));
	floatingPointMin->SetFont(secondFont);

	floatMinText = new wxTextCtrl(floatingPoint,wxID_ANY,"",wxPoint(640,38),wxSize(60,20));
	floatMinText->SetFont(secondFont);

	floatingPointMax = new wxStaticText(floatingPoint, wxID_ANY, "Maximum number of Clocks :", wxPoint(760,40),wxSize(150,20));
	floatingPointMax->SetFont(secondFont);

	floatMaxText = new wxTextCtrl(floatingPoint, wxID_ANY,"",wxPoint(1000,38),wxSize(60,20));
	floatMaxText->SetFont(secondFont);

	floatingPointAvg = new wxStaticText(floatingPoint, wxID_ANY, "Average number of Clocks :", wxPoint(450,70),wxSize(150,20));
	floatingPointAvg->SetFont(secondFont);

	floatAvgText = new wxTextCtrl(floatingPoint,wxID_ANY,"",wxPoint(700,68),wxSize(60,20));
	floatAvgText->SetFont(secondFont);

	memSpeedText = new wxStaticText(memSpeedPage, wxID_ANY, "MEMORY TRANSFER SPEED SECTION", wxPoint(490, 10), wxSize(200,20));
	memSpeedText->SetFont(secondFont);

	AverageSpeed = new wxStaticText(memSpeedPage, wxID_ANY, "Average Transfer Speed per block :", wxPoint(430, 60), wxSize(100, 20));
	AverageSpeed->SetFont(secondFont);

	averageSpeedText = new wxTextCtrl(memSpeedPage, wxID_ANY, "", wxPoint(745, 58), wxSize(60, 20));
	averageSpeedText->SetFont(secondFont);

	totalTime = new wxStaticText(memSpeedPage, wxID_ANY, "Total clocks :", wxPoint(525, 90), wxSize(50, 20));
	totalTime->SetFont(secondFont);

	totalTimeText = new wxTextCtrl(memSpeedPage, wxID_ANY, "", wxPoint(660, 88), wxSize(60, 20));
	totalTimeText->SetFont(secondFont);






	timer = new wxTimer(this,10002);

}

cMain::~cMain() 
{
}


void cMain::realTimeFunctionExec(wxTimerEvent& evt) {

	cpuLoadText->SetLabel(CpuLoadFunction()+"%");
	memLoadText->SetLabel(memoryLoadFunction()+"%");
	availMemText->SetLabel(remainingMemFunction()+" MB");
	totalPageFileText->SetLabel(totalPageFileFunction()+" MB");
	availPageFileText->SetLabel(remainingPageFileFunction() + " MB");
	totalVirtualMemText->SetLabel(totalVirtualMemFunction() + " MB");
	availVirtualMemText->SetLabel(remainingVirtualMemFunction() + " MB");

}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{

	cpuNameText->SetLabel(cpuNameFunction());
	nrOfProcText->SetLabel(nrOfProcFunction());
	cpuArchitectureText->SetLabel(cpuArchitectureNrFunction());
	cpuArchitectureDef->SetLabel(cpuArchitectureFunction());
	cpuTypeText->SetLabel(cpuTypeNr());
	cpuTypeDef->SetLabel(cpuTypeFunction());

	totalMemText->SetLabel(totalMemFunction()+" MB");
	pageFileText->SetLabel(pageFileFunction()+ " Bytes");
	cout << "START PROGRAM";


	timer->Start(500);

}
void cMain::NextPageButtonClicked(wxCommandEvent& evt) {
	
	constDataPanel->Show(false);
	realTimeDataPanel->Show(false);
	nextPage->Show(false);
	secondPage->Show(true);
	floatingPoint->Show(true);
	memSpeedPage->Show(true);



}

void cMain::BackToFirstPageButtonClicked(wxCommandEvent& evt) {
	secondPage->Show(false);
	floatingPoint->Show(false);
	memSpeedPage->Show(false);
	constDataPanel->Show(true);
	realTimeDataPanel->Show(true);
	nextPage->Show(true);
}
void cMain::OpButtonClicked(wxCommandEvent& evt) {
	nrOfTimes = wxAtoi(nrOfTimesArithAndLogText->GetValue());
	string Result = transferDataFunction(nrOfTimes);
	string avgRes;
	string totalRes;
	int pos = 0;
	for (int i = 0; i < Result.length(); i++) {
		if (Result[i] != ' ') {
			if (pos == 0)
				totalRes = totalRes + Result[i];
			else
				avgRes = avgRes + Result[i];
		}
		else {
			pos++;
		}

	}
	totalTimeText->SetLabel(totalRes);
	averageSpeedText->SetLabel(avgRes);

}

void cMain::ChoiceClicked(wxCommandEvent& evt) {
	
	int choice = selectionBar->GetSelection();
	string Result,ResultFloat;
	if (choices->Item(choice) == "ADD") {
		 Result = addFunction(nrOfTimes);
		 ResultFloat = floatAddFunction(nrOfTimes);
	}
	if (choices->Item(choice) == "SUB") {
		 Result = subFunction(nrOfTimes);
		 ResultFloat = floatSubFunction(nrOfTimes);
	}
	
	if (choices->Item(choice) == "AND") {
		 Result = andFunction(nrOfTimes);
		 
	}
	
	if (choices->Item(choice) == "MUL") {
		 Result = mulFunction(nrOfTimes);	
		 ResultFloat = floatMulFunction(nrOfTimes);
	}
	
	if (choices->Item(choice) == "DIV") {
		 Result = divFunction(nrOfTimes);
		 ResultFloat = floatDivFunction(nrOfTimes);
	}
	
	if (choices->Item(choice) == "OR") {
		 Result = orFunction(nrOfTimes);
	}

	string firstOper;
	string minOper;
	string maxOper;
	string avgOper;
	int pos=0;
	for (int i = 0; i < Result.length(); i++) {
		if (Result[i] != ' ') {
			if(pos==0)
				firstOper = firstOper + Result[i];
			if (pos == 1)
				minOper = minOper + Result[i];
			if (pos == 2)
				maxOper = maxOper + Result[i];
			if (pos == 3)
				avgOper = avgOper + Result[i];
		}
		else {
			pos++;
		}
		
	}
	firstOperationText->SetLabel(firstOper);
	minOperationText->SetLabel(minOper);
	maxOperationText->SetLabel(maxOper);
	avgOperationText->SetLabel(avgOper);

	string floatFirstOper;
	string floatMinOper;
	string floatMaxOper;
	string floatAvgOper;
	pos = 0;
	for (int i = 0; i < ResultFloat.length(); i++) {
		if (ResultFloat[i] != ' ') {
			if (pos == 0)
				floatFirstOper = floatFirstOper + ResultFloat[i];
			if (pos == 1)
				floatMinOper = floatMinOper + ResultFloat[i];
			if (pos == 2)
				floatMaxOper = floatMaxOper + ResultFloat[i];
			if (pos == 3)
				floatAvgOper = floatAvgOper + ResultFloat[i];
		}
		else {
			pos++;
		}
	}
	floatFirstText->SetLabel(floatFirstOper);
	floatMinText->SetLabel(floatMinOper);
	floatMaxText->SetLabel(floatMaxOper);
	floatAvgText->SetLabel(floatAvgOper);
}
