#include "pch.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct postac
{
	int sila;
	int zrecznosc;
	int wytrzymalosc;
	int hp = 100;
};

int maxdmg;
int RzutKoscia;
int sukces = 0;
int armor;


void dmg(postac X, int zrecznoscPrzeciwnika)
{

	sukces = 0;
	for (int a = 0; a < X.zrecznosc; a++)
	{
		RzutKoscia = (rand() % 12) + 1;

		if (RzutKoscia > zrecznoscPrzeciwnika)
		{
			sukces = sukces + 1;
		}
		if (RzutKoscia == 12);
		{
			sukces = sukces + 1;
		}

	}	maxdmg = sukces + X.sila;
}

void dmgtaken(postac X, int silaPrzeciwnika)
{
	armor = 0;
	sukces = 0;
	for (int a = 0; a < X.wytrzymalosc; a++)
	{
		RzutKoscia = (rand() % 12) + 1;

		if (RzutKoscia > silaPrzeciwnika)
		{
			sukces = sukces + 1;
		}
		if (RzutKoscia == 12);
		{
			sukces = sukces + 1;
		}

	}	armor = maxdmg - sukces;

	if (armor < 0) armor = 0;
}

int pierwszy(postac Andrzej, postac Janusz)
{
	if (Andrzej.zrecznosc == Janusz.zrecznosc)
	{
		int losowanie = rand() % 2 + 1;
		if (losowanie == 1)
		{
			return 1;

		}
		else
		{
			return 2;
		}

	}
	else if (Andrzej.zrecznosc > Janusz.zrecznosc)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int main()
{

	srand(time(NULL));
	postac Andrzej;
	Andrzej.sila = (rand() % 10) + 1;
	Andrzej.zrecznosc = (rand() % 10) + 1;
	Andrzej.wytrzymalosc = (rand() % 10) + 1;

	postac Janusz;
	Janusz.sila = (rand() % 10) + 1;
	Janusz.zrecznosc = (rand() % 10) + 1;
	Janusz.wytrzymalosc = (rand() % 10) + 1;

	cout << "Statystyki Andrzeja to: " << endl << "Sila: " << Andrzej.sila << " Zrecznosc: " << Andrzej.zrecznosc << " Wytrzymalosc: " << Andrzej.wytrzymalosc << endl;
	cout << "Statystyki Janusza to: " << endl << " Sila: " << Janusz.sila << " Zrecznosc: " << Janusz.zrecznosc << " Wytrzymalosc: " << Janusz.wytrzymalosc << endl;

	cout << "Janusz hp: " << Janusz.hp << endl;
	cout << "Andrzej hp: " << Andrzej.hp << endl;

	int kolej = pierwszy(Andrzej, Janusz);

	do
	{
		
		if (kolej % 2 != 0)
		{
			dmg(Andrzej, Janusz.zrecznosc);
			dmgtaken(Andrzej, Janusz.sila);
			Janusz.hp -= armor;
			cout << "Janusz hp: " << Janusz.hp << endl;
		}
		else
		{
			dmg(Janusz, Andrzej.zrecznosc);
			dmgtaken(Janusz, Andrzej.sila);
			Andrzej.hp -= armor;
			cout << "Andrzej hp: " << Andrzej.hp << endl;
		}

		++kolej;
		_getch();
	} while (Janusz.hp > 0 && Andrzej.hp > 0);


	return 0;
}
