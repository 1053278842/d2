#include "pch.h"
#include "SendMsg.h"
#include <Windows.h>
#include <stdio.h>


struct wxStr
{
	wchar_t * pStr;
	int strLen;
	int strLneDouble;
};

//获取基址
DWORD GetWeChatWin() {
	return (DWORD)LoadLibrary(L"WeChatWin.dll");
}

VOID SendTextMessage(wchar_t * wxid, wchar_t * message) {
	//发送消息call
	DWORD sendCall = 0x173620 + GetWeChatWin();

	//组装数据格式

	wxStr pWxid = { 0 };
	pWxid.pStr = wxid;
	pWxid.strLen = wcslen(wxid);
	pWxid.strLneDouble = wcslen(wxid) * 2;

	wxStr pMsg = { 0 };
	pMsg.pStr = message;
	pWxid.strLen = wcslen(message);
	pWxid.strLneDouble = wcslen(message) * 2;

	/*
		win 79BB0000
		79D2384E    8D46 38         lea eax,dword ptr ds:[esi+0x38]
		79D23851    6A 01           push 0x1											1			1
		79D23853    50              push eax									； 		无			@    wxid
		79D23854    57              push edi                                 ; 	   msg 地址   		[edi] @提示
		79D23855    8D95 7CFFFFFF   lea edx,dword ptr ss:[ebp-0x84]          ; 	 对象的WXID 		edx:群号
		79D2385B    8D8D 50FCFFFF   lea ecx,dword ptr ss:[ebp-0x3B0]		 ；			  1			1
		79D23861    E8 4AAF3400     call WeChatWi.7A06E7B0
		79D23866    83C4 0C         add esp,0xC

		//@
		1749EDF8  17A627C0  ;指向@对象的wxid
		1749EDFC  17A627D4  UNICODE "额"
		1749EE00  17A627D4  UNICODE "额"
	*/
	__asm {

	}
}