#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class magazinOnline {
private:
	const int idMagazin;
	string denumire;
	int nrProduse;
	float* preturi;

public:
	magazinOnline() :idMagazin(1)
	{
		this->denumire = "Magazin necunoscut";
		this->nrProduse = 0;
		this->preturi = nullptr;
	}

	magazinOnline(int idMagazin, string denumire, int nrProduse, float* preturi) :idMagazin(idMagazin) {
		if (nrProduse > 0 && preturi != nullptr) {
			this->nrProduse = nrProduse;
			this->denumire = denumire;
			this->preturi = new float[nrProduse];
			for (int i = 0; i < nrProduse;i++) {
				this->preturi[i] = preturi[i];
			}
		}
		else {
			this->nrProduse = 0;
			this->preturi = nullptr;
		}
	}
	~magazinOnline() {
		delete[]this->preturi;
	}
	int getIdMagazin() const {
		return this ->idMagazin;
	}

	void setPreturi(int valoriNoi, const float* vectorNou) {
		if (valoriNoi > 0 && vectorNou != nullptr) {
			float* copie = new float[valoriNoi];
			for (int i = 0;i < valoriNoi;i++) {
				copie[i] = vectorNou[i];
			}
	
			delete[]this->preturi;
			this->preturi = copie;
			this->nrProduse = valoriNoi;
		}
	
	}
};

int main() {
	magazinOnline m1;
	float preturi[] = { 12.5f, 128.9f, 114.9f };
	magazinOnline m2(5, "magazin 1", 3, preturi);

	cout << "Id magazin:" << m2.getIdMagazin() << endl;

	float preturiNoi[] = { 55.4f,69.7f,27.8f };
	m2.setPreturi(3, preturiNoi);
	cout << "Inlocuirea vectorului fcauta cu succes" << endl;

	return 0;
}