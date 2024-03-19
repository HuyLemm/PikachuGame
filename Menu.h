#include <iostream>
using namespace std;

//create a menu
void menu()
{
	//PlaySound(TEXT("background.wav"), NULL,SND_ASYNC);
	printpikachu();
	drawmenu();
	int temp1;
	playerinput player;
	GoTo(86, 5);
	cout << "MENU";
	GoTo(75, 8);
	cout << "1. Play game";
	GoTo(75, 10);
	cout << "2. How to play";
	GoTo(75, 12);
	cout << "3. Leaderboard";
	GoTo(75, 14);
	cout << "4. Exit game";
	GoTo(74, 17);
	cout << "Select an option ";
	GoTo(76, 19);
	cin >> temp1;
	//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
	while (temp1 != 1 && temp1 != 2 && temp1 != 3 && temp1 != 4)
	{
		GoTo(74, 17);
		cout << "Please try again: ";
		GoTo(76, 19);
		cin >> temp1;
		//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
	}
	set_color(4);
	switch (temp1) {
	case 4:
		system("cls");
		return;
		break;
	case 2:
		clrs();
		system("cls");
		GoTo(52, 10);
		cout << "INSTRUCTION";
		set_color(15);
		GoTo(45, 12);
		cout << "1. Use W,A,S,D to move. ";
		GoTo(45, 13);
		cout << "2. Press H to use hint, P to pause game.";
		GoTo(45, 14);
		cout << "3. Press space to select cell.";
		GoTo(45, 15);
		cout << "4. Match all pairs to win.";
		set_color(6);
		GoTo(35, 17);
		cout << char(16) << "Note: In some specified modes, when connecting as a pair,";
		GoTo(30, 18);
		cout << "the column or row will slide according to the mode you choose " << char(1) << char(1) << char(1);
		cout << endl;
		system("pause");
		if (_kbhit)
		{
			//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
			set_color(4);
			system("cls");
			return menu();
			fflush(stdin);
		}
		break;
	case 1:
		clrs();
		system("cls");
		drawgamemode1();
		set_color(4);
		GoTo(56, 9);
		cout << "GAMEMODE";
		set_color(15);
		GoTo(50, 11);
		cout << "1. Easy (6x6)";
		GoTo(50, 13);
		cout << "2. Medium (8x8)";
		GoTo(50, 15);
		cout << "3. Hard (10x10) ";
		GoTo(50, 17);
		cout << "4. Return menu";
		GoTo(50, 19);
		cout << "Your option: ";
		int temp3;
		cin >> temp3;
		//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
		while (temp3 != 1 && temp3 != 2 && temp3 != 3 && temp3 != 4)
		{
			GoTo(50, 19);
			cout << "Please try again: ";
			cin >> temp3;
			//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
		}
		clrs();
		system("cls");
		int temp4, ** p, n, choice;
		if (temp3 == 1)
		{
			n = 6;
		}
		else if (temp3 == 2)
		{
			n = 8;
		}
		else if (temp3 == 3)
		{
			n = 10;
		}
		else if (temp3 == 4)
		{
			system("cls");
			fflush(stdin);
			return menu();
		}
		drawgamemode2();
		set_color(4);
		GoTo(56, 9);
		cout << "GAMEMODE";
		set_color(15);
		GoTo(50, 11);
		cout << "1. Normal ";
		GoTo(50, 13);
		cout << "2. Cells slide left ";
		GoTo(50, 15);
		cout << "3. Cells slide right ";
		GoTo(50, 17);
		cout << "4. Cells slide up ";
		GoTo(50, 19);
		cout << "5. Cells slide down ";
		GoTo(50, 21);
		cout << "6. Return menu ";
		GoTo(50, 23);
		cout << "Your option: ";
		cin >> temp4;
		//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
		while (temp4 != 1 && temp4 != 2 && temp4 != 3 && temp4 != 4 && temp4 != 5 && temp4 != 6)
		{
			GoTo(50, 23);
			cout << "Please try again: ";
			cin >> temp4;
			//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
		}
		switch (temp4)
		{
		case 1: choice = 1;
			break;
		case 2: choice = 2;
			break;
		case 3: choice = 3;
			break;
		case 4: choice = 4;
			break;
		case 5: choice = 5;
			break;
		default:
			system("cls");
			return menu();
		}
		system("cls");
		genTable(p, n);
		GameRun(p, n, choice, player);
		system("cls");
		fflush(stdin);
		menu();
		break;
	case 3:
		system("cls");
		drawgamemode1();
		set_color(4);
		GoTo(54, 9);
		cout << "LEADERBOARD";
		set_color(15);
		GoTo(50, 11);
		cout << "1. Easy (6x6)";
		GoTo(50, 13);
		cout << "2. Medium (8x8)";
		GoTo(50, 15);
		cout << "3. Hard (10x10) ";
		GoTo(50, 17);
		cout << "4. Return menu";
		GoTo(50, 19);
		cout << "Your option: ";
		int temp2;
		cin >> temp2;
		//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
		while (temp2 != 1 && temp2 != 2 && temp2 != 3 && temp2 != 4)
		{
			GoTo(50, 19);
			cout << "Please try again: ";
			cin >> temp2;
			//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
		}
		if (temp2 == 4)
		{
			system("cls");
			return menu();
		}
		system("cls");
		printtop10(temp2);
		cout << endl;
		system("pause");
		if (_kbhit)
		{
			//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
			set_color(4);
			system("cls");
			return menu();
			fflush(stdin);
		}
		break;
	default:
		system("cls");
		break;
	}
}

