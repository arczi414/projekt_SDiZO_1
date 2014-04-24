#include "stdafx.h"
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include "menu.h"
#include "tablica.h"
#include "lista.h"
#include "kopiecBinarny.h"
#include "drzewoCzerCzar.h"
#include "stoper.h"
#include "pomiary.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	manageMenu();

	/* **********************************
	         P  O  M  I  A  R  Y
	 ********************************** */
	
	// T A B L I C A

	//pomiarTabDodPoczatek("tab_dodaj_poczatek.txt");
	//pomiarTabDodKoniec("tab_dodaj_koniec.txt");
	//pomiarTabDodRand("tab_dodaj_rand.txt");
	//pomiarTabUsuwPoczatek("tab_usun_poczatek.txt");
	//pomiarTabUsuwKoniec("tab_usun_koniec.txt");
	//pomiarTabUsuwRand("tab_usun_rand.txt");
	//pomiarTabZnajdz("tab_znajdz.txt");
	
	// L I S T A
	
	//pomiarListaDodPoczatek("lista_dodaj_poczatek.txt");
	//pomiarListaDodKoniec("lista_dodaj_koniec.txt");
	//pomiarListaZnajdz("lista_znajdz.txt");
	//pomiarListaDodRand("lista_dodaj_random.txt");
	//pomiarListaUsuwPoczatek("lista_usun_poczatek.txt");
	//pomiarListaUsuwKoniec("lista_usun_koniec.txt");
	//pomiarListaUsuwRand("lista_usun_rand.txt");


	// K O P I E C   B I N A R N Y

	//pomiarKopiecDodaj("kopiec_dodaj.txt");
	//pomiarKopiecUsun("kopiec_usun.txt");
	//pomiarKopiecZnajdz("kopiec_znajdz.txt");

	// D R Z E W O   C Z E R W. - C Z A R.

	//pomiarDrzewoDodaj("drzewo_dodaj.txt");
	//pomiarDrzewoUsun("drzewo_usun.txt");
	//pomiarDrzewoZnajdz("drzewo_znajdz.txt");

	cout << "Wcisnij dowolny klawisz, aby zakonczyc program.";
	_getch();
	return 0;
}
