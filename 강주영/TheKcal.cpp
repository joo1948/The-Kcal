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
	cout << "id를 입력하세요.";
	textcolor(14);
	gotoxy(x +8, y);
	cout << " (8글자 이하로 적으세요.)";
	textcolor(15);
	gotoxy(x -10, y + 3);
	cout << ">>";
	cin >> id;
	int width = sizeof(id) / sizeof(string);
	cout.width(width);
	fout << id << setw(2)<<endl;
	choose_number(); 
}

int TheKcal::menuDraw()
{
	start2_display();//네모 박스 부르기

	gotoxy(27, 8);
	cout << "+The Kcal+" << endl;

	gotoxy(25, 10);
	textcolor(14);
	cout << "[ Space키 ]" << endl;
	gotoxy(20, 12);
	textcolor(14);
	cout << "[ w키(UP) , s키(DOWN) ]" << endl;

	this->x = 22;
	this->y = 15;

	textcolor(15);
	gotoxy(x, y);
	cout << "키 몸무게 입력" << endl;
	gotoxy(x, y + 1);
	cout << "목표 칼로리 소모량 입력" << endl;
	gotoxy(x, y + 2);
	cout << "먹은 음식" << endl;
	gotoxy(x, y + 3);
	cout << "칼로리 소모한 양 보기" << endl;

	int k = key();

	return k;
}
void TheKcal::choose_number() {
	textcolor(15);
	while (1) {
		int menuCode = menuDraw(); //시작 화면
		if (menuCode == 0) {
			//키 몸무게 입력
			input();
		}
		else if (menuCode == 1) {
			//목표 칼로리 소모량 입력
			inputWantCal();
		}
		else if (menuCode == 2) {
			//먹은 음식 보기 & 운동 시간
			savefoodKcal();
		}
		else if (menuCode == 3) {
			//칼로리 소모량 보기
			minus_kcal();
		}
	}
}

void TheKcal::input() {
	//네모 박스 
	start2_display();

	//키 몸무게 입력 & 평균 몸무게 나오게 하기 - 150~160까지
	int tall[][5] = { {0,1,2,3,4},{5,6,7,8,9},{10,11,12,13,14},{15,16,17,18,19},{20,21,22,23,24}, {25,26,27,28,29} };
	int height = 0, weight = 0;
	gotoxy(20, 11);
	cout << "키를 입력하세요. : ";
	cin >> height;
	gotoxy(20, 13);
	cout << "몸무게를 입력하세요. : ";
	cin >> weight;

	int h = height % 150;

	for (int j = 0; j < 6; j++) {
		if (tall[0][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
			gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 49kg" << endl;
		}
		else if (tall[1][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
			gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 52kg" << endl;
		}
		else if (tall[2][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
			gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 54kg" << endl;
		}
		else if (tall[3][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
			gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 57kg" << endl;
		}
		else if (tall[4][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
			gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 62kg" << endl;
		}
		else if (tall[5][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
			gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 64kg" << endl;
		}
		else if (tall[6][j] == h) {
			gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
			gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
			gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 68kg" << endl;
		}		
	}

	system("pause>null");
}
void TheKcal::inputWantCal() {
	int n2;
	//원하는 칼로리 소모량 입력
	
	start2_display();

	ofstream fout("minusKcal.txt");
	gotoxy(x-14, y-3);
	cout << "원하는 칼로리 소모량을 입력하세요.(숫자)" << endl;
	gotoxy(x-14, y-1);
	cout << ">>>";
	cin >> n2;
	fout << n2 << setw(4) << endl;

	
	gotoxy(x-14,y+1);
	cout << "원하는 칼로리 소모량 --> ";
	textcolor(14);
	gotoxy(x +12, y +1);
	cout << n2 << endl;
	system("pause>null");
}
int TheKcal::eatfood() {
	start2_display();

	gotoxy(x, y - 2);
	cout << ">";
	gotoxy(x, y - 2);
	cout << "학교 급식";
	gotoxy(x, y - 1);
	cout << "지지고";
	gotoxy(x, y);
	cout << "아마스빈";
	gotoxy(x, y + 1);
	cout << "분식";
	
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
int TheKcal::chooseSports() {//운동선택
	x = 22;
	y = 15;
	start2_display();

	gotoxy(x, y);
	cout << ">";
	gotoxy(x, y);
	cout << "유산소 운동";
	gotoxy(x, y+1);
	cout << "근력 운동";
	gotoxy(x, y+2);
	cout << "스트레칭";
	gotoxy(x, y + 3);
	cout << "일상생활 운동";

	int k = key();
	return k;
}

void TheKcal::ex_mathod(int countcal) {
	int n2;
	string str;
	string id;
	int htime;
	int countcal_1 = countcal;//먹은 음식 칼로리

	system("cls");
	start2_display();
	gotoxy(x-9, y-8 );
	textcolor(13);
	cout << "입력하세요." << endl;

	gotoxy(x-9, y-6);
	textcolor(15);
	cout << "(1) ~15분" << "     " << "(2)15~30분 이상";
	gotoxy(x-9, y-4);
	cout << "(3) 1시간" << "      " << "(4)2시간";
	gotoxy(x-9, y -2);
	cout << ">>";
	cin >> htime;
	
	ifstream memberfin;
	ifstream minusKcalfin;

	memberfin.open("member.txt");
	minusKcalfin.open("minusKcal.txt");

	memberfin >> id;
	minusKcalfin >> n2;

		switch (htime) {
		case 1:
			gotoxy(x - 14, y );
			cout << id << setw(1) << "님 " << "운동 15분하셨습니다.";
			gotoxy(x - 14, y + 2);
			textcolor(13);
			cout << "~150";
			n3 = 150;
			textcolor(15);
			gotoxy(x-10,y+2);
			cout<<" 칼로리 소모 하였습니다."; break;
		case 2:
			gotoxy(x - 14, y);
			cout << id << setw(1) << "님 " << "운동 30분하셨습니다.";
			gotoxy(x - 14, y + 2);
			textcolor(13);
			cout << "~300~500";
			n3 = 450;
			textcolor(15);
			gotoxy(x - 10, y + 2);
			cout << " 칼로리 소모 하였습니다."; break;
		case 3:
			gotoxy(x - 14, y);
			cout << id << setw(1) << "님 " << "운동 1시간하셨습니다.";
			gotoxy(x - 14, y + 2);
			textcolor(13);
			cout << "507";
			n3 = 507;
			textcolor(15);
			gotoxy(x - 10, y + 2);
			cout << " 칼로리 소모 하였습니다."; break;
		case 4:
			gotoxy(x - 14, y);
			cout << id << setw(1) << "님 " << "운동 2시간하셨습니다.";
			gotoxy(x - 14, y + 2);
			textcolor(13);
			cout << "1000";
			n3 = 1000;
			textcolor(15);
			gotoxy(x - 10, y + 2);
			cout << " 칼로리 소모 하였습니다."; break;
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

	gotoxy(x, y-8);
	cout << id << setw(1) << "님!! ";
	gotoxy(x, y-6);
	cout << "칼로리 소모량 목표 : " << n2 << setw(4);
	gotoxy(x, y - 4);
	cout << "음식 칼로리 : " << savecal;
	gotoxy(x, y - 2);
	cout << "운동 후 칼로리 소모량 : " << n3;
	gotoxy(x, y);
	cout << "남은 칼로리 양 : " << total;

	system("pause>null");

}
//=====================================================================================

void TheKcal::gotoxy(int x, int y){
	{
		COORD Cur = { (short)x-1,(short)y-1 };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	} 
}

void TheKcal::CursorView(char show)//커서숨기기
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
	cout << a << b[4]; //ㄱ

	cout << endl;
	for (int i = 1; i <= 20; i++) {//공백 주는 칸
		cout << "     ";
		cout << a << b[2];
		for (int j = 1; j <= 50; j++) cout << " ";
		cout << a << b[2] << endl;
	}

	cout << endl;
	gotoxy(6, 26);
	cout << a << b[6]; //ㄴ
	for (int i = 1; i <= 50; i++) cout << a << b[1];
	cout << a << b[5]; //l
	cout << endl;
	cout << endl;
}
void TheKcal::textcolor(int color_number) //텍스트 칼라를 바꿔주는 함수
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