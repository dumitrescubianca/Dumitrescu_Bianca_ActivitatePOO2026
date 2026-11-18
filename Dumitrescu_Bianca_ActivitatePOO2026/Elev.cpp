#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Elev {
private:
	const int idElev;
	string nume;
	int nrNote;
	float* note;

public:
	static int nrElevi;
	Elev() : idElev(++nrElevi)
	{
		this->nume = "Necunoscut";
		this->nrNote = 0;
		this->note = nullptr;
	}

	Elev(string nume, int nrNote, float* note)
		: idElev(++nrElevi) {

		this->nume = nume;
		this->nrNote = nrNote;

		if (nrNote > 0 && note != nullptr) {
			this->note = new float[nrNote];

			for (int i = 0; i < nrNote; i++) {
				this->note[i] = note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}
	}

	Elev(const Elev& copie) : idElev(++nrElevi) {
		this->nume = copie.nume;
		this->nrNote = copie.nrNote;

		if (copie.note != nullptr) {
			this->note = new float[this->nrNote];

			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = copie.note[i];
			}
		}
		else {
			this->note = nullptr;
		}
	}


	Elev& operator=(const Elev& copie) {
		if (this != &copie) {
			float* noteNoi = nullptr;

			if (copie.note != nullptr && copie.nrNote > 0) {
				noteNoi = new float[copie.nrNote];

				for (int i = 0; i < copie.nrNote; i++) {
					noteNoi[i] = copie.note[i];
				}
			}

			delete[] this->note;

			this->nume = copie.nume;
			this->nrNote = copie.nrNote;
			this->note = noteNoi;
		}

		return *this;
	}

	~Elev() {
		delete[] this->note;
	}


	int getNrNote() {
		return this->nrNote;
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string numeNou) {
		this->nume = numeNou;
	}

	bool operator<(const Elev& e) {
		return this->nrNote < e.nrNote;
	}

	void operator+=(float notaNoua) {
		if (notaNoua < 1 || notaNoua > 10) {
			throw exception("Nota invalida!");
		}

		float* noteNoi = new float[this->nrNote + 1];

		for (int i = 0; i < this->nrNote; i++) {
			noteNoi[i] = this->note[i];
		}

		noteNoi[this->nrNote] = notaNoua;

		delete[] this->note;

		this->note = noteNoi;
		this->nrNote++;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrNote) {
			return this->note[index];
		}
		else {
			throw exception("Index invalid!");
		}
	}

	float operator()(int start, int stop) {
		if (start < 0 || stop >= this->nrNote || start > stop) {
			throw exception("Interval invalid!");
		}

		float suma = 0;

		for (int i = start; i <= stop; i++) {
			suma += this->note[i];
		}

		return suma / (stop - start + 1);
	}

	friend ostream& operator<<(ostream& out, const Elev& e) {
		out << endl << "ID Elev: " << e.idElev;
		out << endl << "Nume: " << e.nume;
		out << endl << "Numar note: " << e.nrNote;
		out << endl << "Note: ";

		for (int i = 0; i < e.nrNote; i++) {
			out << e.note[i] << " ";
		}

		return out;
	}

};
int Elev::nrElevi = 0;


int main()
{
	Elev e1;
	float noteElev[] = { 8,10,9 };
	Elev e2("Andrei", 3, noteElev);
	cout << "Numar elevi: " << Elev::nrElevi << endl;
	Elev e3 = e2;
	cout << endl << "Copie elev:" << e3;

	e1 = e2;
	cout << endl << "Dupa atribuire:" << e1;

	cout << endl << "Numar note: " << e2.getNrNote();

	e1.setNume("Maria");
	cout << endl << "Nume modificat: " << e1.getNume();

	if (e1 < e2) {
		cout << endl << "e1 are mai putine note";
	}
	else {
		cout << endl << "e1 nu are mai putine note";
	}

	e2 += 10;
	cout << endl << "Dupa adaugarea notei:" << e2;

	e2[0] = 7;
	cout << endl << "Prima nota: " << e2[0];

	try {
		cout << endl << "Media notelor 0-2: " << e2(0, 2);
		cout << endl << "Media notelor 1-3: " << e2(1, 3);
		cout << endl << "Media notelor 0-10: " << e2(0, 10);
	}
	catch (const exception& ex) {
		cout << endl << "Eroare: " << ex.what();
	}

	return 0;
}