#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

#define UP 0
#define DOWN 1
#define SUBMIT 4

/* �Լ� ���� */
int keyControl();
void start2_display(void);
int menuDraw();
void gotoxy(int x, int y);//��ǥ �̵���Ű��
void choose_number();
void input();
int chooseSports();
void timeKcal();
void inputWantCal();
void ex_mathod();//� ����ߴ�? ���� ��ߴ�?
void CursorView(char show); //Ŀ�� �����
void textcolor(int color_number);//�ؽ�Ʈ �÷� ����
int key();//Ű �� ��Ʈ���ϱ�

int x = 22;
int y = 15;
int ex_c;

class time{
public:
	void timeKcal(){
		cout << "�����ϼ̽��ϴ�." << endl;
	}

};

class hour : time {
public:
	int h;
	void hourKcal() {
		switch (h) {
		case 1: 
		}
	}
};

int main()
{
	system("title The kcal");
	system("mode con: cols=70 lines=30");//â ��ġ ����(ĭ/�� ( ���� ), ��/�� ( ���� )
	
	CursorView(0);
	choose_number(); //�ɼ� ���� �ϱ�


}
int keyControl() {
	char temp = (char)getch();

	if (temp == 'w' || temp == 'W') return UP;
	else if (temp == 's' || temp == 'S') return DOWN;
	else if (temp == ' ') return SUBMIT;

}
int menuDraw()
{
	start2_display();//�׸� �ڽ� �θ���

	gotoxy(27, 8);
	cout << "+The Kcal+" << endl;
	
	gotoxy(25, 10);
	textcolor(14);
	cout << "[ SpaceŰ ]" << endl;
	gotoxy(20, 12);
	textcolor(14);
	cout << "[ wŰ(UP) , sŰ(DOWN) ]" << endl;

	textcolor(15);
	gotoxy(x, y);
	cout << "Ű ������ �Է�" << endl;
	gotoxy(x, y+1);
	cout << "��ǥ Į�θ� �Ҹ� �Է�" << endl;
	gotoxy(x, y+2); 
	cout << "� ����" << endl;
	gotoxy(x, y+3);
	cout << "����" << endl;

	int k = key();
	
	return k;
}

void choose_number() {
	textcolor(15);
	while (1) {  
		int menuCode = menuDraw(); //���� ȭ��
		if (menuCode == 0) {
			//Ű ������ �Է�
			input();
		}
		else if (menuCode == 1) {
			//��ǥ Į�θ� �Ҹ� �Է�
			inputWantCal();
			
		}
		else if (menuCode == 2) {
			//� ����
			ex_c = chooseSports();
			if (ex_c == 0||ex_c==1||ex_c==2||ex_c==3)
				ex_mathod();
				//����� ���� db�� ���� �� ex) ����� � - ������ - 30��
			}
		else if (menuCode == 3) {
			//����
			gotoxy(100, 100);
			exit(0);
		}
	}
}

void input() {
	//�׸� �ڽ� 
	start2_display();

	//Ű ������ �Է� & ��� ������ ������ �ϱ� - 150~160����
	int tall[][5] = { {0,1,2,3,4},{5,6,7,8,9},{10,11,12,13,14},{15,16,17,18,19},{20,21,22,23,24}, {25,26,27,28,29}};
	int height = 0, weight = 0;
	gotoxy(20, 11);
	cout << "Ű�� �Է��ϼ���. : ";
	cin >> height;
	gotoxy(20, 13);
	cout << "�����Ը� �Է��ϼ���. : ";
	cin >> weight;

	int h = height % 150;

		for (int j = 0; j <6; j++) {
			if (tall[1][j] == h) {
				gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
				gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 52kg" << endl;
			}else if (tall[2][j] == h) {gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
				gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 54kg" << endl;
			}else if (tall[3][j] == h) {gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
				gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 57kg" << endl;
			}else if(tall[4][j]==h){ gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
				gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 62kg" << endl;
			}else if(tall[5][j]==h){ gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
				gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 64kg" << endl;
			}
			else if (tall[6][j] == h) {
				gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
				gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 68kg" << endl;
			}
		}
	system("pause>null");
}
void inputWantCal() {
	//���ϴ� Į�θ� �Ҹ� �Է�
	start2_display();

	int n2;//���ϴ� Į�θ� �Ҹ� �Է¹ޱ�
	gotoxy(8, 12);
	cout << "���ϴ� Į�θ� �Ҹ��� �Է��ϼ���.(����)" << endl;
	gotoxy(8, 14);
	cout << ">>>";
	cin >> n2;
	
	system("pause>>null");

}
int chooseSports() {//�����
	start2_display();
	
	gotoxy(x, y - 2);
	cout << ">";
	gotoxy(x, y-2);
	cout << "����� �";
	gotoxy(x,y-1);
	cout << "�ٷ� �";
	gotoxy(x, y);
	cout << "��Ʈ��Ī";
	gotoxy(x, y+1);
	cout << "�ϻ��Ȱ �";

	int k = key();
	return k;
}

void ex_mathod() {

	system("cls");
	start2_display();

	string str,min,hour;
	int m;

	gotoxy(x-9, y);
	switch (ex_c) {
	case 0:cout << "� ����� ��� �ϼ̳���? >> "; break;
	case 1:cout << "� �ٷ� ��� �ϼ̳���? >> "; break;
	case 2:cout << "� ��Ʈ��Ī�� �ϼ̳���? >> "; break;
	case 3:cout << "� �ϻ� ��� �ϼ̳���? >> "; break;
	}
	getline(cin, str);//���ڿ� �Է¹ޱ�

	system("cls");
	start2_display();
	gotoxy(x, y - 2);
	cout << "�󸶳� �Ͽ�����? ";
	gotoxy(x, y);
	cout << "�ð�"<<endl;
	gotoxy(x, y + 1);
	cout << "��" << endl;

	int cou = key();

	system("pause>null");//�̰� ��������~~

	//cin >> m;//
	//timeKcal(min);
	//���� db�����ؾ��ؿ�
}

void timeKcal(int min) {

	//�� �Լ���Ŭ������ �ְ� �����ε� ��Ű��-->���߿�

}



//=====================================================================================

void gotoxy(int x, int y) {//��ǥ �̵���Ű��
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show)//Ŀ�������
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void start2_display() {
	textcolor(15);
	unsigned char a = 0xa6, b[7], i;

	for (i = 1; i < 7; i++) b[i] = 0xa0 + i;

	gotoxy(6, 5);
	cout << a << b[3]; //r
	for (int i = 1; i <= 50; i++) cout << a << b[1]; //-
	cout << a << b[4]; //��

	cout << endl;
	for (int i = 1; i <= 20; i++) {//���� �ִ� ĭ
		cout << "     ";
		cout << a << b[2];
		for (int j = 1; j <= 50; j++) cout << " ";
		cout << a << b[2] << endl;
	}

	cout << endl;
	gotoxy(6, 26);
	cout << a << b[6]; //��
	for (int i = 1; i <= 50; i++) cout << a << b[1];
	cout << a << b[5]; //l
	cout << endl;
	cout << endl;
}



void textcolor(int color_number) //�ؽ�Ʈ Į�� �ٲ��ִ� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

int key() {
	textcolor(10);
	gotoxy(x-2, y);
	cout << ">";
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 15) {
				gotoxy(x - 2, y);
				textcolor(10);
				printf(" ");
				gotoxy(x - 2, --y);
				textcolor(10);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 18) {
				gotoxy(x - 2, y);
				textcolor(10);
				printf(" ");
				gotoxy(x - 2, ++y);
				textcolor(10);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 15;
		}
		}
	}


	system("pause>null");


}