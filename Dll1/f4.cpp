#include "pch.h"
#include <OleAuto.h>
#include <sstream>

static BSTR MakeBSTR(LPCCH lpMultiByteStr, int cbMultiByte)
{
	const auto cchWideChar = cbMultiByte;
	if (auto bstrText = SysAllocStringLen(nullptr, cchWideChar)) {
		const auto cchResult = MultiByteToWideChar
		( /*_In_                                     UINT   CodePage      */CP_ACP
		, /*_In_                                     DWORD  dwFlags       */0
		, /*_In_NLS_string_(cbMultiByte)             LPCCH  lpMultiByteStr*/lpMultiByteStr
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


#include <exception>
extern "C" __declspec(dllexport) BSTR __stdcall f4(LPCWCH lpWideCharStr)
{
	try {
		const auto cchWideChar = lstrlenW(lpWideCharStr);
		const auto cbMultiByte = 2 * cchWideChar;

		std::string s(cbMultiByte, '\0');
		s.resize(WideCharToMultiByte
		( /*_In_                                           UINT   CodePage         */CP_ACP
		, /*_In_                                           DWORD  dwFlags          */0
		, /*_In_NLS_string_(cchWideChar)                   LPCWCH lpWideCharStr    */lpWideCharStr
		, /*_In_                                           int    cchWideChar      */cchWideChar
		, /*_Out_writes_bytes_to_opt_(cbMultiByte, return) LPSTR  lpMultiByteStr   */&s.front()
		, /*_In_                                           int    cbMultiByte      */cbMultiByte
		, /*_In_opt_                                       LPCCH  lpDefaultChar    */nullptr
		, /*_Out_opt_                                      LPBOOL lpUsedDefaultChar*/nullptr
		));
		OutputDebugStringA((std::ostringstream() << "s = \"" << s << "\"\n").str().c_str());
		const auto s2 = (std::ostringstream() << "与えられた文字列は \"" << s << "\" です。\n").str();
		return MakeBSTR(s2.c_str(), static_cast<int>(s2.length()));
	}
	catch (const std::exception& e) {
		OutputDebugStringA((std::ostringstream() << "例外が発生しました。エラーメッセージ：\"" << e.what() << "\"\n").str().c_str());
		return nullptr;
	}
}
