#include "Game.h"
bool gameOver;
const int width = 30;
const int height = 10;
int x, y, fruitX, fruitY, score, when = 1, whenDot = 1, over = 0, z,life=4;
int dotX, dotY, button, w, which = 0;
char p, m;
int tabX[100], tabY[100], Results[100];
char tabChar[100];
int *results = Results;
char Equal;
HANDLE hOut;
bool t = false;
enum eDirection { STOP = 0, LEFT, RIGHT };
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height - 1;
	fruitX = rand() % width;
	fruitY = 0;
	score = 0;
	dotX = x;
	dotY = y - 1;

}
void Draw()
{
	system("cls");
	cout << char(201);
	for (int i = 1; i < width + 1; i++)
	{
		cout << char(205);
	}
	cout << char(187) << endl;
	for (int i = 0; i < height; i++)
	{
		cout << char(186);
		for (int j = 0; j < width; j++)
		{
			if (t && j==dotX && i==dotY)
			{
				cout << '*';
				dotY--;
				continue;
			}
			if (t && dotX == fruitX && dotY == fruitY)
			{
				t = false;
				dotX = x;
				dotY = y - 1;
				fruitX = rand() % width;
				fruitY = 0;
				score++;
				results++;
				over++;
			}
			if (fruitY == y - 1)
			{
				gameOver = true;
				break;
			}
			if (j == x && i == y)
			{
				cout << char(223);
			}
			else if (i == fruitY && j == fruitX)
			{
				cout << "V";
			}
			else
				cout << " ";
		}
		cout << char(186) << endl;
	}
	cout << char(200);
	for (int i = 1; i < width + 1; i++)
	{
		cout << char(205);
	}
	cout << char(188) << endl << endl;
	cout << "          " << tabX[over] << " " << tabChar[over] << " " << tabY[over] << " " << Equal << " " << '?' << endl << endl;
	cout << "      Pozostale zycie: " << life << endl;
	if (dotY == 0)
	{
		t = false;
		dotX = x;
		dotY = y - 1;
	}
	Sleep(90);
}
void Input()
{
	if (_kbhit())
	{
		button = _getch();
		switch (button)
		{
		case 75:
			dir = LEFT;
			break;
		case 77:
			dir = RIGHT;
			break;
		/*case 72:
			t = true;
			Beep(1000, 100);
			dotX = x;
			break;*/
		case 27:
			gameOver = true;
			break;
		}
		if (button-48 == w)
		{
			t = true;
			Beep(1000, 100);
			dotX = x;
		}
		else if(button>47 && button<58)
		{
			life--;
		}
	}

}
void Logic()
{
	switch (dir)
	{
	case LEFT:
		x--;
		dir = STOP;
		break;
	case RIGHT:
		x++;
		dir = STOP;
		break;
	default:
		break;
	}
	if (x > width)
	{
		x = 0;
	}
	if (x < 0)
	{
		x = width;
	}
}
void newGame()
{
	ifstream data("save.txt");
	int count=0;
	if (data.is_open())
	{
		while (!data.eof())
		{
			data >> x >> p >> y >> m >> z;
			count++;
		}
	}
	else
	{
		cout << "Nie mozna otworzyc plik." << endl;
		system("Pause");
	}
	data.close();
	data.open("save.txt", ios::in);
	for (int write = 0; !data.eof(); write++)
	{
		data >> tabX[write] >> tabChar[write] >> tabY[write] >> Equal >> Results[write];
	}
	results = Results;
	Setup();
	while (!gameOver && over<count && life>0)
	{
		w = *results;
		if (when % 17 == 0)
		{
			fruitY++;
		}
		Draw();
		Input();
		Logic();
		when++;
	}
	system("cls");
	Beep(300, 500);
	cout << "Koniec gry" << endl << "Twoj wynik to: " << score << endl << "Pozostale zycie: " << life << endl;
	gameOver = false;
	system("Pause");
}