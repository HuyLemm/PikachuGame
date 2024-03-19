#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// func to delete fullscreen more smoothly
void clrs()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 1;
	Position.Y = 1;
	SetConsoleCursorPosition(hOut, Position);
}

//func to help us able to allocate where output should print
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;
	SetConsoleCursorPosition(hStdout, Position);
}

//func to set color wherever we want
void set_color(int code)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}

//func to set default color
void setcolor()
{
	system("color 4");
}

BOOL WINAPI SetConsoleTitle(
	_In_ LPCTSTR lpConsoleTitle
);

//func to hide mouse pointer
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

//func to set size of console
void SetFont()
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 1000;
	fontex.dwFontSize.X = 60;
	fontex.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}
//draw outline playing board
void DrawLine(int n)
{
	set_color(4);
	GoTo(70, 4);
	cout << "Hint: 5";
	set_color(15);
	GoTo(40, 6);
	cout << char(218);
	for (int i = 0; i < n - 1; ++i)
		cout << char(196) << char(196) << char(196) << char(194);
	cout << char(196) << char(196) << char(196) << char(191);
	for (int i = 0; i < n - 1; ++i)
	{
		GoTo(40, 2 * i + 8);
		cout << char(195);
		for (int j = 0; j < n - 1; ++j)
			cout << char(196) << char(196) << char(196) << char(197);
		cout << char(196) << char(196) << char(196) << char(180);
	}
	GoTo(40, 2 * n + 6);
	cout << char(192);
	for (int i = 0; i < n - 1; ++i)
		cout << char(196) << char(196) << char(196) << char(193);
	cout << char(196) << char(196) << char(196) << char(217);
}

//draw gamemode board
void drawgamemode1()
{
	set_color(6);
	GoTo(48, 8);
	cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
	for (int i = 0; i < 6; i++)
	{
		GoTo(48, 9 + i * 2);
		cout << "|";
		GoTo(71, 9 + i * 2);
		cout << "|";
	}
	GoTo(48, 10);
	cout << char(195) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(180);
	for (int i = 1; i < 5; i++)
	{
		GoTo(48, 10 + i * 2);
		cout << char(195) << "----------------------" << char(180);
	}
	GoTo(48, 20);
	cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);
}

//draw gamemode board
void drawgamemode2()
{
	set_color(6);
	GoTo(48, 8);
	cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
	for (int i = 0; i < 8; i++)
	{
		GoTo(48, 9 + i * 2);
		cout << "|";
		GoTo(71, 9 + i * 2);
		cout << "|";
	}
	GoTo(48, 10);
	cout << char(195) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(180);
	for (int i = 1; i < 7; i++)
	{
		GoTo(48, 10 + i * 2);
		cout << char(195) << "----------------------" << char(180);
	}
	GoTo(48, 24);
	cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);
}

void drawmenu()
{
	set_color(11);
	GoTo(82, 2);
	cout << "PIKACHUGAME<3";
	set_color(15);
	GoTo(73, 4);
	cout << char(218);
	GoTo(73, 5);
	cout << "|";
	GoTo(73, 6);
	cout << "|";
	GoTo(74, 4);
	cout << "|";
	GoTo(102, 4);
	cout << char(191);
	GoTo(102, 5);
	cout << "|";
	GoTo(102, 6);
	cout << "|";
	GoTo(74, 4);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(191);
	for (int i = 0; i < 4; i++)
	{
		GoTo(73, 8 + i * 2);
		cout << "|";
		GoTo(102, 8 + i * 2);
		cout << "|";
	}
	GoTo(73, 7);
	cout << char(195) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(180);
	for (int i = 1; i < 4; i++)
	{
		GoTo(73, 7 + i * 2);
		cout << char(195) << "----------------------------" << char(180);
	}
	GoTo(74, 18);
	cout << char(218) << "----------------------------";
	GoTo(74, 19);
	cout << char(124);
	GoTo(73, 15);
	cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);
}

void printpikachu()
{
	set_color(4);
	cout << "                             (%#####&/                                     " << endl;
	cout << "                      ######################.                              " << endl;
	cout << "                   #########################%%%%%                          " << endl;
	cout << "               *  ##########################%%%%%&%/                       " << endl;
	cout << "                 ###########################%%%%%&%%%                      " << endl;
	cout << "                 ################%%%%%%%%%%%%,%%%%%%%%/                     " << endl;
	cout << "                 ##########%%%%%%@##&&%%%%%%%%%%%#%%%%                     " << endl;
	cout << "             (   ######";
	set_color(6);
	cout << ",,,,,................. / ...";
	set_color(4);
	cout << "& %%%%" << endl;
	cout << "             * .%%";
	set_color(6);
	cout << ",,...";
	set_color(8);
	cout << "@";
	set_color(15);
	cout << "##";
	set_color(8);
	cout << "@";
	set_color(6);
	cout << "...........";
	set_color(8);
	cout << "@";
	set_color(15);
	cout << "##";
	set_color(8);
	cout << "@";
	set_color(6);
	cout << "........ ";
	set_color(4);
	cout << " & %" << endl;
	cout << "              #%";
	set_color(6);
	cout << "........";
	set_color(8);
	cout << "@@";
	set_color(6);
	cout << ".............";
	set_color(8);
	cout << "@@";
	set_color(6);
	cout << "......, .....";
	set_color(4);
	cout << "#                     " << endl;
	cout << "           #%%%";
	set_color(6);
	cout << "(..";
	set_color(4);
	cout << "####";
	set_color(6);
	cout << "........";
	set_color(8);
	cout << char(31);
	set_color(6);
	cout << "................";
	cout << "#";
	cout << ".....";
	set_color(4);
	cout << "#                    " << endl;
	cout << "        ##%%%%%";
	set_color(6);
	cout << "...";
	set_color(4);
	cout << "###*";
	set_color(6);
	cout << "....";
	set_color(8);
	cout << "@";
	set_color(6);
	cout << "..";
	set_color(8);
	cout << "@@";
	set_color(6);
	cout << "..";
	set_color(8);
	cout << "@";
	set_color(6);
	cout << ".....";
	set_color(4);
	cout << "#####";
	set_color(6);
	cout << ".... .....";
	set_color(8);
	cout << "(" << endl;
	set_color(4);
	cout << "      #%%%%%%%%%";
	set_color(8);
	cout << "@";
	set_color(6);
	cout << "*.........";
	set_color(8);
	cout << "@@";
	set_color(6);
	cout << "..";
	set_color(8);
	cout << "@@";
	set_color(6);
	cout << ".......";
	set_color(4);
	cout << "#####";
	set_color(6);
	cout << "....  ";
	set_color(8);
	cout << "#(";
	cout << "@@@@                 " << endl;
	set_color(4);
	cout << "    ##%%%%%%%%%%";
	set_color(8);
	cout << "@@@";
	set_color(4);
	cout << "%";
	set_color(6);
	cout << ".............................. ";
	cout << " / ";
	set_color(8);
	cout << "  @@@@                  " << endl;
	set_color(4);
	cout << "    ##%%%%%%%%%%";
	set_color(8);
	cout << "@@";
	set_color(4);
	cout << " % %%%%";
	set_color(6);
	cout << "..........................,,,... ";
	cout << " / @. % " << endl;
	set_color(4);
	cout << "      #%%%%%%%%%";
	set_color(8);
	cout << "@";
	set_color(4);
	cout << " % %%%%";
	set_color(6);
	cout << "(........,,,,,,, ..........,,,,,,,,,,......(" << endl;
	set_color(4);
	cout << "        #%%%%%%%%%%%%";
	set_color(6);
	cout << "................(.........,.,,,,,,,,,,,,,,.......*    " << endl;
	cout << "                    %...............#.........,,.,,,,,,,,,,,,,,,,,,,,..    " << endl;
	cout << "                    .,.............,........,,/,*.,,,/ #,,,,,,,,,,,,,#     " << endl;
	cout << "                   #..*........#...........,,,,,, ,,,,      #,,,,,,,       " << endl;
	cout << "                   ............#..,.......,/,,,,,(,,,,          *,*        " << endl;
	cout << "                  /......#...............,...,,,,,(,,,(                    " << endl;
	cout << "                  ...........................,,,,,                         " << endl;
	cout << "                 /,..........................,,,,,#                        " << endl;
	cout << "                  ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,                         " << endl;
	cout << "                   %,,,,,,,,,,,,,,,,,,,,,,,,,,,,                           " << endl;
	cout << "                   (,,,,,,,            /(**(*,,                            " << endl;
	cout << "                 ,*,,,,,                  ,,,,,,,,                         " << endl;
	cout << "                 .                             #,(%                      " << endl;
}

