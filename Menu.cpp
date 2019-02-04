#include "Menu.h"
#include "Game.h"
void Menu()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "                         WITAJ W GRZE" << endl;
	cout << "    PROSTE DZIALANIA MATEMATYCZNE NA LICZBACH Z ZAKRESU 0 DO 9" << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "              Aby rozpoczac wcisnij przycisk spacji" << endl;

	cout << "            Sterowanie odbywa sie przy pomocy strzalek" << endl;
	cout << "  Aby wykonac strzal wcisnij cyfre, ktora odpowiada wynikowi dzialania" << endl;
	int press = _getch();
	if (press == ' ')
	{
		Beep(400, 500);
		while (true)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			newGame();
		}
	}

}