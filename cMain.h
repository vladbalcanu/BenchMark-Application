#pragma once
#include "wx/wx.h"

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton* start_button = nullptr;
	wxButton* nextPageButton = nullptr;
	wxButton* backToFirstPageButton = nullptr;
	wxButton* startButtonOp = nullptr;




	wxStaticText* cpuName = nullptr;
	wxStaticText* numberOfProcessors = nullptr;
	wxStaticText* totalMem = nullptr;
	wxStaticText* MemMB = nullptr;
	wxStaticText* pageFile = nullptr;
	wxStaticText* cpuType = nullptr;
	wxStaticText* cpuArchitecture = nullptr;
	wxTextCtrl* cpuArchitectureText = nullptr;
	wxTextCtrl* cpuArchitectureDef = nullptr;
	wxTextCtrl* cpuTypeDef = nullptr;
	wxTextCtrl* totalMemText = nullptr;
	wxTextCtrl* nrOfProcText = nullptr;
	wxTextCtrl* cpuNameText = nullptr;
	wxTextCtrl* pageFileText = nullptr;
	wxTextCtrl* cpuTypeText = nullptr;
	wxListBox* list_box = nullptr;
	wxTextCtrl* text = nullptr;
	wxStaticText* cpuLoad = nullptr;
	wxTextCtrl* cpuLoadText = nullptr;
	wxTimer* timer = nullptr;
	wxStaticText* memLoad = nullptr;
	wxTextCtrl* memLoadText = nullptr;
	wxStaticText* availMem = nullptr;
	wxTextCtrl* availMemText = nullptr;
	wxStaticText* totalPageFile = nullptr;
	wxTextCtrl* totalPageFileText = nullptr;
	wxStaticText* availPageFile = nullptr;
	wxTextCtrl* availPageFileText = nullptr;
	wxStaticText* totalVirtualMem = nullptr;
	wxTextCtrl* totalVirtualMemText = nullptr;
	wxStaticText* availVirtualMem = nullptr;
	wxTextCtrl* availVirtualMemText = nullptr;
	wxStaticText* nrOfTimesArithAndLog = nullptr;
	wxTextCtrl* nrOfTimesArithAndLogText = nullptr;
	wxTextCtrl* totalResultOp = nullptr;
	wxChoice* selectionBar = nullptr;
	wxArrayString* choices = nullptr;
	wxStaticText* firstOperation = nullptr;
	wxStaticText* minOperation = nullptr;
	wxStaticText* maxOperation = nullptr;
	wxStaticText* avgOperation = nullptr;
	wxStaticText* integerOperations = nullptr;
	wxTextCtrl* firstOperationText = nullptr;
	wxTextCtrl* minOperationText = nullptr;
	wxTextCtrl* maxOperationText = nullptr;
	wxTextCtrl* avgOperationText = nullptr;
	wxStaticText* floatingPointText = nullptr;
	wxStaticText* floatingPointFirst = nullptr;
	wxStaticText* floatingPointMin = nullptr;
	wxStaticText* floatingPointMax = nullptr;
	wxStaticText* floatingPointAvg = nullptr;
	wxTextCtrl* floatFirstText = nullptr;
	wxTextCtrl* floatMinText = nullptr;
	wxTextCtrl* floatMaxText = nullptr;
	wxTextCtrl* floatAvgText = nullptr;
	wxStaticText* memSpeedText = nullptr;
	wxStaticText* AverageSpeed = nullptr;
	wxTextCtrl* averageSpeedText = nullptr;
	wxStaticText* totalTime = nullptr;
	wxTextCtrl* totalTimeText = nullptr;


	wxPanel* constDataPanel = nullptr;
	wxPanel* realTimeDataPanel = nullptr;
	wxPanel* nextPage = nullptr;
	wxPanel* secondPage = nullptr;
	wxPanel* floatingPoint = nullptr;
	wxPanel* memSpeedPage = nullptr;


	void OnButtonClicked(wxCommandEvent& evt);
	void realTimeFunctionExec(wxTimerEvent& evt);
	void NextPageButtonClicked(wxCommandEvent& evt);
	void BackToFirstPageButtonClicked(wxCommandEvent& evt);
	void OpButtonClicked(wxCommandEvent& evt);
	void ChoiceClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

