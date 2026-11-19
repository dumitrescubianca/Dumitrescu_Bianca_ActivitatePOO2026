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
	magazinCraciun(int idMagazin, string denumire, int nrProduse, float* preturi):idMagazin(idMagazin)
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
};