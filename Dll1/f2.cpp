#include "pch.h"
#include <combaseapi.h>
extern "C" __declspec(dllexport) LPSTR __stdcall f2(LPCSTR pszText)
{
	const auto pfn = CoTaskMemFree;// 【デバッグ用】CoTaskMemFree 関数のアドレスを確認
	const auto cbText = lstrlenA(pszText);
	if (const auto p = static_cast<LPSTR>(CoTaskMemAlloc(cbText + 1))) {
		CopyMemory(p, pszText, cbText);
		p[cbText] = '\0';
		_strlwr(p);
		return p;
	}
	else
		return nullptr;
}
