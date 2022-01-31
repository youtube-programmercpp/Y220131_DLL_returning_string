#include "pch.h"
#include <OleAuto.h>
extern "C" __declspec(dllexport) BSTR __stdcall f3(LPCSTR pszText)
{
	const auto cbMultiByte = lstrlenA(pszText);
	const auto cchWideChar = cbMultiByte;
	if (auto bstrText = SysAllocStringLen(nullptr, cchWideChar)) {
		const auto cchResult = MultiByteToWideChar
		( /*_In_                                     UINT   CodePage      */CP_ACP
		, /*_In_                                     DWORD  dwFlags       */0
		, /*_In_NLS_string_(cbMultiByte)             LPCCH  lpMultiByteStr*/pszText
		, /*_In_                                     int    cbMultiByte   */cbMultiByte
		, /*_Out_writes_to_opt_(cchWideChar, return) LPWSTR lpWideCharStr */bstrText
		, /*_In_                                     int    cchWideChar   */cchWideChar
		);
		if (SysReAllocStringLen(&bstrText, nullptr, cchResult)) {
			_wcslwr(bstrText);
			return bstrText;
		}
		else {
			SysFreeString(bstrText);
			return nullptr;
		}
	}
	else
		return nullptr;
}
