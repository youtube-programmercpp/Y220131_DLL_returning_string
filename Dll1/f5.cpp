#include "pch.h"
int �w�肳�ꂽ�����łP�`�R�݂̂��g��ꂽ���l���o��(char s[], int �l, int ����)
{
	for (;;) {
		s[���� - 1] = �l % 3 + '1';//�u1�v�n�܂�̐����ɕϊ��i���l�ł͂Ȃ��Đ����j
		�l /= 3;
		if (--���� == 0)
			return �l;//0�ɂȂ��Ă��邱�Ƃ�����
	}
}
#include <OleAuto.h>

extern "C" __declspec(dllexport) LPSTR __stdcall f5(int �l, int ����)
{
	//C#, VB.NET �p�̕������Ԃ����߂� CoTaskMemAlloc �֐��Ń�����������t����
	if (const auto s = static_cast<char*>(CoTaskMemAlloc(���� + 1))) {
		//����������t������
		if (�w�肳�ꂽ�����łP�`�R�݂̂��g��ꂽ���l���o��(s, �l, ����) == 0) {
			//����
			s[����] = '\0';//bracket 
		}
		else {
			//�����I�[�o�[�i�l���傫������j
			*s = '\0';
		}
		return s;
	}
	else
		return nullptr;
}
