//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    send_smsg.h ���Ű���
//    added by hejizhe 2011-09-13
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "smsg_common.h"


#define caojie 1201
#define back 1202
static CTRLDATA CtrlInitHelpProgress [] =
{ 

	{
		"static",
		WS_VISIBLE |  SS_LEFT,
		10, 100, 300, 300,
		caojie,
		"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tǶ��ʽB��\n\t\t\t\tGSMģ��J5ƬѡCSO,J4��������MCU",
		0
	},
	
	
	{
		"button",
		WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON, 
		130, 385, 60, 25,
		back, 
		"ȷ��",
		0
	},
   
};

static DLGTEMPLATE DlgInitHelpProgress =
{
    WS_BORDER | WS_CAPTION, 
    WS_EX_NONE,
    160, 0, 320, 480, 
    "����",
    0, 0,
    2, NULL,
    0
};
static int InitDialogHelpBoxProc (HWND hDlg, int message, WPARAM wParam, LPARAM lParam)
{
	switch (message) 
	{
	case MSG_INITDIALOG:
		return 1;
	case MSG_COMMAND:
		switch(wParam)
		{
			case back:
				EndDialog( hDlg, wParam);
				return 1;
		}

	 
		  
	}
	return DefaultDialogProc (hDlg, message, wParam, lParam);

}

static void InitDialogHelpBox (HWND hWnd)
{
	DlgInitHelpProgress.controls = CtrlInitHelpProgress;
		
		DialogBoxIndirectParam (&DlgInitHelpProgress, hWnd, InitDialogHelpBoxProc, 0);

}



static void HELP_SMSG(HWND hWnd)
{
	InitDialogHelpBox(hWnd);
}

