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
