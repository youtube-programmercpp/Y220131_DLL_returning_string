#include "pch.h"
#include <combaseapi.h>
extern "C" __declspec(dllexport) LPSTR __stdcall f2(LPCSTR pszText)
{
	const auto pfn = CoTaskMemFree;// �y�f�o�b�O�p�zCoTaskMemFree �֐��̃A�h���X���m�F
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
