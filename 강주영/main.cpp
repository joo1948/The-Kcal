#pragma once
#pragma warning(disable : 4996)

#include "TheKcal.h"


int main()
{
	
	system("title The kcal");
	system("mode con: cols=70 lines=30");//â ��ġ ����(ĭ/�� ( ���� ), ��/�� ( ���� )

	TheKcal kcal(22, 15);
	kcal.CursorView(0);
	kcal.inputId(); //�ɼ� ���� �ϱ�


}