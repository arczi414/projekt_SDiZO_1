#include "stdafx.h"
#include "tablica.h"

/*
	Tworzy nowa tablice o zadanej liczbie elementow.
*/
void Tablica::create(int n)
{
	this->tablica = new int(n);
	this->n = n;
}

/*
	Niszczy tablice i zeruje jej strukture.
*/
void Tablica::destroy()
{
	delete[] tablica;
	tablica = NULL;
	n = 0;
}

/*
	Zwraca element tablicy o podanym indeksie.
*/
int Tablica::read(int index)
{
	if (index < n && index >= 0)
		return *(tablica + index);
	
	return -1;
}

/*
	Zapisuje 'data' w miejscu o indeksie 'index'.
*/
bool Tablica::write(int index, int data)
{
	if (index >= 0 && index < n)
	{
		*(tablica + index) = data;

		return true;
	}

	return false;
}

/*
	Dodaje nowy element w miejsce 'index' i w razie potrzeby rozsuwa tablicê.
*/
void Tablica::add(int index, int data)
{
	if (index <= n)
	{
		int *temp = tablica;
		tablica = new int[n + 1];
		for (int i = 0; i < index; i++)
		{
			tablica[i] = temp[i];
		}

		tablica[index] = data;
		n++;

		for (int i = index + 1; i < n; i++)
		{
			tablica[i] = temp[i - 1];
		}

		delete[] temp;
	}
	else
	{
		int *temp = tablica;
		tablica = new int[n + 1];
		for (int i = 1; i < n+1; i++)
		{
			tablica[i] = temp[i-1];
		}

		tablica[0] = data;
		n++;

		delete[] temp;
	}
}

/*
	Wyszukuje element w tablicy. Zwraca numer indeksu elementu. Jeœli
	szukanej wartoœci nie ma w strukturze zwraca -1.
*/
int Tablica::find(int data)
{
	for (int i = 0; i < n; i++)
	{
		if (tablica[i] == data) return i;
	}

	return -1;
}

/*
	Usuwa element o zadanym indeksie i zsuwa tablicê. Jesli wartosc indeksu jest
	nieprawidlowa zwraca false.
*/
bool Tablica::deleteData(int index)
{
	if (index < n && index >= 0)
	{
		int *temp = tablica;
		n--;
		tablica = new int[n];
		for (int i = 0; i < index; i++)
		{
			tablica[i] = temp[i];
		}

		for (int i = index; i < n; i++)
		{
			tablica[i] = temp[i + 1];
		}

		delete[] temp;

		return true;
	}

	return false;
}

/*
	Wypisuje strukture na ekran.
*/
void Tablica::print()
{
	if ( n > 0 )
	{
		std::cout << tablica[0];

		for (int i = 1; i < n; i++)
			std::cout << ", " << tablica[i];
	}
}