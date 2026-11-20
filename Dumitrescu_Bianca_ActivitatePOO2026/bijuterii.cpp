#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class bijuterie{
private:
	const int id;
	string material;
	int nrPietre;
	float* greutate;

public:
	bijuterie() :id(1) {
		this->material = "aur";
		this->nrPietre = 0;
		this->greutate = nullptr;
	}

	bijuterie(int id, string material, int nrPietre, float* greutate) :id(id) {
		this->material = material;
		if (nrPietre > 0 && greutate != nullptr) {
			this->nrPietre = nrPietre;
			this->greutate = new float[nrPietre];
			for (int i = 0;i < nrPietre;i++) {
				this->greutate[i] = greutate[i];
			}
		}
		else {
			this->nrPietre = 0;
			this->greutate = nullptr;
		}
	}
	~bijuterie() {
		delete[] this->greutate;
	}
	
	int getId() const {
		return this->id;
	}

};

int main() {
	bijuterie b1;
	
	float greutate[] = { 13.9f,23.99f,18.0f };
	bijuterie b2(3, "aur", 3,greutate);
	cout << "ID bijuterie:" << b2.getId() << endl;
}