#include "stdafx.h"
#include <fstream>
#include "tablica.h"
#include "lista.h"
#include "kopiecBinarny.h"
#include "drzewoCzerCzar.h"
#include "menu.h"

using namespace std;

int manageMenu()
{
	char menu_choice;
	int submenu_choice = 0;

	while (true)
	{
		menu_choice = showMainMenu();

		switch (menu_choice)
		{
		case '1':
			manageTabMenu();
			break;
		case '2':
			manageListMenu();
			break;
		case '3':
			manageHeapMenu();
			break;
		case '4':
			manageTreeMenu();
			break;
		case 'q':
			submenu_choice = -1;
			break;
		default:
			cout << "Niewlasciwy wybor, wybierz ponownie.\n\n";
			submenu_choice = manageMenu();
		}

		if (submenu_choice == -1)
			break;
	}

	return submenu_choice;
}

char showMainMenu()
{
	cout << "Menu:\n"
		<< " 1 - tablica\n"
		<< " 2 - lista\n"
		<< " 3 - kopiec binarny\n"
		<< " 4 - drzewo czerwono-czarne\n"
		<< " q - wyjscie z programu\n\n";

	return _getch();
}

char showTabMenu()
{
	cout << "Menu struktury 'tablica':\n"
		<< " 1 - dodaj elementy z pliku\n"
		<< " 2 - dodaj nowy element\n"
		<< " 3 - usun element\n"
		<< " 4 - wstaw wartosc\n"
		<< " 5 - znajdz wartosc\n"
		<< " 6 - wyswietl strukture\n"
		<< " q - wyjscie do menu\n\n";

	return _getch();
}

void manageTabMenu()
{
	char choice;
	int index, data;
	char *str_plik;
	ifstream plik;
	Tablica* tablica = new Tablica();

	while (true)
	{
		choice = showTabMenu();

		switch (choice)
		{
		case '1':
			str_plik = new char[30];
			cout << "Podaj nazwe pliku (razem z rozszerzeniem .txt): ";
			cin >> str_plik;
			plik.open(str_plik);
			if (plik)
			{
				plik.clear();
				plik.seekg(ios::beg);

				tablica->destroy();
				plik >> data;	//pobranie rozmiaru struktury (pominiecie - nie potrzebne)

				while (!plik.eof())
				{
					plik >> data;
					tablica->add(0, data);
				}

				plik.close();
				cout << "\nzaladowano dane do struktury\n\n";
			}
			else
				cout << "\nnie udalo sie wczytac danych z pliku (sprawdz czy plik istnieje)\n\n";

			delete str_plik;
			break;
		case '2':
			cout << "index: "; cin >> index;
			cout << "dane: "; cin >> data;
			tablica->add(index, data);
			cout << "\ndodano nowy element\n\n";
			break;
		case '3':
			cout << "index: "; cin >> data;
			if ( tablica->deleteData(data) )
				cout << "\nusunieto element\n\n";
			else
				cout << "\nprzekroczono zakres tablicy\n\n";
			break;
		case '4':
			cout << "index: "; cin >> index;
			cout << "dane: "; cin >> data;
			if( tablica->write(index, data) )
				cout << "\nwstawiono element\n\n";
			else
				cout << "\nprzekroczono zakres tablicy\n\n";
			cout << endl;
			break;
		case '5':
			cout << "szukana wartosc: "; cin >> data;
			if (tablica->find(data) >= 0)
				cout << "\nznaleziono\n\n";
			else
				cout << "\nnie znaleziono\n\n";
			break;
		case '6':
			tablica->print();
			cout << "\n\n";
			break;
		default:;
		}

		if (choice == 'q')
			break;
	}

	delete tablica;
}

char showListMenu()
{
	cout << "Menu struktury 'lista':\n"
		<< " 1 - dodaj elementy z pliku\n"
		<< " 2 - dodaj nowy element\n"
		<< " 3 - usun wartosc\n"
		<< " 4 - znajdz wartosc\n"
		<< " 5 - wyswietl strukture\n"
		<< " q - wyjscie do menu\n\n";

	return _getch();
}

void manageListMenu()
{
	char choice;
	int index, data;
	char *str_plik;
	ifstream plik;
	Lista* lista = new Lista();

	while (true)
	{
		choice = showListMenu();

		switch (choice)
		{
		case '1':
			str_plik = new char[30];
			cout << "Podaj nazwe pliku (razem z rozszerzeniem .txt): ";
			cin >> str_plik;
			plik.open(str_plik);
			if (plik)
			{
				plik.clear();
				plik.seekg(ios::beg);

				lista->makenull();
				plik >> data;	//pobranie rozmiaru struktury (pominiecie - nie potrzebne)

				while (!plik.eof())
				{
					plik >> data;
					lista->insert(0, data, true);
				}

				plik.close();
				cout << "\nzaladowano dane do struktury\n\n";
			}
			else
				cout << "\nnie udalo sie wczytac danych z pliku (sprawdz czy plik istnieje)\n\n";

			delete str_plik;
			break;
		case '2':
			cout << "wartosc za ktora wstawic element: "; cin >> index;
			cout << "dane: "; cin >> data;
			lista->insert(index, data);
			cout << "\ndodano nowy element\n\n";
			break;
		case '3':
			cout << "liczba do usuniecia: "; cin >> data;
			if ( lista->remove(data) )
				cout << "\nusunieto element\n\n";
			else
				cout << "\nnie odnaleziono elementu o zadanej wartosci\n\n";
			break;
		case '4':
			cout << "szukana wartosc: "; cin >> data;
			if (lista->find(data))
				cout << "\nznaleziono";
			else
				cout << "\nnie znaleziono";
			cout << "\n\n";
			break;
		case '5':
			lista->print();
			cout << "\n\n";
			break;
		default:;
		}

		if (choice == 'q')
			break;
	}

	delete lista;
}

char showHeapMenu()
{
	cout << "Menu struktury 'kopiec binarny':\n"
		<< " 1 - dodaj elementy z pliku\n"
		<< " 2 - dodaj nowy element\n"
		<< " 3 - usun wartosc\n"
		<< " 4 - znajdz wartosc\n"
		<< " 5 - zdejmij korzen\n"
		<< " 6 - wyswietl strukture\n"
		<< " q - wyjscie do menu\n\n";

	return _getch();
}

void manageHeapMenu()
{
	char choice;
	int index, data;
	char *str_plik;
	ifstream plik;
	KopiecBinarny* kopiec = new KopiecBinarny(); 
	int* i;

	while (true)
	{
		choice = showHeapMenu();

		switch (choice)
		{
		case '1':
			str_plik = new char[30];
			cout << "Podaj nazwe pliku (razem z rozszerzeniem .txt): ";
			cin >> str_plik;
			plik.open(str_plik);
			if (plik)
			{
				plik.clear();
				plik.seekg(ios::beg);

				delete kopiec;
				kopiec = new KopiecBinarny();
				plik >> data;	//pobranie rozmiaru struktury (pominiecie - nie potrzebne)

				while (!plik.eof())
				{
					plik >> data;
					kopiec->push(data);
				}

				plik.close();
				cout << "\nzaladowano dane do struktury\n\n";
			}
			else
				cout << "\nnie udalo sie wczytac danych z pliku (sprawdz czy plik istnieje)\n\n";

			delete str_plik;
			break;
		case '2':
			cout << "dane: "; cin >> data;
			kopiec->push(data);
			cout << "\ndodano nowy element\n\n";
			cout << endl;
			break;
		case '3':
			cout << "liczba do usuniecia: "; cin >> data;
			if (kopiec->usunWybrany(data))
				cout << "\nusunieto element\n\n";
			else
				cout << "\nnie udalo sie usunac elementu\n\n";
			cout << endl;
			break;
		case '4':
			cout << "szukana wartosc: "; cin >> data;
			index = kopiec->find(data);
			if (index)
				cout << "\nznaleziono";
			else
				cout << "\nnie znaleziono";
			cout << "\n\n";
			break;
		case '5':
			i = kopiec->pop();
			if (i != NULL)
				cout << *i << "\n\n";
			else
				cout << "\nkopiec jest pusty\n\n";
			break;
		case '6':
			kopiec->print();
			cout << "\n\n";
			break;
		default:;
		}

		if (choice == 'q')
			break;
	}

	delete kopiec;
}

char showTreeMenu()
{
	cout << "Menu struktury 'drzewo czerwono-czarne':\n"
		<< " 1 - dodaj elementy z pliku\n"
		<< " 2 - dodaj nowy element\n"
		<< " 3 - usun wartosc\n"
		<< " 4 - znajdz wartosc\n"
		<< " 5 - wyswietl strukture\n"
		<< " q - wyjscie do menu\n\n";

	return _getch();
}

void manageTreeMenu()
{
	char choice;
	int index, data;
	char *str_plik;
	ifstream plik;
	DrzewoCzerCzar *drzewo = new DrzewoCzerCzar();
	int* i; Node *t;

	while (true)
	{
		choice = showTreeMenu();

		switch (choice)
		{
		case '1':
			str_plik = new char[30];
			cout << "Podaj nazwe pliku (razem z rozszerzeniem .txt): ";
			cin >> str_plik;
			plik.open(str_plik);
			if (plik)
			{
				plik.clear();
				plik.seekg(ios::beg);

				delete drzewo;
				drzewo = new DrzewoCzerCzar();
				plik >> data;	//pobranie rozmiaru struktury (pominiecie - nie potrzebne)

				while (!plik.eof())
				{
					plik >> data;
					drzewo->insert(data);
				}

				plik.close();
				cout << "\nzaladowano dane do struktury\n\n";
			}
			else
				cout << "\nnie udalo sie wczytac danych z pliku (sprawdz czy plik istnieje)\n\n";

			delete str_plik;
			break;
		case '2':
			cout << "dane: "; cin >> data;
			drzewo->insert(data);
			cout << "\ndodano nowy element\n\n";
			break;
		case '3':
			cout << "liczba do usuniecia: "; cin >> data;
			if (drzewo->remove(data))
				cout << "\nusunieto element\n\n";
			else
				cout << "\nbrak takiego elementu w drzewie\n\n";
			break;
		case '4':
			cout << "szukana wartosc: "; cin >> data;
			t = drzewo->find(data);
			if (t)
				cout << "\nznaleziono";
			else
				cout << "\nie znaleziono";
			cout << "\n\n";
			break;
		case '5':
			drzewo->print();
			cout << "\n\n";
			break;
		default:;
		}

		if (choice == 'q')
			break;
	}

	delete drzewo;
}