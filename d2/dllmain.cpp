// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <Windows.h>
#include "resource.h"

#include "SendMsg.h"

INT_PTR Dlgproc(
	HWND unnamedParam1,
	UINT unnamedParam2,
	WPARAM unnamedParam3,
	LPARAM unnamedParam4
);
DWORD ThreadProc(HMODULE hModule);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, hModule, 0, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

DWORD ThreadProc(HMODULE hModule) {
	DialogBox(hModule, MAKEINTRESOURCE(MAIN), NULL, &Dlgproc);

}


INT_PTR Dlgproc(
	HWND hDlg,
	UINT uMsg,
	WPARAM wParam,
	LPARAM unnamedParam4
)
{
	wchar_t wxid[0x100] = { 0 };
	wchar_t message[0x300] = { 0 };
	switch (uMsg)
	{
	case WM_INITDIALOG:
		break;
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		break;
	case WM_COMMAND:
		if (wParam == SEND)
		{
			SendTextMessage(wxid,message);
		}
		break;
	default:
		break;
	}
}