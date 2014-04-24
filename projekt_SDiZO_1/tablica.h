class Tablica
{
private:
	int *tablica;		// wskaznik na tablice
	unsigned int n;		// rozmiar tablicy

public:
	void create(int);			// tworzy tablice o zadanej liczbie elementow
	void destroy();				// usuwa tablice
	int read(int);				// odczytuje element z tablicy z podanego miejsca
	bool write(int, int);		// zapisuje element do tablicy (index, wartosc)
	void add(int, int);			// dodaje nowy element do tablicy
	bool deleteData(int);		// usuwa element o zadanym indeksie
	int find(int);				// szuka czy w tablicy istnieje zadany element, jesli tak - zwraca index, jesli nie zwraca -1
	void print();
};