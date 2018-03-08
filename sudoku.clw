; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSudokuDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "sudoku.h"

ClassCount=3
Class1=CSudokuApp
Class2=CSudokuDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SUDOKU_DIALOG

[CLS:CSudokuApp]
Type=0
HeaderFile=sudoku.h
ImplementationFile=sudoku.cpp
Filter=N

[CLS:CSudokuDlg]
Type=0
HeaderFile=sudokuDlg.h
ImplementationFile=sudokuDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON2

[CLS:CAboutDlg]
Type=0
HeaderFile=sudokuDlg.h
ImplementationFile=sudokuDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SUDOKU_DIALOG]
Type=1
Class=CSudokuDlg
ControlCount=3
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_BUTTON2,button,1342242816
Control3=IDC_BUTTON3,button,1342242816

