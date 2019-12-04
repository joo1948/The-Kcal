#pragma once
#ifndef CHOOSEEX_H
#define CHOOSEEX_H

#pragma warning(disable : 4996)
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SUBMIT 4



class TheKcal{
private:
	int x;
	int y;
	int ex_c;
public:
	
	void admire();//관리자
	void showadmire(int k);//관리자 리뷰 보기 1
	void showadmire_1();//관리자 리뷰 보기 2
	void wirtememo();//관리자 메모하기
	void readmemo();//관리자 메모 보기
	TheKcal(int x, int y);
	int keyControl();
	void start2_display(void);
	int menuDraw();
	void inputId();
	void gotoxy(int x, int y);//좌표 이동시키기
	void choose_number();
	void input();
	int chooseSports();
	void inputWantCal();
	int eatfood();//먹은 음식 뭐닝~~?
	int savefoodKcal();//먹은 음식 칼로리 저장
	void ex_mathod(int countcal);//무슨 운동했니?
	void minus_kcal();//칼로리 소모한 양 보기
	void CursorView(char show); //커서 숨기기
	void textcolor(int color_number);//텍스트 컬러 조절
	int key();//키 값 컨트롤하기



};

#endif CHOOSEEX_H


