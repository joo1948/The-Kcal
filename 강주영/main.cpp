#pragma once
#pragma warning(disable : 4996)

#include "TheKcal.h"


int main()
{
	
	system("title The kcal");
	system("mode con: cols=70 lines=30");//창 위치 조절(칸/행 ( 가로 ), 줄/열 ( 세로 )

	TheKcal kcal(22, 15);
	kcal.CursorView(0);
	kcal.inputId(); //옵션 선택 하기


}