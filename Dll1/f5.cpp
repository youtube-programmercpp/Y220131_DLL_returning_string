#include "pch.h"
int 指定された桁数で１～３のみが使われた数値を出力(char s[], int 値, int 桁数)
{
	for (;;) {
		s[桁数 - 1] = 値 % 3 + '1';//「1」始まりの数字に変換（数値ではなくて数字）
		値 /= 3;
		if (--桁数 == 0)
			return 値;//0になっていることを期待
	}
}
#include <OleAuto.h>

extern "C" __declspec(dllexport) LPSTR __stdcall f5(int 値, int 桁数)
{
	//C#, VB.NET 用の文字列を返すために CoTaskMemAlloc 関数でメモリを割り付ける
	if (const auto s = static_cast<char*>(CoTaskMemAlloc(桁数 + 1))) {
		//メモリ割り付け成功
		if (指定された桁数で１～３のみが使われた数値を出力(s, 値, 桁数) == 0) {
			//成功
			s[桁数] = '\0';//bracket 
		}
		else {
			//桁数オーバー（値が大きすぎる）
			*s = '\0';
		}
		return s;
	}
	else
		return nullptr;
}
