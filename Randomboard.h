#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <thread>
using namespace std;

struct point
{
	int pointX, pointY;
};

int checkI(int** p, int n, point ps1, point ps2)
{
	if (ps1.pointX != ps2.pointX && ps1.pointY != ps2.pointY) return 0;
	if (ps1.pointX == ps2.pointX)
	{
		if (ps1.pointY > ps2.pointY)
			swap(ps1, ps2);
		for (int i = ps1.pointY + 1; i <= ps2.pointY; ++i)
			if (p[ps1.pointX][i] != 0 && i < ps2.pointY) return 0;
	}
	else
	{
		if (ps1.pointX > ps2.pointX)
			swap(ps1, ps2);
		for (int i = ps1.pointX + 1; i <= ps2.pointX; ++i)
			if (p[i][ps1.pointY] != 0 && i < ps2.pointX) return 0;
	}
	return 1;
}

int checkL(int** p, int n, point ps1, point ps2)
{
	int i, j;
	if (ps1.pointX == ps2.pointX || ps1.pointY == ps2.pointY) return 0;
	if (ps1.pointY > ps2.pointY) swap(ps1, ps2);
	for (j = ps1.pointY + 1; j <= ps2.pointY; ++j)
		if (p[ps1.pointX][j] != 0) break;
	if (j > ps2.pointY)
	{
		--j;
		if (ps1.pointX < ps2.pointX)
		{
			for (i = ps1.pointX + 1; i <= ps2.pointX; ++i)
				if (p[i][j] != 0 && i < ps2.pointX) break;
			if (i > ps2.pointX) return 1;
		}
		else
		{
			for (i = ps1.pointX - 1; i >= ps2.pointX; --i)
				if (p[i][j] != 0 && i > ps2.pointX) break;
			if (i < ps2.pointX) return 1;
		}
	}
	if (ps1.pointX < ps2.pointX)
	{
		for (i = ps1.pointX + 1; i <= ps2.pointX; ++i)
			if (p[i][ps1.pointY] != 0) return 0;
		--i;
	}
	else
	{
		for (i = ps1.pointX - 1; i >= ps2.pointX; --i)
			if (p[i][ps1.pointY] != 0) return 0;
		++i;
	}
	for (j = ps1.pointY + 1; j <= ps2.pointY; ++j)
		if (p[i][j] != 0 && j < ps2.pointY) return 0;
	return 1;
}

int checkZ(int** p, int n, point ps1, point ps2)
{
	int i, j, x1, x2, sum, * rc, k = 0;
	if (ps1.pointX == ps2.pointX || ps2.pointY == ps1.pointY) return 0;
	rc = new int[n + 1];
	if (ps1.pointY > ps2.pointY) swap(ps1, ps2);
	x1 = ps1.pointX;  x2 = ps2.pointX;
	if (ps1.pointX > ps2.pointX) swap(x1, x2);
	for (i = x1 + 1; i < x2; ++i)
	{
		sum = 0;
		for (j = ps1.pointY; j <= ps2.pointY; ++j)
		{
			sum += p[i][j];
			if (sum != 0) break;
		}
		if (sum == 0)
		{
			rc[k] = i;
			++k;
		}
	}
	if (ps1.pointX > ps2.pointX) swap(ps1, ps2);
	for (int t = 0; t < k; ++t)
	{
		for (i = ps1.pointX + 1; i < rc[t]; ++i)
			if (p[i][ps1.pointY] != 0) break;
		for (j = ps2.pointX - 1; j > rc[t]; --j)
			if (p[j][ps2.pointY] != 0) break;
		if (i == j)
		{
			delete[] rc;
			return 1;
		}
	}
	if (ps1.pointY > ps2.pointY) swap(ps1, ps2);
	k = 0;
	for (j = ps1.pointY + 1; j < ps2.pointY; ++j)
	{
		sum = 0;
		for (i = x1; i <= x2; ++i)
		{
			sum += p[i][j];
			if (sum != 0) break;
		}
		if (sum == 0)
		{
			rc[k] = j;
			++k;
		}
	}
	for (int t = 0; t < k; ++t)
	{
		for (i = ps1.pointY + 1; i < rc[t]; ++i)
			if (p[ps1.pointX][i] != 0) break;
		for (j = ps2.pointY - 1; j > rc[t]; --j)
			if (p[ps2.pointX][j] != 0) break;
		if (i == j)
		{
			delete[] rc;
			return 1;
		}
	}
	delete[] rc;
	return 0;
}

int checkU(int** p, int n, point ps1, point ps2)
{
	int i, j, x1, x2, sum, * rc, k = 0;
	rc = new int[n + 1];
	if (ps1.pointY > ps2.pointY) swap(ps1, ps2);
	x1 = ps1.pointX;  x2 = ps2.pointX;
	if (x1 > x2) swap(x1, x2);
	if (ps1.pointX != ps2.pointX)
	{
		for (i = ps1.pointY; i < n; ++i)
			if (i > ps1.pointY && p[ps1.pointX][i] != 0) break;
		for (j = ps2.pointY; j < n; ++j)
			if (j > ps2.pointY && p[ps2.pointX][j] != 0) break;
		if (i == n && j == n)
		{
			delete[] rc;
			return 1;
		}
		for (j = ps2.pointY + 1; j < n; ++j)
		{
			sum = 0;
			for (i = x1; i <= x2; ++i)
			{
				sum += p[i][j];
				if (sum != 0) break;
			}
			if (sum == 0)
			{
				rc[k] = j;
				++k;
			}
		}
		for (int t = 0; t < k; ++t)
		{
			for (i = ps1.pointY + 1; i < rc[t]; ++i)
				if (p[ps1.pointX][i] != 0) break;
			for (j = ps2.pointY + 1; j < rc[t]; ++j)
				if (p[ps2.pointX][j] != 0) break;
			if (i == rc[t] && j == rc[t])
			{
				delete[] rc;
				return 1;
			}
		}
		//----------------------------------------------------
		k = 0;
		for (i = ps1.pointY; i >= 0; --i)
			if (i < ps1.pointY && p[ps1.pointX][i] != 0) break;
		for (j = ps2.pointY; j >= 0; --j)
			if (j < ps2.pointY && p[ps2.pointX][j] != 0) break;
		if (i == -1 && j == -1)
		{
			delete[] rc;
			return 1;
		}
		for (j = ps1.pointY - 1; j >= 0; --j)
		{
			sum = 0;
			for (i = x1; i <= x2; ++i)
			{
				sum += p[i][j];
				if (sum != 0) break;
			}
			if (sum == 0)
			{
				rc[k] = j;
				++k;
			}
		}
		for (int t = 0; t < k; ++t)
		{
			for (i = ps1.pointY - 1; i > rc[t]; --i)
				if (p[ps1.pointX][i] != 0) break;
			for (j = ps2.pointY - 1; j > rc[t]; --j)
				if (p[ps2.pointX][j] != 0) break;
			if (i == rc[t] && j == rc[t])
			{
				delete[] rc;
				return 1;
			}
		}
	}
	//----------------------------------------------------
	if (ps1.pointY != ps2.pointY)
	{
		k = 0;
		for (i = ps1.pointX; i < n; ++i)
			if (i > ps1.pointX && p[i][ps1.pointY] != 0) break;
		for (j = ps2.pointX; j < n; ++j)
			if (j > ps2.pointX && p[j][ps2.pointY] != 0) break;
		if (i == n && j == n)
		{
			delete[] rc;
			return 1;
		}
		for (i = x2 + 1; i < n; ++i)
		{
			sum = 0;
			for (j = ps1.pointY; j <= ps2.pointY; ++j)
			{
				sum += p[i][j];
				if (sum != 0) break;
			}
			if (sum == 0)
			{
				rc[k] = i;
				++k;
			}
		}
		for (int t = 0; t < k; ++t)
		{
			for (i = ps1.pointX + 1; i < rc[t]; ++i)
				if (p[i][ps1.pointY] != 0) break;
			for (j = ps2.pointX + 1; j < rc[t]; ++j)
				if (p[j][ps2.pointY] != 0) break;
			if (i == rc[t] && j == rc[t])
			{
				delete[] rc;
				return 1;
			}
		}
		//----------------------------------------------------
		k = 0;
		for (i = ps1.pointX; i >= 0; --i)
			if (i < ps1.pointX && p[i][ps1.pointY] != 0) break;
		for (j = ps2.pointX; j >= 0; --j)
			if (j < ps2.pointX && p[j][ps2.pointY] != 0) break;
		if (i == -1 && j == -1)
		{
			delete[] rc;
			return 1;
		}
		for (i = x1 - 1; i >= 0; --i)
		{
			sum = 0;
			for (j = ps1.pointY; j <= ps2.pointY; ++j)
			{
				sum += p[i][j];
				if (sum != 0) break;
			}
			if (sum == 0)
			{
				rc[k] = i;
				++k;
			}
		}
		for (int t = 0; t < k; ++t)
		{
			for (i = ps1.pointX - 1; i > rc[t]; --i)
				if (p[i][ps1.pointY] != 0) break;
			for (j = ps2.pointX - 1; j > rc[t]; --j)
				if (p[j][ps2.pointY] != 0) break;
			if (i == rc[t] && j == rc[t])
			{
				delete[] rc;
				return 1;
			}
		}
	}
	delete[] rc;
	return 0;
}

//func to include four check
int checkLine(int** p, int n, point ps1, point ps2)
{
	if (checkI(p, n, ps1, ps2)) return 1;
	else if (checkU(p, n, ps1, ps2)) return 1;
	else if (checkL(p, n, ps1, ps2)) return 1;
	else if (checkZ(p, n, ps1, ps2)) return 1;
	return 0;
}

//Check if there are available matches.If not, then run ResetTable().
int checkReset(int** p, int n, int x, int y)
{
	point ps1, ps2;
	ps1.pointX = x;  ps1.pointY = y;
	for (int i = x; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (p[i][j] == p[x][y] && (i != x || j != y))
			{
				ps2.pointX = i;  ps2.pointY = j;
				if (checkLine(p, n, ps1, ps2)) return 0;
			}
	return 1;
}

//print board
void outTable(int** p, int n, int x, int y, point ps, int* go, string bg[])
{
	set_color(14);
	GoTo(44, 3);
	cout << "P: Pause game";
	GoTo(44, 4);
	cout << "H: Use hint";
	GoTo(44, 5);
	cout << "ESC: Exit ";

	for (int i = 0; i < n; ++i)
	{
		*go = 0;
		fflush(stdin);
		GoTo(40, 2 * i + 7);
		cout << char(179);
		for (int j = 0; j < n; ++j)
		{
			if (p[i][j] != 0)
			{
				if ((i == x && j == y) || (i == ps.pointX && j == ps.pointY))
				{
					set_color(15);
					cout << char(219);
					set_color(15 * 16 + 4);
					cout << char(64 + p[i][j]);
					set_color(15);
					cout << char(219) << char(179);
				}
				else cout << " " << char(64 + p[i][j]) << " " << char(179);
			}
			else
			{
				if (i == x && j == y)
				{
					set_color(15);
					cout << char(219) << char(219) << char(219) << char(179);
				}
				else
				{
					cout << " ";
					set_color(3);
					cout << bg[i][j];
					set_color(15);
					cout << " " << char(179);
				}
			}
		}
		cout << endl;
	}
}

// Allocate the block of memory of the game table.
void genTable(int**& p, int n)
{
	p = new int* [n];
	for (int i = 0; i < n; ++i)
		p[i] = new int[n];
}

void genValue(int** p, int n, int* count)
{
	for (int i = 0; i < n * n / 4 + 1; ++i)
		count[i] = 0;
	srand(int(time(NULL)));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			p[i][j] = rand() % (n * n / 4 - 1 + 1) + 1;
			while (count[p[i][j]] >= 4)
				p[i][j] = rand() % (n * n / 4 - 1 + 1) + 1;
			++count[p[i][j]];
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (p[i][j] != 0 && !checkReset(p, n, i, j)) return;
	genValue(p, n, count);
}

//Reset game table if there are no matching sets available
void ResetTable(int** p, int n, int* count)
{
	int* countText = new int[n * n / 4 + 1];
	for (int i = 0; i < n * n / 4 + 1; ++i)
		countText[i] = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (p[i][j] != 0 && !checkReset(p, n, i, j))
			{
				delete[] countText;
				return;
			}
	srand(int(time(NULL)));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (p[i][j] != 0)
			{
				p[i][j] = rand() % (n * n / 4 - 1 + 1) + 1;
				while (countText[p[i][j]] >= count[p[i][j]])
					p[i][j] = rand() % (n * n / 4 - 1 + 1) + 1;
				++countText[p[i][j]];
			}
	delete[] countText;
	ResetTable(p, n, count);
}
//Change the current position when pressing A, S, W, D.
void Move(int** p, int n, int& i, int& j, char key, point ps, int* go, string bg[])
{
	if (toupper(key) == 68 && j != n - 1)
	{
		++j;
		outTable(p, n, i, j, ps, go, bg);
	}
	else if (toupper(key) == 65 && j != 0)
	{
		--j;
		outTable(p, n, i, j, ps, go, bg);
	}
	else if (toupper(key) == 87 && i != 0)
	{
		--i;
		outTable(p, n, i, j, ps, go, bg);
	}
	else if (toupper(key) == 83 && i != n - 1)
	{
		++i;
		outTable(p, n, i, j, ps, go, bg);
	}
}

//cells slide left
void left(int** p, int n, point ps1, point ps2)
{
	if (ps1.pointY > ps2.pointY) swap(ps1, ps2);
	if (ps1.pointX == ps2.pointX)
	{
		if (ps1.pointY + 1 == ps2.pointY)
		{
			for (int i = ps1.pointY; i < n - 2; ++i)
				p[ps1.pointX][i] = p[ps1.pointX][i + 2];
			p[ps1.pointX][n - 2] = 0;
			p[ps1.pointX][n - 1] = 0;
			return;
		}
		for (int i = ps1.pointY; i < n - 1; ++i)
			p[ps1.pointX][i] = p[ps1.pointX][i + 1];
		for (int i = ps2.pointY - 1; i < n - 1; ++i)
			p[ps1.pointX][i] = p[ps1.pointX][i + 1];
		p[ps1.pointX][n - 2] = 0;
		p[ps1.pointX][n - 1] = 0;
		return;
	}
	for (int i = ps1.pointY; i < n - 1; ++i)
		p[ps1.pointX][i] = p[ps1.pointX][i + 1];
	p[ps1.pointX][n - 1] = 0;
	for (int i = ps2.pointY; i < n - 1; ++i)
		p[ps2.pointX][i] = p[ps2.pointX][i + 1];
	p[ps2.pointX][n - 1] = 0;

}

//cells slide right
void right(int** p, int n, point ps1, point ps2)
{
	if (ps1.pointY > ps2.pointY) swap(ps1, ps2);
	if (ps1.pointX == ps2.pointX)
	{
		if (ps1.pointY + 1 == ps2.pointY)
		{
			for (int i = ps2.pointY; i >= 2; --i)
				p[ps1.pointX][i] = p[ps1.pointX][i - 2];
			p[ps1.pointX][0] = 0;
			p[ps1.pointX][1] = 0;
			return;
		}
		for (int i = ps2.pointY; i >= 1; --i)
			p[ps2.pointX][i] = p[ps2.pointX][i - 1];
		for (int i = ps1.pointY + 1; i >= 1; --i)
			p[ps1.pointX][i] = p[ps1.pointX][i - 1];
		p[ps1.pointX][0] = 0;
		p[ps1.pointX][1] = 0;
		return;
	}
	for (int i = ps1.pointY; i >= 1; --i)
		p[ps1.pointX][i] = p[ps1.pointX][i - 1];
	p[ps1.pointX][0] = 0;
	for (int i = ps2.pointY; i >= 1; --i)
		p[ps2.pointX][i] = p[ps2.pointX][i - 1];
	p[ps2.pointX][0] = 0;
}

//cells slide up
void up(int** p, int n, point ps1, point ps2)
{
	if (ps1.pointX > ps2.pointX) swap(ps1, ps2);
	if (ps1.pointY == ps2.pointY)
	{
		if (ps1.pointX + 1 == ps2.pointX)
		{
			for (int i = ps1.pointX; i < n - 2; ++i)
				p[i][ps1.pointY] = p[i + 2][ps1.pointY];
			p[n - 2][ps1.pointY] = 0;
			p[n - 1][ps1.pointY] = 0;
			return;
		}
		for (int i = ps1.pointX; i < n - 1; ++i)
			p[i][ps1.pointY] = p[i + 1][ps1.pointY];
		for (int i = ps2.pointX - 1; i < n - 1; ++i)
			p[i][ps1.pointY] = p[i + 1][ps1.pointY];
		p[n - 2][ps1.pointY] = 0;
		p[n - 1][ps1.pointY] = 0;
		return;
	}
	for (int i = ps1.pointX; i < n - 1; ++i)
		p[i][ps1.pointY] = p[i + 1][ps1.pointY];
	p[n - 1][ps1.pointY] = 0;
	for (int i = ps2.pointX; i < n - 1; ++i)
		p[i][ps2.pointY] = p[i + 1][ps2.pointY];
	p[n - 1][ps2.pointY] = 0;

}

//cells slide down
void down(int** p, int n, point ps1, point ps2)
{
	if (ps1.pointX > ps2.pointX) swap(ps1, ps2);
	if (ps1.pointY == ps2.pointY)
	{
		if (ps1.pointX + 1 == ps2.pointX)
		{
			for (int i = ps2.pointX; i >= 2; --i)
				p[i][ps1.pointY] = p[i - 2][ps1.pointY];
			p[0][ps1.pointY] = 0;
			p[1][ps1.pointY] = 0;
			return;
		}
		for (int i = ps2.pointX; i >= 1; --i)
			p[i][ps2.pointY] = p[i - 1][ps2.pointY];
		for (int i = ps1.pointX + 1; i >= 1; --i)
			p[i][ps1.pointY] = p[i - 1][ps1.pointY];
		p[0][ps1.pointY] = 0;
		p[1][ps1.pointY] = 0;
		return;
	}
	for (int i = ps1.pointX; i >= 1; --i)
		p[i][ps1.pointY] = p[i - 1][ps1.pointY];
	p[0][ps1.pointY] = 0;
	for (int i = ps2.pointX; i >= 1; --i)
		p[i][ps2.pointY] = p[i - 1][ps2.pointY];
	p[0][ps2.pointY] = 0;
}

//Showing hints to the gameplay screen.
void PrintSuggest(int** p, int n, int x, int y, point ps1, point ps2, int* go, string bg[])
{
	fflush(stdin);
	*go = 0;
	for (int i = 0; i < n; ++i)
	{
		GoTo(40, 2 * i + 7);
		cout << char(179);
		for (int j = 0; j < n; ++j)
		{
			if (p[i][j] != 0)
			{
				if ((i == ps1.pointX && j == ps1.pointY) || (i == ps2.pointX && j == ps2.pointY))
				{
					set_color(15);
					cout << " ";
					set_color(4);
					cout << char(64 + p[i][j]);
					set_color(15);
					cout << " " << char(179);
				}
				else if (i == x && j == y)
				{
					set_color(15);
					cout << char(219);
					set_color(15 * 16 + 4);
					cout << char(64 + p[i][j]);
					set_color(15);
					cout << char(219) << char(179);
				}
				else cout << " " << char(64 + p[i][j]) << " " << char(179);
			}
			else
			{
				if (i == x && j == y)
				{
					set_color(15);
					cout << char(219) << char(219) << char(219) << char(179);
				}
				else
				{
					cout << " ";
					set_color(3);
					cout << bg[i][j];
					set_color(15);
					cout << " " << char(179);
				}
			}
		}
		cout << endl;
	}
}

//Find the hints. Find two positions that satisfy the result of function checkLine().
void MoveSuggest(int** p, int n, int curX, int curY, int& hint, int* go, string bg[])
{
	point ps1, ps2;
	--hint;
	*go = 0;
	GoTo(70, 4);
	cout << "Hint: " << hint;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (p[i][j] != 0)
			{
				ps1.pointX = i;  ps1.pointY = j;
				for (int k = i; k < n; ++k)
					for (int t = 0; t < n; ++t)
						if (p[k][t] == p[i][j] && (k != i || t != j))
						{
							ps2.pointX = k;  ps2.pointY = t;
							if (checkLine(p, n, ps1, ps2))
							{
								PrintSuggest(p, n, curX, curY, ps1, ps2, go, bg);
								return;
							}
						}
			}
}

//Show the background where the squares are disappeared.
void Background(string bg[], int n)
{
	string a, b, c, d, e, f, g, h, i, j, k, l, m, o;
	a = char(92);
	b = char(196);
	c = char(218);
	d = char(191);
	e = char(192);
	f = char(217);
	g = char(201);
	h = char(205);
	i = char(187);
	j = char(186);
	k = char(200);
	l = char(188);
	m = char(219);
	o = char(31);
	switch (n)
	{
	case 6:	bg[0] = "(" + a + "_(" + a + " ";
		bg[1] = "(=':')";
		bg[2] = "(U  U)";
		bg[3] = "(')(')";
		bg[4] = "|     ";
		bg[5] = a + "_O   ";
		break;
	case 8: bg[0] = " " + b + b + b + b + b + b + " ";
		bg[1] = "|      |";
		bg[2] = "|  " + b + b + "  |";
		bg[3] = "|" + b + "|" + c + d + "|" + b + "|";
		bg[4] = "|" + b + "|" + e + f + "|" + b + "|";
		bg[5] = "|  " + b + b + "  |";
		bg[6] = "|      |";
		bg[7] = " " + b + b + b + b + b + b + " ";
		break;
	default:bg[0] = g + h + h + h + h + h + h + h + h + i;
		bg[1] = j + "(')_(')_" + j;
		bg[2] = j + " ; .. ';" + j;
		bg[3] = j + "(o _ o)'" + j;
		bg[4] = j + "   " + m + "    " + j;
		bg[5] = j + "   " + o + "    " + j;
		bg[6] = j + "(')_(')_" + j;
		bg[7] = j + " ;= = ';" + j;
		bg[8] = j + "(o _,o)'" + j;
		bg[9] = k + h + h + h + h + h + h + h + h + l;
		break;
	}
}

//Sum up 4 modes and show them up on the game table.
void Round(int** p, int n, int* count, int choice, int* turn, int* go)
{
	char key = 0;
	point ps1 = { -1,-1 }, ps2;
	int i = 0, j = 0, countPos = 0, pause = 0, hint = 5;
	string bg[10];
	DrawLine(n);
	outTable(p, n, 0, 0, { 0,0 }, go, bg);
	Background(bg, n);
	while (*turn > 0)
	{
		if (pause == 0) *go = 1;
		key = _getch();
		if (key == 27) return;
		else if (toupper(key) == 80)
		{
			if (pause == 0)
			{
				pause = 1;
				*go = 0;
			}
			else pause = 0;
		}
		else if (toupper(key) == 72 && pause == 0 && hint != 0) MoveSuggest(p, n, i, j, hint, go, bg);
		else if (key != 32 && pause == 0) Move(p, n, i, j, key, ps1, go, bg);
		else if (countPos == 0 && p[i][j] != 0 && pause == 0)
		{
			ps1.pointX = i;  ps1.pointY = j;
			++countPos;
			outTable(p, n, i, j, ps1, go, bg);
		}
		else if (countPos == 1 && (i != ps1.pointX || j != ps1.pointY) && p[i][j] != 0 && pause == 0)
		{
			ps2.pointX = i;  ps2.pointY = j;
			if (p[ps2.pointX][ps2.pointY] == p[ps1.pointX][ps1.pointY] && checkLine(p, n, ps1, ps2))
			{
				count[p[ps1.pointX][ps1.pointY]] -= 2;
				p[ps1.pointX][ps1.pointY] = 0;
				p[ps2.pointX][ps2.pointY] = 0;
				*turn -= 2;
				switch (choice)
				{
				case 1: break;
				case 2: left(p, n, ps1, ps2);
					break;
				case 3: right(p, n, ps1, ps2);
					break;
				case 4: up(p, n, ps1, ps2);
					break;
				default: down(p, n, ps1, ps2);
					break;
				}
				ps1.pointX = -1;  ps1.pointY = -1;
				if (*turn > 0) ResetTable(p, n, count);
				outTable(p, n, ps2.pointX, ps2.pointY, ps1, go, bg);
			}
			countPos = 0;
			ps1.pointX = -1;  ps1.pointY = -1;
			ps2.pointX = -1;  ps2.pointY = -1;
		}
	}
}

//Free block of memory of game table.
void freeMem(int** p, int n)
{
	for (int i = 0; i < n; ++i)
		delete[] p[i];
	delete[] p;
}

//Run the game.
void GameRun(int** p, int n, int choice, playerinput& player)
{
	int* count = new int[n * n / 4 + 1], a, b, c, * turn = &a, * time = &b, * go = &c, turn2;
	*turn = n * n;
	genValue(p, n, count);
	thread task(clocksystem, turn, time, go);
	Round(p, n, count, choice, turn, go);
	turn2 = *turn;
	*turn = 0;
	task.join();
	system("cls");
	if (turn2 == 0)
	{
		player.record = *time;
		printafterdone(player, time);
		consistinfo(player, n);
	}
	freeMem(p, n);
	delete[] count;
}


