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

#define UP 0
#define DOWN 1
#define SUBMIT 4

class TheKcal{
private:
	int x;
	int y;
	int ex_c;
public:
	TheKcal(int x, int y);
	int keyControl();
	void start2_display(void);
	int menuDraw();
	void inputId();
	void gotoxy(int x, int y);//��ǥ �̵���Ű��
	void choose_number();
	void input();
	int chooseSports();
	void inputWantCal();
	int eatfood();//���� ���� ����~~?
	int savefoodKcal();//���� ���� Į�θ� ����
	void ex_mathod(int countcal);//���� ��ߴ�?
	void minus_kcal();//Į�θ� �Ҹ��� �� ����
	void CursorView(char show); //Ŀ�� �����
	void textcolor(int color_number);//�ؽ�Ʈ �÷� ����
	int key();//Ű �� ��Ʈ���ϱ�



};

#endif CHOOSEEX_H


