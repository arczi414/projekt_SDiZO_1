#include "stdafx.h"
#include "pomiary.h"
#include "stoper.h"
#include "tablica.h"
#include "lista.h"
#include "kopiecBinarny.h"
#include "drzewoCzerCzar.h"
#include <cstdlib>
#include <time.h>

using namespace std;

// T A B L I C A
void pomiarTabDodPoczatek(string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	Tablica *tab = new Tablica();
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 100;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;

	// dodawanie na poczatku
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarTabDodPoczatek dla n = " << n << endl;

		for (int i = 0; i < n; i++)
			tab->add(0, rand());

		for (int i = 0; i < iloscJedn; i++)
		{
			st.start();
			tab->add(0, rand());
			st.stop();
			sredniaPomiaru += st.inMicrosec();
			tab->deleteData(0);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
		tab->destroy();
	}
	st.closeFile();
	std::cout << endl;
}

void pomiarTabDodKoniec(string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	Tablica *tab = new Tablica();
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 100;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;

	// dodawanie na poczatku
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarTabDodKoniec dla n = " << n << endl;

		for (int i = 0; i < n; i++)
			tab->add(0, rand());

		for (int i = 0; i < iloscJedn; i++)
		{
			st.start();
			tab->add(n-1, rand());
			st.stop();
			sredniaPomiaru += st.inMicrosec();
			tab->deleteData(0);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
		tab->destroy();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarTabDodRand(string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	Tablica *tab = new Tablica();
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 100;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;

	// dodawanie na poczatku
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarTabDodRand dla n = " << n << endl;

		for (int i = 0; i < n; i++)
			tab->add(rand()%(n-1), rand());

		for (int i = 0; i < iloscJedn; i++)
		{
			st.start();
			tab->add(0, rand());
			st.stop();
			sredniaPomiaru += st.inMicrosec();
			tab->deleteData(0);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
		tab->destroy();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarTabUsuwPoczatek(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	Tablica *tab = new Tablica();
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 100;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;

	// usuwanie z poczatku
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarTabUsuwPoczatek dla n = " << n << endl;

		for (int i = 0; i < n; i++)
			tab->add(0, rand());

		for (int i = 0; i < iloscJedn; i++)
		{
			st.start();
			tab->deleteData(0);
			st.stop();
			sredniaPomiaru += st.inMicrosec();
			tab->add(0, rand());
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
		tab->destroy();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarTabUsuwKoniec(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	Tablica *tab = new Tablica();
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 100;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;

	// usuwanie z konca
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarTabUsuwKoniec dla n = " << n << endl;

		for (int i = 0; i < n; i++)
			tab->add(0, rand());

		for (int i = 0; i < iloscJedn; i++)
		{
			st.start();
			tab->deleteData(n-1);
			st.stop();
			sredniaPomiaru += st.inMicrosec();
			tab->add(0, rand());
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
		tab->destroy();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarTabUsuwRand(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	Tablica *tab = new Tablica();
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 1000;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarTabUsuwRand dla n = " << n << endl;

		for (int i = 0; i < n; i++)
			tab->add(0, rand());

		for (int i = 0; i < iloscJedn; i++)
		{
			st.start();
			tab->deleteData(rand()%(n-1));
			st.stop();
			sredniaPomiaru += st.inMicrosec();
			tab->add(0, rand());
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
		tab->destroy();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarTabZnajdz(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	Tablica *tab = new Tablica();
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 10000;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarTabZnajdz dla n = " << n << endl;

		for (int i = 0; i < n-1; i++)
			tab->add(0, rand());

		int szukany;

		for (int i = 0; i < iloscJedn; i++)
		{
			szukany = rand();
			tab->add(rand() % (n - 1), szukany);
			st.start();
			tab->find(szukany);
			st.stop();
			sredniaPomiaru += st.inMicrosec();
			tab->deleteData(0);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
		tab->destroy();
	}
	st.closeFile();

	std::cout << endl;
}

// L I S T A
void pomiarListaDodPoczatek(string plik)
{
	Stoper st;
	srand(time(NULL));

	Lista *ls = new Lista();

	// inicjalizacja
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;					// aktualny rozmiar
	int iloscJedn = 100;		// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	int wstaw;

	// dodawanie na poczatku
	while (n < max)
	{
		sredniaPomiaru = 0;

		ls->makenull();

		for (int i = 0; i < n; i++)
			ls->insert(0, rand(), true);

		cout << "pomiarListaDodPoczatek dla n = " << n << endl;

		for (int i = 0; i < iloscJedn; i++)
		{
			wstaw = rand();

			st.start();
				ls->insert(0, wstaw, true);
			st.stop();

			sredniaPomiaru += st.inMicrosec();
			ls->remove(wstaw);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarListaDodKoniec(string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 500;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	int wstaw; int *ostatnia = NULL;

	// dodawanie na poczatku
	while (n < max)
	{
		Lista *ls = new Lista();

		sredniaPomiaru = 0;

		for (int i = 0; i < n; i++)
			ls->insert(-1, i);

		cout << "pomiarListaDodKoniec dla n = " << n << endl;

		for (int i = 0; i < iloscJedn; i++)
		{
			wstaw = rand();

			st.start();
				ls->insert(0, wstaw);
			st.stop();

			sredniaPomiaru += st.inMicrosec();
			ls->remove(wstaw);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;

		ls->makenull();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarListaDodRand(string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica

	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 1000;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	int wstaw; int *ostatnia = NULL;

	// dodawanie na poczatku
	while (n < max)
	{
		Lista *ls = new Lista();

		sredniaPomiaru = 0;

		for (int i = 0; i < n; i++)
			ls->insert(-1, i);

		cout << "pomiarListaDodRand dla n = " << n << endl;

		for (int i = 0; i < iloscJedn; i++)
		{
			wstaw = rand();

			st.start();
			ls->insert(rand()%n, wstaw);
			st.stop();

			sredniaPomiaru += st.inMicrosec();
			ls->remove(wstaw);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;

		ls->makenull();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarListaUsuwPoczatek(string plik)
{
	Stoper st;
	srand(time(NULL));

	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 100;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	int wstaw; int *ostatnia = NULL;


	while (n < max)
	{
		Lista *ls = new Lista();

		sredniaPomiaru = 0;

		for (int i = 0; i < n; i++)
			ls->insert(-1, i);

		cout << "pomiarListaUsuwPoczatek dla n = " << n << endl;

		for (int i = 0; i < iloscJedn; i++)
		{
			st.start();
				ls->remove(n - 1);
			st.stop();

			sredniaPomiaru += st.inMicrosec();
			ls->insert(-1, n - 1);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;

		ls->makenull();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarListaUsuwKoniec(string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica

	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 500;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	int wstaw; int *ostatnia = NULL;

	// dodawanie na poczatku
	while (n < max)
	{
		Lista *ls = new Lista();

		sredniaPomiaru = 0;

		for (int i = 0; i < n; i++)
			ls->insert(-1, i);

		cout << "pomiarListaDodKoniec dla n = " << n << endl;

		for (int i = 0; i < iloscJedn; i++)
		{
			st.start();
			ls->remove(0);
			st.stop();

			sredniaPomiaru += st.inMicrosec();
			ls->insert(1, 0);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;

		ls->makenull();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarListaUsuwRand(string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica

	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 1000;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	int usun;

	// dodawanie na poczatku
	while (n < max)
	{
		Lista *ls = new Lista();

		sredniaPomiaru = 0;

		for (int i = 0; i < n; i++)
			ls->insert(-1, i);

		cout << "pomiarListaDodRand dla n = " << n << endl;

		for (int i = 0; i < iloscJedn; i++)
		{
			usun = rand() % n;

			st.start();
				ls->remove(rand() % n);
			st.stop();

			sredniaPomiaru += st.inMicrosec();
			ls->insert(usun + 1, usun);
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;

		ls->makenull();
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarListaZnajdz(string plik)
{
	Stoper st;
	srand(time(NULL));

	Lista *ls = new Lista();

	// inicjalizacja
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;					// aktualny rozmiar
	int iloscJedn = 1000;		// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru; int *szukany;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarTabZnajdz dla n = " << n << endl;

		for (int i = 0; i < n - 1; i++)
			ls->insert(0, rand());

		for (int i = 0; i < iloscJedn; i++)
		{
			ls->reset(rand() % n);
			szukany = ls->next();

			st.start();
				ls->find(*szukany);
			st.stop();

			sredniaPomiaru += st.inMicrosec();
		}
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);
		n += 500;
		ls->makenull();
	}
	st.closeFile();

	std::cout << endl;
}

// K O P I E C
void pomiarKopiecDodaj(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica
	
	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 200;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	double* pomiarWewn = new double();
	int x;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		KopiecBinarny *kopiec = new KopiecBinarny();

		sredniaPomiaru = 0;

		cout << "pomiarKopiecDodaj dla n = " << n << endl;

		if (n>200)
		{
			for (int i = 0; i < n - 1; i++)
				kopiec->push(rand() % 100);

			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand() % 100 + 1000;
				kopiec->push(x, pomiarWewn);
				sredniaPomiaru += *pomiarWewn;
				kopiec->pop();
			}

			n += 1000;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
			delete kopiec;
		}
		else
		{
			for (int i = 0; i < n - 1; i++)
				kopiec->push(rand() % 100);

			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand() % 100 + 1000;
				kopiec->push(x, pomiarWewn);
				sredniaPomiaru += *pomiarWewn;
				kopiec->pop();
			}

			n += 10;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
			delete kopiec;
		}
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarKopiecUsun(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica

	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 100;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	double* pomiarWewn = new double();
	int x;

	KopiecBinarny *kopiec;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		cout << "pomiarKopiecUsun dla n = " << n << endl;
		sredniaPomiaru = 0;

		// nowa populacja
		kopiec = new KopiecBinarny();
		for (int i = 0; i < n; i++)
			kopiec->push(rand());

		if (n < 500)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				// pomiar
				kopiec->pop(pomiarWewn);
				sredniaPomiaru += *pomiarWewn;	
			}

			n += 20;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				// pomiar
				kopiec->pop(pomiarWewn);
				sredniaPomiaru += *pomiarWewn;
			}

			n += 500;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}

		delete kopiec;
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarKopiecZnajdz(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica

	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;			// aktualny rozmiar
	int iloscJedn = 500;	// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	double* pomiarWewn = new double();
	int x;
	KopiecBinarny *kopiec;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		cout << "pomiarKopiecZnajdz dla n = " << n << endl;
		sredniaPomiaru = 0;

		kopiec = new KopiecBinarny();
		for (int i = 0; i < n; i++)
			kopiec->push(i);

		for (int i = 0; i < iloscJedn; i++)
		{
			x = rand() % n;
			// pomiar
			st.start();
			kopiec->find(x);
			st.stop();

			sredniaPomiaru += st.inMicrosec();
		}

		n += 500;
		sredniaPomiaru /= iloscJedn;
		st.saveScore(sredniaPomiaru, n);

		delete kopiec;
	}
	st.closeFile();

	std::cout << endl;
}

// D R Z E W O   C Z E R W. - C Z A R N.
void pomiarDrzewoDodaj(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// inicjalizacja
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;					// aktualny rozmiar
	int iloscJedn = 100;		// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	double* pomiarWewn = new double();
	int x;

	DrzewoCzerCzar *drzewo;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarDrzewoDodaj dla n = " << n << endl;

		// nowa populacja
		drzewo = new DrzewoCzerCzar();
		for (int i = 0; i < n - 1; i++)
			drzewo->insert(rand());

		if (n<20)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand();
				
				st.start();
					drzewo->insert(x);
				st.stop();
				
				sredniaPomiaru += st.inMicrosec();
				drzewo->remove(x);
			}

			n += 5;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else if (n<200)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand();

				st.start();
				drzewo->insert(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();
				drzewo->remove(x);
			}

			n += 50;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else if (n<500)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand();

				st.start();
				drzewo->insert(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();
				drzewo->remove(x);
			}

			n += 100;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand();

				st.start();
					drzewo->insert(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();
				drzewo->remove(x);
			}

			n += 500;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}

		delete drzewo;
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarDrzewoUsun(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// inicjalizacja
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;					// aktualny rozmiar
	int iloscJedn = 100;		// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	double* pomiarWewn = new double();
	int x;

	DrzewoCzerCzar *drzewo;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		sredniaPomiaru = 0;

		cout << "pomiarDrzewoUsun dla n = " << n << endl;

		// nowa populacja
		drzewo = new DrzewoCzerCzar();
		for (int i = 0; i < n - 1; i++)
			drzewo->insert(rand());

		if (n<20)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand();
				drzewo->insert(x);

				st.start();
					drzewo->remove(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();
			}

			n += 5;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else if (n<200)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand();
				drzewo->insert(x);

				st.start();
				drzewo->remove(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();
			}

			n += 50;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else if (n<500)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand();
				drzewo->insert(x);

				st.start();
				drzewo->remove(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();
			}

			n += 100;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				x = rand();
				drzewo->insert(x);

				st.start();
					drzewo->remove(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();
			}

			n += 500;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}

		delete drzewo;
	}
	st.closeFile();

	std::cout << endl;
}

void pomiarDrzewoZnajdz(std::string plik)
{
	Stoper st;
	srand(time(NULL));

	// tablica

	// dodawanie elementu
	st.openFile(plik);
	int max = 20000 - 1;		// maksymalny rozmiar
	int n = 2;					// aktualny rozmiar
	int iloscJedn =100;		// liczba pomiarow pojedynczej operacji
	double sredniaPomiaru;
	double* pomiarWewn = new double();
	int x;
	DrzewoCzerCzar *drzewo;

	// usuwanie z losowego miejsca
	while (n < max)
	{
		cout << "pomiarDrzewoZnajdz dla n = " << n << endl;
		sredniaPomiaru = 0;

		if (n < 20)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				// nowa populacja
				drzewo = new DrzewoCzerCzar();
				for (int i = 0; i < n; i++)
					drzewo->insert(rand());

				x = rand();	// liczba do znalezienia
				drzewo->insert(x);

				// pomiar
				st.start();
				drzewo->find(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();

				drzewo->remove(x);
				delete drzewo;
			}

			n += 5;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else if (n < 200)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				// nowa populacja
				drzewo = new DrzewoCzerCzar();
				for (int i = 0; i < n; i++)
					drzewo->insert(rand());

				x = rand();	// liczba do znalezienia
				drzewo->insert(x);

				// pomiar
				st.start();
					drzewo->find(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();

				drzewo->remove(x);
				delete drzewo;
			}

			n += 50;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else if (n < 500)
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				// nowa populacja
				drzewo = new DrzewoCzerCzar();
				for (int i = 0; i < n; i++)
					drzewo->insert(rand());

				x = rand();	// liczba do znalezienia
				drzewo->insert(x);

				// pomiar
				st.start();
				drzewo->find(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();

				drzewo->remove(x);
				delete drzewo;
			}

			n += 100;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
		else
		{
			for (int i = 0; i < iloscJedn; i++)
			{
				// nowa populacja
				drzewo = new DrzewoCzerCzar();
				for (int i = 0; i < n; i++)
					drzewo->insert(rand());

				x = rand();	// liczba do znalezienia
				drzewo->insert(x);

				// pomiar
				st.start();
					drzewo->find(x);
				st.stop();

				sredniaPomiaru += st.inMicrosec();

				drzewo->remove(x);
				delete drzewo;
			}

			n += 500;
			sredniaPomiaru /= iloscJedn;
			st.saveScore(sredniaPomiaru, n);
		}
	}
	st.closeFile();

	std::cout << endl;
}