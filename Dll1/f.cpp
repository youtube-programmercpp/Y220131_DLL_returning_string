#include "pch.h"
#include <OleAuto.h>
extern "C" __declspec(dllexport) BSTR __stdcall f(LPCWSTR pszText)
{
	if (const auto bstrText = SysAllocString(pszText)) {
		_wcslwr(bstrText);
		return bstrText;
	}
	else
		return nullptr;
}
#include <exception>
extern "C" __declspec(dllexport) LPWSTR __stdcall f2(LPCWSTR pszText)
{
	try {
		const auto cchText = lstrlenW(pszText);
		const auto p = new wchar_t[cchText + 1];
		CopyMemory(p, pszText, cchText * sizeof * p);
		p[cchText] = L'\0';
		_wcslwr(p);
		return p;
	}
	catch (const std::exception& e) {
		OutputDebugStringA(e.what());
		OutputDebugStringA("\n");
		return nullptr;
	}
}
