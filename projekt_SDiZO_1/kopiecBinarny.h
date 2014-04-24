class KopiecBinarny
{
private:
	int* kopiec;
	unsigned int n;		// rozmiar kopca
	bool find(int, int);
	void printTree(int, int);

public:
	KopiecBinarny();
	~KopiecBinarny();

	void push(int, double* pomiar = NULL);
	int* pop(double* pomiar = NULL);
	bool usunWybrany(int, double* pomiar = NULL);
	bool find(int);
	void print();		// wypisanie na ekran

};