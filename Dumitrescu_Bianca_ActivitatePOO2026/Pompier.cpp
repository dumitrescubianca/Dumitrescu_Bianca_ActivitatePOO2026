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
	Pompier(const char* nume, Functie functie)
		: idPompier(++nrPompieri) {

		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

		this->functie = functie;
		this->nrInterventii = 0;
		this->durate = nullptr;

	}

	Pompier(const Pompier& copie)
		: idPompier(++nrPompieri) {

		this->functie = copie.functie;
		this->nrInterventii = copie.nrInterventii;

		if (copie.nume != nullptr) {
			size_t dim = strlen(copie.nume) + 1;
			this->nume = new char[dim];
			strcpy_s(this->nume, dim, copie.nume);
		}
		else {
			this->nume = nullptr;
		}

		if (copie.durate != nullptr && copie.nrInterventii > 0) {
			this->durate = new float[this->nrInterventii];

			for (int i = 0; i < this->nrInterventii; i++) {
				this->durate[i] = copie.durate[i];
			}
		}
		else {
			this->durate = nullptr;
		}
	}

	~Pompier() {   	//  Destructor

		delete[] this->nume;
		delete[] this->durate;
	}
};

int Pompier::nrPompieri = 0;

int main() {
	Pompier p1;
	Pompier p2;
	Pompier p3;
	Pompier p4("ION Marius", sofer);

	Pompier p5 = p4;

	cout << endl << "Numar pompieri: "
		<< Pompier::nrPompieri;

	cout << "Numar pompieri: " << Pompier::nrPompieri;

	return 0;
}

