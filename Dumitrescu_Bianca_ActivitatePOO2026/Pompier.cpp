#include <iostream>
#include <string>
#include <cstring>


using namespace std;

enum Functie {
	servant,
	sefPromotie,
	voluntar,
	sofer,
};

class Pompier {
private:
	const int idPompier; 
	char* nume;
	Functie functie;
	int nrInterventii;
	float* durate;

public:
	static int nrPompieri; // variabilă comună clasei, pe care o voi folosi pt generarea identificatorilor

	Pompier() :idPompier(++nrPompieri){
	this->nume = nullptr;
	this->functie = servant;
	this->nrInterventii = 0;
	this->durate = nullptr;
	}
};
int Pompier::nrPompieri = 0;

int main() {
	Pompier p1;
	Pompier p2;
	Pompier p3;

	cout << "Numar pompieri: " << Pompier::nrPompieri;

	return 0;
}

