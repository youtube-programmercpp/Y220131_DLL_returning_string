#include <iostream>
#include <Windows.h>
#include <OleAuto.h>
extern "C" LPSTR __stdcall f5(int 値, int 桁数);
#pragma comment(lib, "Dll1.lib")
#include <memory> //std::unique_ptr

#include <string>
std::string convert_to_string(std::unique_ptr<char, decltype(CoTaskMemFree)*>&& s)
{
	const auto p = &*s;
	if (const auto length = lstrlenA(p))
		return { p, static_cast<size_t>(length) };
	else
		return { };
}
int main()
{
	int 桁数;
	if (std::cin >> 桁数) {
		if (1 <= 桁数 && 桁数 <= 10) {
			for (int 値 = 0; ; ++値) {
				const auto s = convert_to_string(std::unique_ptr<char, decltype(CoTaskMemFree)*>{ f5(値, 桁数), CoTaskMemFree});
				if (s.empty())
					break;
				else
					std::cout << s << '\n';
			}
		}
	}
}
