#pragma once
#pragma warning(disable : 4996)

#include "TheKcal.h"

int ex_c, savecal,n3;


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

	ofstream fout("member.txt");
	gotoxy(x -10, y);
	cout << "id�� �Է��ϼ���.";
	textcolor(14);
	/*gotoxy(x +5, y);
	cout << " (9���� ���Ϸ� ��������.)";*/
	textcolor(14);
	gotoxy(x -10, y + 3);
	cout << ">> ";
	textcolor(15);
	cin >> id;
	if (id == "joo1948") { admire(); }
	int width = sizeof(id) / sizeof(string);
	cout.width(width);
	fout << id <<endl;
	choose_number(); 
}

void TheKcal::admire() {
	x = 22;
	y = 15;

	start2_display();
	
	gotoxy(x-1, y - 5);
	textcolor(15);
	cout << "    --������ ������--" << endl;

	gotoxy(x, y);
	cout << ">";
	gotoxy(x, y);
	cout << "���� ����";
	gotoxy(x, y + 1);
	cout << "�޸� �ϱ�";
	gotoxy(x, y + 2);
	cout << "�޸� ����";
	gotoxy(x, y + 3);
	cout << "TheKcal ����";
	int k = key();
	if(k==0) showadmire(k);//���� ����� ����
	else if (k == 1) wirtememo();//�޸� ����� ����
	else if (k == 2) readmemo();//�޸� ����� ����
	else if (k == 3) menuDraw();//����ȭ������ ����

}
void TheKcal::showadmire(int k) {

	string empid;
	string emptalk;

	system("cls");
	start2_display();

	ifstream review;

	review.open("review.txt");

	gotoxy(x + 2, y - 8);
	cout << "�������亸�⢾��";
	gotoxy(x - 10, y-5);
	textcolor(14);
	cout << " ID";
	gotoxy(x+3 , y - 5);
	textcolor(14);
	cout << "���䳻��";

	int j = 2;
	if (k == 0) {
		
		while (review >> empid >> emptalk/*>> empreview*/) {
			textcolor(15);
			gotoxy(x - 10, y - j);
			cout << empid << "\t" << emptalk << endl/*<< empreview << setw(20) */;
			j -= 3;

		}

		review.close();
	}

	system("pause>null");
	
	showadmire_1();
}
void TheKcal::showadmire_1() {
	string empid;
	string emptalk;

	system("cls");
	start2_display();

	ifstream review;

	review.open("review_2.txt");

	gotoxy(x + 2, y - 8);
	cout << "�������亸�⢾��";
	gotoxy(x - 10, y - 5);
	textcolor(14);
	cout << " ID";
	gotoxy(x + 3, y - 5);
	textcolor(14);
	cout << "���䳻��";

	int j = 2;

		while (review >> empid >> emptalk/*>> empreview*/) {
			textcolor(15);
			gotoxy(x - 10, y - j);
			cout << empid << "\t" << emptalk << endl/*<< empreview << setw(20) */;
			j -= 3;

		}

	
		review.close();
	
		gotoxy(x + 30, y + 9);
		textcolor(13);
		cout << "��";
		textcolor(15);
	system("pause>null");

	admire();
}
void TheKcal::wirtememo() {
	system("cls");
	start2_display();//�׸� �ڽ� �θ���

	gotoxy(20,8);
	textcolor(14);
	cout << "   --�޸� �ϱ�--";
	textcolor(15);
	gotoxy(12, 12);
	cout << "�� �Է� �Ͽ����� Enter �� SpaceŰ..";


	char memo[90];

	ofstream fout("memo.txt",ios::app);
	
	if (!fout) {
		cerr << "���� ���� ����" << endl;
		exit(1);
	}

	gotoxy(13, 17);
	cout << "->";
	cin >> memo;
	
	fout << memo << endl;

	system("pause>null");


	admire();
	
}
void TheKcal::readmemo() {

	system("cls");
	start2_display();

	string memo;

	ifstream readmemo;

	readmemo.open("memo.txt");

	gotoxy(20, 8);
	textcolor(14);
	cout << "     --�޸� ����--";
	
	int j = 0;
	while (readmemo>>memo) {
		textcolor(15);
		gotoxy(x+4 , 13+j );
		cout << memo <<"\t" << endl;
		j+=2;
	}

	readmemo.close();

	system("pause>null");
	admire();
}
int TheKcal::menuDraw()
{
	start2_display();//�׸� �ڽ� �θ���

	gotoxy(27, 8);
	//for (int i = 0; i < 15; i++) {
		textcolor(15);
	//}
	cout << "+The Kcal+" << endl;

	gotoxy(25, 10);
	textcolor(14);
	cout << "[ SpaceŰ ]" << endl;
	gotoxy(20, 12);
	textcolor(14);
	cout << "[ wŰ(UP) , sŰ(DOWN) ]" << endl;

	this->x = 22;
	this->y = 15;

	textcolor(15);
	gotoxy(x, y);
	cout << "Ű ������ �Է�" << endl;
	gotoxy(x, y + 1);
	cout << "��ǥ Į�θ� �Ҹ� �Է�" << endl;
	gotoxy(x, y + 2);
	cout << "���� ����" << endl;
	gotoxy(x, y + 3);
	cout << "Į�θ� �Ҹ��� �� ����" << endl;

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
			//���� ���� ���� & � �ð�
			savefoodKcal();
		}
		else if (menuCode == 3) {
			//Į�θ� �Ҹ� ����
			minus_kcal();
		}
	}
}

void TheKcal::input() {
	//�׸� �ڽ� 
	start2_display();

	//Ű ������ �Է� & ��� ������ ������ �ϱ� - 150~160����
	int tall[7][5] = { {150,151,152,153,154},{155,156,157,158,159},{160,161,162,163,164},{165,166,167,168,169},
	{170,171,172,173,174}, {175,176,177,178,179},{180, } };
	int height = 0;
	int weight = 0;
	gotoxy(11, 9);
	textcolor(14);
	cout << "�ڡڡ�";
	gotoxy(17, 9);
	textcolor(15);
	cout << "Ű&�����Ը� ������ �Է��ϼ���.";
	gotoxy(47,9);
	textcolor(14);
	cout<<"�ڡڡ�";
	textcolor(15);
	gotoxy(20, 13);
	cout << "Ű�� �Է��ϼ���. : ";
	cin >> height;
	gotoxy(20, 16);
	cout << "�����Ը� �Է��ϼ���. : ";
	cin >> weight;


	for (int j = 0; j < 5; j++) {
		if (tall[0][j] == height) {//150~154
			gotoxy(20, 19); textcolor(15); cout << "����� Ű : " << tall[0][j] << endl;
			gotoxy(20, 21); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 23); textcolor(14); cout << "ǥ�� ������ : 49kg" << endl;
		}
		else if (tall[1][j] == height) {//155~160
			gotoxy(20, 19); textcolor(15); cout << "����� Ű : " << tall[1][j] << endl;
			gotoxy(20, 21); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 23); textcolor(14); cout << "ǥ�� ������ : 52kg" << endl;
		}
		else if (tall[2][j] == height) {//160~164
			gotoxy(20, 19); textcolor(15); cout << "����� Ű : " << tall[2][j] << endl;
			gotoxy(20, 21); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 23); textcolor(14); cout << "ǥ�� ������ : 54kg" << endl;
		}
		else if (tall[3][j] == height) {//165~170
			gotoxy(20, 19); textcolor(15); cout << "����� Ű : " << tall[3][j] << endl;
			gotoxy(20, 21); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 23); textcolor(14); cout << "ǥ�� ������ : 57kg" << endl;
		}
		else if (tall[4][j] == height) {//171 ~ 180
			gotoxy(20, 19); textcolor(15); cout << "����� Ű : " << tall[4][j] << endl;
			gotoxy(20, 21); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 23); textcolor(14); cout << "ǥ�� ������ : 62kg" << endl;
		}
		else if (tall[5][j] == height) {//180~
			gotoxy(20, 19); textcolor(15); cout << "����� Ű : " << tall[5][j] << endl;
			gotoxy(20, 21); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 23); textcolor(14); cout << "ǥ�� ������ : 64kg" << endl;
		}		
		if (height < 150 || height > 180) {
			gotoxy(20, 19); textcolor(15); cout << "����� Ű : " << tall[5][j] << endl;
			gotoxy(20, 21); cout << "����� ������ : " << weight << endl;
			gotoxy(20, 23); textcolor(14); cout << "������ ������ �����ϴ�." << endl;
		}
	}
		system("pause>null");
}
void TheKcal::inputWantCal() {
	int n2;
	//���ϴ� Į�θ� �Ҹ� �Է�
	
	start2_display();

	ofstream fout("minusKcal.txt");
	gotoxy(x-8, y-3);
	cout << "���ϴ� Į�θ� �Ҹ��� �Է��ϼ���.(����)" << endl;
	gotoxy(x-8, y-1);
	cout << ">>>";
	cin >> n2;
	fout << n2 << setw(4) << endl;

	
	gotoxy(x-8,y+1);
	cout << "���ϴ� Į�θ� �Ҹ� --> ";
	textcolor(14);
	gotoxy(x+17, y +1);
	cout << n2;
	gotoxy(x + 22, y + 1);
	textcolor(15);
	cout<<"kcal" << endl;
	system("pause>null");
}
int TheKcal::eatfood() {
	start2_display();
	gotoxy(x -4, y-6);
	cout << "���� ���� ������ �������ּ���~!" << endl;
	gotoxy(x+2, y - 2);
	cout << ">";
	gotoxy(x+2, y - 2);
	cout << "�б� �޽�";
	gotoxy(x+2, y - 1);
	cout << "������";
	gotoxy(x+2, y);
	cout << "�Ƹ�����";
	gotoxy(x+2, y + 1);
	cout << "�н�";
	
	int k = key();
	
	return k;

}
int TheKcal::savefoodKcal() {
	int cal = eatfood();
	
	savecal = 0;
	switch (cal) {
	case 0: savecal = 500; break;
	case 1: savecal = 351; break;
	case 2: savecal = 270; break;
	case 3: savecal = 500; break;
		}

	ex_c = chooseSports();
	if (ex_c == 0 || ex_c == 1 || ex_c == 2 || ex_c == 3)
		ex_mathod(savecal);

	return savecal;
}
int TheKcal::chooseSports() {//�����
	x = 22;
	y = 15;
	start2_display();

	/*string n;
	system("cls");
	start2_display();
	gotoxy(x + 2,y-4);
	cout << "��� �ϼ̽��ϱ�?    (y/n)";
	gotoxy(x + 2, y - 2);
	cout << ">>";
	cin >> n;
	if (n == "n") menuDraw();

	system("cls");
	start2_display();
	*/
	gotoxy(x - 4, y - 4);
	cout << "���� �� ��� �������ּ���~!" << endl;
	gotoxy(x+2, y);
	cout << "����� �";
	gotoxy(x+2, y+1);
	cout << "�ٷ� �";
	gotoxy(x+2, y+2);
	cout << "��Ʈ��Ī";
	gotoxy(x+2, y + 3);
	cout << "�ϻ��Ȱ �";

	int k = key();
	return k;
}

void TheKcal::ex_mathod(int countcal) {
	int n2;
	string str;
	string id;
	int htime;
	int countcal_1 = countcal;//���� ���� Į�θ�

	system("cls");
	start2_display();
	gotoxy(x+2, y-5 );
	textcolor(13);
	cout << "���Է��ϼ���.��" << endl;

	gotoxy(x-5, y-1);
	textcolor(15);
	cout << "(1) ~15��" << "     " << " (2)15~30�� �̻�";
	gotoxy(x-5, y+1);
	cout << "(3) 1�ð�" << "      " << "(4)2�ð�";
	gotoxy(x-5, y+3);
	textcolor(13);
	cout << ">> ";
	textcolor(15);
	cin >> htime;
	
	ifstream memberfin;
	ifstream minusKcalfin;

	memberfin.open("member.txt");
	minusKcalfin.open("minusKcal.txt");

	memberfin >> id;
	minusKcalfin >> n2;

	system("cls");
	start2_display();
		switch (htime) {
			x = 22;
			y = 15;
		case 1:
			gotoxy(x - 4, y );
			cout << id << setw(1) << "�� " << "� 15���ϼ̽��ϴ�.";
			gotoxy(x - 4, y + 2);
			textcolor(13);
			cout << "~150";
			n3 = 150;
			textcolor(15);
			gotoxy(x,y+2);
			cout<<" Į�θ� �Ҹ� �Ͽ����ϴ�."; break;
		case 2:
			gotoxy(x - 4, y);
			cout << id << setw(1) << "�� " << "� 30���ϼ̽��ϴ�.";
			gotoxy(x - 4, y + 2);
			textcolor(13);
			cout << "~300~500";
			n3 = 450;
			textcolor(15);
			gotoxy(x, y + 2);
			cout << " Į�θ� �Ҹ� �Ͽ����ϴ�."; break;
		case 3:
			gotoxy(x - 4, y);
			cout << id << setw(1) << "�� " << "� 1�ð��ϼ̽��ϴ�.";
			gotoxy(x - 4, y + 2);
			textcolor(13);
			cout << "507";
			n3 = 507;
			textcolor(15);
			gotoxy(x , y + 2);
			cout << " Į�θ� �Ҹ� �Ͽ����ϴ�."; break;
		case 4:
			gotoxy(x - 4, y);
			cout << id << setw(1) << "�� " << "� 2�ð��ϼ̽��ϴ�.";
			gotoxy(x - 4, y + 2);
			textcolor(13);
			cout << "1000";
			n3 = 1000;
			textcolor(15);
			gotoxy(x, y + 2);
			cout << " Į�θ� �Ҹ� �Ͽ����ϴ�."; break;
		}
	system("pause>null");
}

void TheKcal::minus_kcal(){
	int n2;
	string id;
	start2_display();
	
	

	ifstream memberfin;
	ifstream minusKcalfin;

	memberfin.open("member.txt");
	minusKcalfin.open("minusKcal.txt");

	memberfin >> id;
	minusKcalfin >> n2;

	int total = n2-n3;
	if (total < 0) total = 0;

	gotoxy(x-2, y-8);
	cout << id << setw(1) << "��!! ";
	gotoxy(x-2, y-6);
	cout << "Į�θ� �Ҹ� ��ǥ : ";
	textcolor(14);
	gotoxy(x + 19, y - 6);
	cout<< n2 << setw(4);
	gotoxy(x-2, y - 4);
	textcolor(15);
	cout << "���� Į�θ� : ";
	gotoxy(x + 13, y - 4);
	textcolor(14);
	cout<< savecal;
	gotoxy(x-2, y - 2);
	textcolor(15);
	cout << "� �� Į�θ� �Ҹ� : ";
	gotoxy(x + 22, y - 2);
	textcolor(14);
	cout<< n3;
	gotoxy(x-2, y);
	textcolor(15);
	cout << "���� Į�θ� �� : ";
	gotoxy(x + 16, y);
	textcolor(14);
	cout<< total;

	system("pause>null");

}
//=====================================================================================

void TheKcal::gotoxy(int x, int y){
	{
		COORD Cur = { (short)x-1,(short)y-1 };

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
	x = 22;
	y = 15;
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