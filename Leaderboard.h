#include <iostream>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <string>
#include <conio.h>
#define MAX 100
using namespace std;

struct playerinput {
	string name;
	int age;
	int record;
};
//func to create a mobile clock during playing
void clocksystem(int* turn, int* time, int* go)
{
	int h = 0, m = 0, s = 0;
	while (*turn > 0)
	{
		if (*go == 1)
		{
			fflush(stdin);
			//			Goto(45, 3);
			//			cout << char(251) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(183);
			//			Goto(45, 5);
			//			cout << char(212) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(208);
			//			Goto(45, 4);
			//			cout << "| ";
			//			if (h < 10)
			//				cout << "0" << h << ": ";
			//			else cout << m << ":";
			//			if (m < 10)
			//				cout << "0" << m << ": ";
			//			else cout << m << ":";
			//			if (s < 10)
			//				cout << "0" << s;
			//			else cout << s;
			//			cout << " |";
			s++;
			if (s == 59)
			{
				s = 0;
				m++;
			}
			if (m == 59)
			{
				m = 0;
				h++;
			}
		}
		Sleep(1000);
	}
	*time = h * 3600 + m * 60 + s;
}

// player will enter their information after winnning
void printafterdone(playerinput& player, int* time)
{
	//PlaySound(TEXT("victorysound.wav"), NULL, SND_ASYNC);
	set_color(4);
	GoTo(40, 8);
	cout << "Amazing goodjob em!!!";
	set_color(6);
	GoTo(40, 9);
	cout << "Your record is: " << *time << " seconds";
	GoTo(40, 10);
	cout << "Enter your first name and age to save record: ";
	GoTo(40, 11);
	cout << "Name: ";
	cin.ignore();
	getline(cin, player.name);
	//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
	GoTo(40, 12);
	cout << "Age: ";
	cin >> player.age;
	//PlaySound(TEXT("clicksound.wav"), NULL, SND_ASYNC);
}

//write player information to file
void consistinfo(playerinput player, int temp)
{
	ofstream output;
	switch (temp)
	{
	case 6:
		output.open("Leaderboard1.txt", ios::app);
		break;
	case 8:
		output.open("Leaderboard2.txt", ios::app);
		break;
	case 10:
		output.open("Leaderboard3.txt", ios::app);
		break;
	}
	output << "\n" << player.name << ",";
	output << player.age << ",";
	output << player.record;
	output.close();
}

//draw top10 leaderboard
void draw(int n)
{
	set_color(6);
	GoTo(51, 3);
	cout << "---LEADERBOARD---";
	GoTo(34, 4);
	cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(191);
	for (int i = 0; i < n - 1; i++)
	{
		GoTo(34, 6 + i * 2);
		cout << char(195) << char(196) << char(196) << char(196) << char(196) << char(196);
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
		cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(180);
	}
	GoTo(34, 6 + (n - 1) * 2);
	cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196);
	cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217);
	for (int i = 0; i < n; i++)
	{
		GoTo(84, 2 * i + 5);
		cout << "|";
	}
}

//print top 10 leaderboard
void printtop10(int temp)
{
	int numlines = 0;
	set_color(6);
	string a;
	playerinput player[10];
	playerinput tmp;
	ifstream input;
	switch (temp)
	{
	case 1:
		input.open("Leaderboard1.txt", ios::in);
		break;
	case 2:
		input.open("Leaderboard2.txt", ios::in);
		break;
	case 3:
		input.open("Leaderboard3.txt", ios::in);
		break;
	}
	getline(input, a);
	while (!input.eof() && numlines < 10)
	{
		getline(input, player[numlines].name, ',');
		getline(input, a, ',');
		player[numlines].age = stoi(a);
		getline(input, a);
		player[numlines].record = stoi(a);
		numlines++;
	}
	while (!input.eof())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (player[i].record > player[j].record)
				{
					swap(player[i], player[j]);
				}
			}
		}
		getline(input, tmp.name, ',');
		getline(input, a, ',');
		tmp.age = stoi(a);
		getline(input, a);
		tmp.record = stoi(a);
		for (int i = 10; i > 0; i--)
		{
			if (tmp.record < player[i].record)
			{
				player[i] = tmp;
				break;
			}
		}
	}
	for (int i = 0; i < numlines - 1; i++)
	{
		for (int j = i + 1; j < numlines; j++)
		{
			if (player[i].record > player[j].record)
			{
				swap(player[i], player[j]);
			}
		}
	}
	for (int i = 0; i < numlines; i++)
	{
		set_color(6);
		GoTo(34, 5 + i * 2);
		cout << "|";
		GoTo(42, 5 + i * 2);
		set_color(4);
		cout << i + 1 << ".Name: ";
		set_color(15);
		cout << player[i].name << ", ";
		set_color(4);
		cout << "Age: ";
		set_color(15);
		cout << player[i].age << ", ";
		set_color(4);
		cout << "Record: ";
		set_color(15);
		cout << player[i].record << "s.";
	}
	draw(numlines);
	input.close();
	ofstream output;
	switch (temp)
	{
	case 1:
		output.open("Leaderboard1.txt", ios::out);
		break;
	case 2:
		output.open("Leaderboard2.txt", ios::out);
		break;
	case 3:
		output.open("Leaderboard3.txt", ios::out);
		break;
	}
	for (int i = 0; i < numlines; i++)
	{
		output << "\n" << player[i].name << ",";
		output << player[i].age << ",";
		output << player[i].record;
	}
	output.close();
}
