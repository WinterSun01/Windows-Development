#include<Windows.h>
#include<cstdio>
#include"resource.h"

CONST CHAR* values[] = { "This", "is", "my", "first", "Combo", "Box" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	MessageBox(NULL, "Check", "Check", MB_OK | MB_ICONINFORMATION);
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
		for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
		{
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)values[i]);
		}
	}
	break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
			case IDOK:
			{
				HWND hCombo = GetDlgItem(hwnd, IDC_COMBO);
				INT i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
				
				if(i == CB_ERR)
				MessageBox(hwnd, "��� ������ �������� ��� �����", "Warning", MB_OK | MB_ICONWARNING);
			else
			{	 
				CONST INT SIZE = 256;
				CHAR sz_buffer[SIZE]{};
				CHAR sz_message[SIZE]{};
				SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_buffer);
				sprintf(sz_message, "�� ������� ����� N%i �� ��������� %s", i, sz_buffer);
				MessageBox(hwnd, sz_message, "Your choice", MB_OK | MB_ICONINFORMATION);
			}    

		}	
			break;

			case IDCANCEL: EndDialog(hwnd,0);
	    }
		break;

	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;
}