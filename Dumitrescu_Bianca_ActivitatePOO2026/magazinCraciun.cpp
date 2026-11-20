#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class magazinCraciun {
private:
	const int idMagazin;
	string denumire;
	float profit;
	int nrProduse;
	float* preturi;

public:
	//construct. implicit
	magazinCraciun() :idMagazin(1) {
		this->denumire = "Magazin principal";
		this->profit = 0;
		this->nrProduse = 0;
		this->preturi = nullptr;
	}
	// construct.cu param.
	magazinCraciun(int idMagazin, string denumire, float profit, int nrProduse, float* preturi) :idMagazin(idMagazin)
	{
			this->denumire = denumire;
			this->profit = profit;

			if (nrProduse > 0 && preturi != nullptr) {

				this->nrProduse = nrProduse;
				this->preturi = new float[nrProduse];

				for (int i = 0; i < nrProduse; i++) {
					this->preturi[i] = preturi[i];
				}
			}
			else {
				this->nrProduse = 0;
				this->preturi = nullptr;
			}
	}
	//desctructir
	~magazinCraciun() {
		delete[]this->preturi;
	}

	//get
	int getIdMagazin() const {
		return this->idMagazin;
	}
	//set
	void setPreturi(int nrNou, const float* vectorNou) {
		if (nrNou > 0 && vectorNou != nullptr) {
			float* copie = new float[nrNou];
			for (int i = 0;i < nrNou;i++) {
				copie[i] = vectorNou[i];
			}
			delete[]this->preturi;
			this->preturi = copie;
			this->nrProduse = nrNou;
		}
	}
};

int main() {
	magazinCraciun m1;
	float preturi[] = { 10.5f, 20.0f, 30.5f };

	magazinCraciun m2(2, "Magazinul Mosului",
		1500.0f, 3, preturi);
	cout << "ID magazin: " << m2.getIdMagazin() << endl;

	float preturiNoi[] = { 50.0f, 60.0f };

	m2.setPreturi(2, preturiNoi);
	cout << "SET executat!" << endl;

	return 0;
}
