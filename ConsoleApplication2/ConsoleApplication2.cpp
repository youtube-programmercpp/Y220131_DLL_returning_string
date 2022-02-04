#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int 指定された桁数で１～３のみが使われた数値を出力(char s[], int 値, int 桁数)
{
	for (;;) {
		s[桁数 - 1] = 値 % 3 + '1';//「1」始まりの数字に変換（数値ではなくて数字）
		値 /= 3;
		if (--桁数 == 0)
			return 値;//0になっていることを期待
	}
}
int main()
{
	int 桁数;
	if (scanf("%d", &桁数) == 1) {
		if (1 <= 桁数 && 桁数 <= 10) {
			char s[10 + 1];
			s[桁数] = '\0';
			for (int 値 = 0; 指定された桁数で１～３のみが使われた数値を出力(s, 値, 桁数) == 0; ++値)
				printf("%s\n", s);
		}
	}
}