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
	
	void admire();//������
	void showadmire(int k);//������ ���� ���� 1
	void showadmire_1();//������ ���� ���� 2
	void wirtememo();//������ �޸��ϱ�
	void readmemo();//������ �޸� ����
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


