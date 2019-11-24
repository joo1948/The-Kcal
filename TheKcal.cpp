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
	cout << "id를 입력하세요. >> ";
	cin >> id;
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

	textcolor(15);
	gotoxy(x, y);
	cout << "키 몸무게 입력" << endl;
	gotoxy(x, y + 1);
	cout << "목표 칼로리 소모량 입력" << endl;
	gotoxy(x, y + 2);
	cout << "운동 시간" << endl;
	gotoxy(x, y + 3);
	cout << "종료" << endl;

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
			//운동 선택
			ex_c = chooseSports();
			if (ex_c == 0 || ex_c == 1 || ex_c == 2 || ex_c == 3)
				ex_mathod();
			//여기는 이제 db로 넣을 곳 ex) 유산소 운동 - 자전거 - 30분
		}
		else if (menuCode == 3) {
			//종료
			gotoxy(100, 100);
			exit(0);
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
		if (tall[1][j] == h) {
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
		else {
			gotoxy(20, 21);
			textcolor(15);
			cout << "저장되어 있는 데이터가 없습니다." << endl;
		}
	}
	system("pause>null");
}
void TheKcal::inputWantCal() {
	//원하는 칼로리 소모량 입력
	start2_display();

	int n2;//원하는 칼로리 소모량 입력받기
	gotoxy(8, 12);
	cout << "원하는 칼로리 소모량을 입력하세요.(숫자)" << endl;
	gotoxy(8, 14);
	cout << ">>>";
	cin >> n2;
	//여기서 DB 
	//***님의 원하느 칼로리 소모량은 *** 입니다. 뜨게 하기
	system("pause>>null");

}
int TheKcal::chooseSports() {//운동선택
	start2_display();

	gotoxy(x, y - 2);
	cout << ">";
	gotoxy(x, y - 2);
	cout << "유산소 운동";
	gotoxy(x, y - 1);
	cout << "근력 운동";
	gotoxy(x, y);
	cout << "스트레칭";
	gotoxy(x, y + 1);
	cout << "일상생활 운동";

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
	case 0:cout << "어떤 유산소 운동을 하셨나요? >> "; break;
	case 1:cout << "어떤 근력 운동을 하셨나요? >> "; break;
	case 2:cout << "어떤 스트레칭을 하셨나요? >> "; break;
	case 3:cout << "어떤 일상 운동을 하셨나요? >> "; break;
	}
*/
	system("cls");
	start2_display();
	gotoxy(x-9, y );
	textcolor(13);
	cout << "입력하세요." << endl;

	gotoxy(x-9, y+3);
	textcolor(15);
	cout << "(1) ~15분" << "     " << "(2)15~30분 이상";
	gotoxy(x-9, y+5);
	cout << "(3) 1시간" << "      " << "(4)2시간";
	gotoxy(x-9, y + 7);
	cout << ">>";
	cin >> htime;
	
	switch (htime) {
	case 1 :
		cout << " **** 님 ***운동 15분 ~150칼로리 소모 하였습니다."; break;
	case 2 :
		cout << " **** 님 ***운동 30~분 300칼로리 소모 하였습니다."; break;
	case 3:
		cout << " **** 님 ***운동 1시간 ~557칼로리 소모 하였습니다."; break;
	case 4:
		cout << " **** 님 ***운동 2시간 1000칼로리 소모 하였습니다."; break;
	}
	//여기 db해서 15분 했으면 ***님 **운동 **분 ~150칼로리소모 하였습니다.
	//30~시간 했으면 300~500칼로리 소모 하였습니다. 출력창 나오게 하기

	//1시간 했으면 557칼로리칼로리 소모하였습니다.
	//2시간 했으면 1000칼로리 이상 소모하였습니다. 출력창 나오게 하기
	system("pause>null");
}
//=====================================================================================

void TheKcal::gotoxy(int x, int y){
	{
		COORD Cur = { x-1,y-1 };

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