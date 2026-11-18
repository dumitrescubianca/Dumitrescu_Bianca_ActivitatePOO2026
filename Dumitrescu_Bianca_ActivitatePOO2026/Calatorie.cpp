#include <iostream>
#include <cstring>

using namespace std;

class Calatorie {
private:
	char* numeDestinatie;
	const int idCalatorie;

public:
	Calatorie(const char* numeDestinatie)
		:idCalatorie(1) {
		this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
		strcpy_s(this->numeDestinatie, strlen(numeDestinatie) + 1, numeDestinatie);
	}

	~Calatorie(){
		delete[]this->numeDestinatie;
	}

	int getIdCalatorie()
	{
		return this->idCalatorie;
	}

	void setNumeDestinatie(const char* numeNou) {
		if (numeNou != nullptr) {
			int dim = strlen(numeNou) + 1;
			char* destinatieNoua = new char[dim];
			strcpy_s(destinatieNoua, dim, numeNou);
			delete[] this->numeDestinatie;
			this->numeDestinatie = destinatieNoua;
		}
	}
};

int main()
{
	Calatorie c1("Elvetia");
	cout << "Calatoria a fost creata cu succes!!" << endl;
	 c1.setNumeDestinatie("Romania");
	 cout << "Destinatia a fost modificata cu succes!!" << endl;
	 cout << "ID Calatorie:" << c1.getIdCalatorie() << endl;

	return 0;
}