#pragma once
#pragma warning(disable : 4996)

#include "TheKcal.h"


int ex_c;

TheKcal::TheKcal(int x, int y) {
	this->x = x;
	this->y = y;
}

int TheKcal::keyControl() {
	char temp = (char)getch();

	if (temp == 'w' || temp == 'W') return UP;
	else if (temp == 's' || temp == 'S') return DOWN;
	else if (temp == ' ') return SUBMIT;
}
void TheKcal::inputId() {
	string id;
	textcolor(15);
	start2_display();
	gotoxy(x - 1, y);
	cout << "id�� �Է��ϼ���. >> ";
	cin >> id;
	choose_number();
}
int TheKcal::menuDraw()
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
	gotoxy(x, y + 1);
	cout << "��ǥ Į�θ� �Ҹ� �Է�" << endl;
	gotoxy(x, y + 2);
	cout << "� �ð�" << endl;
	gotoxy(x, y + 3);
	cout << "����" << endl;

	int k = key();

	return k;
}
void TheKcal::choose_number() {
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
			if (ex_c == 0 || ex_c == 1 || ex_c == 2 || ex_c == 3)
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

void TheKcal::input() {
	//�׸� �ڽ� 
	start2_display();

	//Ű ������ �Է� & ��� ������ ������ �ϱ� - 150~160����
	int tall[][5] = { {0,1,2,3,4},{5,6,7,8,9},{10,11,12,13,14},{15,16,17,18,19},{20,21,22,23,24}, {25,26,27,28,29} };
	int height = 0, weight = 0;
	gotoxy(20, 11);
	cout << "Ű�� �Է��ϼ���. : ";
	cin >> height;
	gotoxy(20, 13);
	cout << "�����Ը� �Է��ϼ���. : ";
	cin >> weight;

	int h = height % 150;

	for (int j = 0; j < 6; j++) {
		if (tall[1][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
			gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 52kg" << endl;
		}
		else if (tall[2][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
			gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 54kg" << endl;
		}
		else if (tall[3][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
			gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 57kg" << endl;
		}
		else if (tall[4][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
			gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 62kg" << endl;
		}
		else if (tall[5][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
			gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 64kg" << endl;
		}
		else if (tall[6][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "����� Ű : " << height << endl;
			gotoxy(20, 19); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "ǥ�� ������ : 68kg" << endl;
		}
		else {
			gotoxy(20, 21);
			textcolor(15);
			cout << "����Ǿ� �ִ� �����Ͱ� �����ϴ�." << endl;
		}
	}
	system("pause>null");
}
void TheKcal::inputWantCal() {
	//���ϴ� Į�θ� �Ҹ� �Է�
	start2_display();

	int n2;//���ϴ� Į�θ� �Ҹ� �Է¹ޱ�
	gotoxy(8, 12);
	cout << "���ϴ� Į�θ� �Ҹ��� �Է��ϼ���.(����)" << endl;
	gotoxy(8, 14);
	cout << ">>>";
	cin >> n2;
	//���⼭ DB 
	//***���� ���ϴ� Į�θ� �Ҹ��� *** �Դϴ�. �߰� �ϱ�
	system("pause>>null");

}
int TheKcal::chooseSports() {//�����
	start2_display();

	gotoxy(x, y - 2);
	cout << ">";
	gotoxy(x, y - 2);
	cout << "����� �";
	gotoxy(x, y - 1);
	cout << "�ٷ� �";
	gotoxy(x, y);
	cout << "��Ʈ��Ī";
	gotoxy(x, y + 1);
	cout << "�ϻ��Ȱ �";

	int k = key();
	return k;
}

void TheKcal::ex_mathod() {

	string str;
	int htime;

	/*system("cls");
	start2_display();

	gotoxy(x - 9, y);
	switch (ex_c) {
	case 0:cout << "� ����� ��� �ϼ̳���? >> "; break;
	case 1:cout << "� �ٷ� ��� �ϼ̳���? >> "; break;
	case 2:cout << "� ��Ʈ��Ī�� �ϼ̳���? >> "; break;
	case 3:cout << "� �ϻ� ��� �ϼ̳���? >> "; break;
	}
*/
	system("cls");
	start2_display();
	gotoxy(x-9, y );
	textcolor(13);
	cout << "�Է��ϼ���." << endl;

	gotoxy(x-9, y+3);
	textcolor(15);
	cout << "(1) ~15��" << "     " << "(2)15~30�� �̻�";
	gotoxy(x-9, y+5);
	cout << "(3) 1�ð�" << "      " << "(4)2�ð�";
	gotoxy(x-9, y + 7);
	cout << ">>";
	cin >> htime;
	
	switch (htime) {
	case 1 :
		cout << " **** �� ***� 15�� ~150Į�θ� �Ҹ� �Ͽ����ϴ�."; break;
	case 2 :
		cout << " **** �� ***� 30~�� 300Į�θ� �Ҹ� �Ͽ����ϴ�."; break;
	case 3:
		cout << " **** �� ***� 1�ð� ~557Į�θ� �Ҹ� �Ͽ����ϴ�."; break;
	case 4:
		cout << " **** �� ***� 2�ð� 1000Į�θ� �Ҹ� �Ͽ����ϴ�."; break;
	}
	//���� db�ؼ� 15�� ������ ***�� **� **�� ~150Į�θ��Ҹ� �Ͽ����ϴ�.
	//30~�ð� ������ 300~500Į�θ� �Ҹ� �Ͽ����ϴ�. ���â ������ �ϱ�

	//1�ð� ������ 557Į�θ�Į�θ� �Ҹ��Ͽ����ϴ�.
	//2�ð� ������ 1000Į�θ� �̻� �Ҹ��Ͽ����ϴ�. ���â ������ �ϱ�
	system("pause>null");
}
//=====================================================================================

void TheKcal::gotoxy(int x, int y){
	{
		COORD Cur = { x-1,y-1 };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	}
}

void TheKcal::CursorView(char show)//Ŀ�������
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
void TheKcal::start2_display() {
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
void TheKcal::textcolor(int color_number) //�ؽ�Ʈ Į�� �ٲ��ִ� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
int TheKcal::key() {
	textcolor(10);
	gotoxy(x - 2, y);
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