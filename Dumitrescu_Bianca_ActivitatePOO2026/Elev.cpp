#include <iostream>
#include <string>

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
		this->note= nullptr;
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
};
int Elev::nrElevi = 0;

int main()
{
	Elev e1;
	float noteElev[] = { 8,10,9 };
	Elev e2("Andrei", 3, noteElev);
	cout << "Numar elevi: " << Elev::nrElevi << endl;
	return 0;
}