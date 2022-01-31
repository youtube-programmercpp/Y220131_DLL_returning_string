#include <Windows.h>
int main()
{
	const auto length1 = wcslen  (L"ABCDEF");//戻り値：size_t, ライブラリ関数
	const auto length2 = lstrlenW(L"ABCDEF");//戻り値：int   , Windows API   
}
