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

/* 함수 선언 */
int keyControl();
void start2_display(void);
int menuDraw();
void gotoxy(int x, int y);//좌표 이동시키기
void choose_number();
void input();
int chooseSports();
void timeKcal();
void inputWantCal();
void ex_mathod();//운동 몇분했니? 무슨 운동했니?
void CursorView(char show); //커서 숨기기
void textcolor(int color_number);//텍스트 컬러 조절
int key();//키 값 컨트롤하기

int x = 22;
int y = 15;
int ex_c;

class time{
public:
	void timeKcal(){
		cout << "선택하셨습니다." << endl;
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
	system("mode con: cols=70 lines=30");//창 위치 조절(칸/행 ( 가로 ), 줄/열 ( 세로 )
	
	CursorView(0);
	choose_number(); //옵션 선택 하기


}
int keyControl() {
	char temp = (char)getch();

	if (temp == 'w' || temp == 'W') return UP;
	else if (temp == 's' || temp == 'S') return DOWN;
	else if (temp == ' ') return SUBMIT;

}
int menuDraw()
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
	gotoxy(x, y+1);
	cout << "목표 칼로리 소모량 입력" << endl;
	gotoxy(x, y+2); 
	cout << "운동 선택" << endl;
	gotoxy(x, y+3);
	cout << "종료" << endl;

	int k = key();
	
	return k;
}

void choose_number() {
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
			if (ex_c == 0||ex_c==1||ex_c==2||ex_c==3)
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

void input() {
	//네모 박스 
	start2_display();

	//키 몸무게 입력 & 평균 몸무게 나오게 하기 - 150~160까지
	int tall[][5] = { {0,1,2,3,4},{5,6,7,8,9},{10,11,12,13,14},{15,16,17,18,19},{20,21,22,23,24}, {25,26,27,28,29}};
	int height = 0, weight = 0;
	gotoxy(20, 11);
	cout << "키를 입력하세요. : ";
	cin >> height;
	gotoxy(20, 13);
	cout << "몸무게를 입력하세요. : ";
	cin >> weight;

	int h = height % 150;

		for (int j = 0; j <6; j++) {
			if (tall[1][j] == h) {
				gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
				gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 52kg" << endl;
			}else if (tall[2][j] == h) {gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
				gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 54kg" << endl;
			}else if (tall[3][j] == h) {gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
				gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 57kg" << endl;
			}else if(tall[4][j]==h){ gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
				gotoxy(20, 19); cout << "당신의 몸무게 : " << weight << endl;
				gotoxy(20, 21); textcolor(14); cout << "표준 몸무게 : 62kg" << endl;
			}else if(tall[5][j]==h){ gotoxy(20, 17); textcolor(15); cout << "당신의 키 : " << height << endl;
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
void inputWantCal() {
	//원하는 칼로리 소모량 입력
	start2_display();

	int n2;//원하는 칼로리 소모량 입력받기
	gotoxy(8, 12);
	cout << "원하는 칼로리 소모량을 입력하세요.(숫자)" << endl;
	gotoxy(8, 14);
	cout << ">>>";
	cin >> n2;
	
	system("pause>>null");

}
int chooseSports() {//운동선택
	start2_display();
	
	gotoxy(x, y - 2);
	cout << ">";
	gotoxy(x, y-2);
	cout << "유산소 운동";
	gotoxy(x,y-1);
	cout << "근력 운동";
	gotoxy(x, y);
	cout << "스트레칭";
	gotoxy(x, y+1);
	cout << "일상생활 운동";

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
	case 0:cout << "어떤 유산소 운동을 하셨나요? >> "; break;
	case 1:cout << "어떤 근력 운동을 하셨나요? >> "; break;
	case 2:cout << "어떤 스트레칭을 하셨나요? >> "; break;
	case 3:cout << "어떤 일상 운동을 하셨나요? >> "; break;
	}
	getline(cin, str);//문자열 입력받기

	system("cls");
	start2_display();
	gotoxy(x, y - 2);
	cout << "얼마나 하였나요? ";
	gotoxy(x, y);
	cout << "시간"<<endl;
	gotoxy(x, y + 1);
	cout << "분" << endl;

	int cou = key();

	system("pause>null");//이거 수정하자~~

	//cin >> m;//
	//timeKcal(min);
	//이후 db연결해야해요
}

void timeKcal(int min) {

	//이 함수를클래스에 넣고 오버로딩 시키기-->나중에

}



//=====================================================================================

void gotoxy(int x, int y) {//좌표 이동시키기
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show)//커서숨기기
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



void textcolor(int color_number) //텍스트 칼라를 바꿔주는 함수
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