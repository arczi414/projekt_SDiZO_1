#ifndef _POMAIRY_H_
#define _POMIARY_H_

/*
	Naglowek zawiera deklaracje funkcji pomiarowych.
*/

// T A B L I C A
void pomiarTabDodPoczatek(std::string);
void pomiarTabDodKoniec(std::string);
void pomiarTabDodRand(std::string);

void pomiarTabUsuwPoczatek(std::string);
void pomiarTabUsuwKoniec(std::string);
void pomiarTabUsuwRand(std::string);

void pomiarTabZnajdz(std::string);

// L I S T A
void pomiarListaDodPoczatek(std::string);
void pomiarListaDodKoniec(std::string);
void pomiarListaDodRand(std::string);

void pomiarListaUsuwPoczatek(std::string);
void pomiarListaUsuwKoniec(std::string);
void pomiarListaUsuwRand(std::string);

void pomiarListaZnajdz(std::string);

// K O P I E C
void pomiarKopiecDodaj(std::string);
void pomiarKopiecUsun(std::string);
void pomiarKopiecZnajdz(std::string);

// D R Z E W O   C Z E R W. - C Z A R N.
void pomiarDrzewoDodaj(std::string);
void pomiarDrzewoUsun(std::string);
void pomiarDrzewoZnajdz(std::string);

#endif