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
};

int main()
{
	Calatorie c1("Elvetia");
	cout << "Calatoria a fost creata cu succes!!" << endl;
	return 0;
}