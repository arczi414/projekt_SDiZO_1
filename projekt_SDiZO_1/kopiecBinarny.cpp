#include "stdafx.h"
#include "kopiecBinarny.h"
#include "lista.h"
#include "stoper.h"

KopiecBinarny::KopiecBinarny():
kopiec(NULL), n(0)
{

}

KopiecBinarny::~KopiecBinarny()
{
	delete[] kopiec;
	kopiec = NULL;
}

/*
	Dok³ada nowy element do kopca.
*/
void KopiecBinarny::push(int data, double* pomiar)
{
	Stoper st;

	// dodanie nowego elementu i przepisanie tablicy
	int* kopiec_temp = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		kopiec_temp[i] = kopiec[i];
	}
	
	delete[] kopiec;
	kopiec = kopiec_temp;

	st.start();

	n++;
	kopiec_temp[n - 1] = data;

	// przywracanie wlasnosci kopca
	int nowyElement, rodzic;
	nowyElement = n - 1;
	rodzic = floor((nowyElement - 1) / 2);
	
	while (rodzic >=0 && kopiec[rodzic] < kopiec[nowyElement])
	{
		int temp = kopiec[rodzic];
		kopiec[rodzic] = kopiec[nowyElement];
		kopiec[nowyElement] = temp;
		nowyElement = rodzic;
		rodzic = floor((nowyElement - 1) / 2);
		// opoznienie
		for (int i = 0; i < 10000; i++);
	}

	st.stop();

	if (pomiar!=NULL)
		*pomiar = st.inMicrosec();
}

/*
	Wyszukuje i usuwa wybrany element z kopca. Zwraca false
	gdy zadany element nie istnieje.
*/
bool KopiecBinarny::usunWybrany(int data, double* pomiar)
{
	Stoper st;
	double *pop_time = new double(0);
	double *push_time = new double(0);
	double pop_operation = 0;
	double push_operation = 0;

	bool found = false;

	double temp_time = 0;

	if (n > 0)
	{
		st.start();

		int *temp = NULL;
		int prev = 0;
		Lista *tmpLst = new Lista();

		// sciaganie elementow do natrafienia na szukany
		
		st.stop();
		temp_time = st.inMicrosec();

		do
		{
			pop_operation += *pop_time;
			temp = pop(pop_time);
			if (*temp != data) { tmpLst->insert(prev, *temp); }
			prev = *temp;
		} 
		while (*temp != data && n > 0);

		found = *temp == data ? true : false;

		// wprowadzenie œci¹gniêtych elementów spowrotem do kopca
		tmpLst->reset(1);
		do
		{
			push_operation += *push_time;
			temp = tmpLst->next();
			if (temp != NULL) { push(*temp, push_time); }
		} 
		while (tmpLst->hasNext());

		// ostani element na liscie
		st.start();
		temp = tmpLst->next();
		if (temp != NULL ) { push(*temp); }
		st.stop();

		if (pomiar != NULL)
			*pomiar = pop_operation + push_operation + temp_time + st.inMicrosec();

		if (found) { return true; }
	}

	return false;
}

/*
	Zdejmuje i zwraca korzen kopca.
*/
int* KopiecBinarny::pop(double* pomiar)
{
	Stoper st;

	st.start();		// rozpoczecie pomiaru

	// zamiana korzenia z ostatnim lisciem
	if (n == 1)
	{
		n--;
		int save = kopiec[0];
		delete[] kopiec;
		kopiec = NULL;
		return new int(save);
	}
	else if (n > 1)
	{
		int save = kopiec[0];	// korzen
		kopiec[0] = kopiec[n - 1];	// zamiana z ostatnim lisciem

		int akt = 0;
		int left = 1;
		int right = 2;

		while ( (left < n - 1) && (kopiec[left] > kopiec[akt] || kopiec[right] > kopiec[akt]))
		{
			// opoznienie dla pomiarow
			for (int i = 0; i < 5000; i++);

			if (right >= n - 1)
			{
				int saveL = kopiec[akt];
				kopiec[akt] = kopiec[left];
				kopiec[left] = saveL;

				akt = left;
				left = 2 * akt + 1;
				right = 2 * akt + 2;
			}
			else
			{
				if (kopiec[left] > kopiec[right])
				{
					int saveL = kopiec[akt];
					kopiec[akt] = kopiec[left];
					kopiec[left] = saveL;

					akt = left;
					left = 2 * akt + 1;
					right = 2 * akt + 2;
				}
				else
				{
					int saveR = kopiec[akt];
					kopiec[akt] = kopiec[right];
					kopiec[right] = saveR;

					akt = right;
					left = 2 * akt + 1;
					right = 2 * akt + 2;
				}
			}
		}
		st.stop();

		if (pomiar)
			*pomiar = st.inMicrosec();

		// usuniecie ostatniego liscia drzewa
		int *temp = kopiec;
		kopiec = new int[n - 1];
		for (int i = 0; i < n - 1; i++)
			kopiec[i] = temp[i];

		delete[] temp;
		n--;
		return new int(save);
	}

	return NULL;
}

/*
	Sprawdza czy zadany element istnieje w strukturze.
*/
bool KopiecBinarny::find(int data)
{
	if (n>0)
		return find(data, 0);

	return false;
}

/*
	Funkcja rekurencyjna, pomocnicza dla find().
*/
bool KopiecBinarny::find(int data, int wezel)
{
	int child1 = wezel * 2 + 1;
	int child2 = wezel * 2 + 2;
	bool z = false;

	if (kopiec[wezel] == data)
		return true;
	else if (wezel < n && kopiec[wezel] != data)
	{
			// opoznienie dla pomiarow
			for (int i = 0; i < 1000; i++);

			if (child1 < n)
				z = find(data, child1);

			if (z == true)
				return true;

			if (child2 < n)
				z = find(data, child2);

			if (z == true)
				return true;
	}

	return false;
}

// wypisuje zawartosc kopca
void  KopiecBinarny::print()
{
	if (kopiec != NULL)
	{
		std::cout << kopiec[0] << "\n";
		printTree(0, 1);
	}
}

// funkcja glowna wypisania na ekran
void KopiecBinarny::printTree(int wezel, int glebokosc)
{
	int child1 = wezel * 2 + 1;
	int child2 = wezel * 2 + 2;

	if (child1 < n)
	{
		for (int i = 0; i < glebokosc; i++)
			std::cout << "\t";
		std::cout << kopiec[child1] << "\n";
		printTree(child1, glebokosc + 1);
	}

	if (child2 < n)
	{
		for (int i = 0; i < glebokosc; i++)
			std::cout << "\t";
		std::cout << kopiec[child2] << "\n";
		printTree(child2, glebokosc + 1);
	}
}