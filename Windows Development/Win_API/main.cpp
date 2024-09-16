#include <Windows.h>
#include "resource.h"

CONST CHAR g_sz_INVITATION[] = "������� ���� ���";

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
		SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
	
	HWND hEditLogin = GetDlgItem (hwnd, IDC_EDIT_LOGIN);
	SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_INVITATION);
	//SetFocus(hEditLogin);
	//SetFocus(GetDlgItem(hwnd, IDC_EDIT_LOGIN));
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE]{};
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);

		if (HIWORD(wParam) == EN_SETFOCUS && strcmp(sz_buffer, g_sz_INVITATION) == 0)
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");

		if (HIWORD(wParam) == EN_KILLFOCUS && strlen(sz_buffer) == 0)
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_INVITATION);

		}
		break;

		case IDC_BUTTON_COPY:
		{
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE]{};
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
		break;
		case IDOK:MessageBox(hwnd, "���� ������ ������ OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:EndDialog(hwnd, 0);		break;
		}
		break;

	case WM_CLOSE:
		EndDialog(hwnd, 0); break;
	}
	return FALSE;
}
