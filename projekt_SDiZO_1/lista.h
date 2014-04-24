struct listElement;

class Lista
{
private:
	listElement *pointer;
	listElement *head;

	int n = 0;	// liczba elementów

public:
	Lista();

	void insert(int pop, int wstaw, bool beg = false);		// wstawia nowy element do listy
	bool remove(int usuw);			// usuwa element o zadanej wartoœci
	listElement* find(int szuk);	// szuka elementu i ustawia na nim wskaznik
	void reset(int m);				// resetuje pointer na zadany element (jest to numer porzadkowy elementu)
	int* next();					// zwraca wartosc nastepnego elementu
	int* prev();					// zwraca wartosc poprzedniego elementu
	void makenull();				// zeruje cala liste
	void print();

	// pomocnicze
	int getSize();
	bool hasNext();
	bool hasPrev();
};

struct listElement
{
	listElement(int data = 0);
	~listElement();

	int data;
	listElement *nextElement;
	listElement *prevElement;
};