#include <iostream>
#include "Background.h"
#include "Leaderboard.h"
#include "Randomboard.h"
#include "Menu.h"
using namespace std;
int main()
{
	SetFont();
	ShowCur(0);
	SetConsoleTitle(TEXT("Game Pikachu"));
	setcolor();
	menu();
	return 0;
}