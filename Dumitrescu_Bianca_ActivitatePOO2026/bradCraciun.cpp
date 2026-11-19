#include <iostream>
#include <cstring>

using namespace std;

class bradCraciun {
private:
	int idBrad;
	char* numeBrad;
public: 
	bradCraciun(const char* nume)
		: idBrad(1) {
		this->numeBrad = new char[strlen(nume) + 1];
		strcpy_s(this->numeBrad, strlen(nume) + 1, nume);
	}

	bradCraciun() {
		delete[]this->numeBrad;
	}
	int getIdBrad() {
		return this->idBrad;
	}
	void setNumeBrad(const char* numeNou) {
		if (numeNou != nullptr) {
			int dim = strlen(numeNou) + 1;
			char* denumireNoua = new char[dim];
			strcpy_s(denumireNoua, dim, numeNou);
			delete[] this->numeBrad;
			this->numeBrad = denumireNoua;
		}
	}
	bradCraciun&operator = (const bradCraciun & b){
		if (this != &b) {
			this->setNumeBrad(b.numeBrad);
		}
		return *this;
	}
	
	bool operator<(const bradCraciun& b) {
		return strlen(this->numeBrad) < strlen(b.numeBrad);
	}

	bradCraciun& operator+=(const  char* text){
		if (text != nullptr) {

		}
	}
};

int main()
{
	bradCraciun b1("Brad cu zapada");
	cout << "Bradul a fost creat cu succes" << endl; 
	cout << "ID Brad:" << b1.getIdBrad() << endl;

	b1.setNumeBrad("Brad rosu");
	cout << "Denumirea bradului a fost modificat cu succes!" << endl;

	bradCraciun b2("Brad cu globuri");
	b1 = b2;
	cout << "Operatorul = a fost aplicat." << endl;

	bradCraciun b3("Brad CLASIC");
	bradCraciun b4("Brad cu luminite");

	if (b3 < b4) {
		cout << "Primul brad are numele mai scurt." << endl;
	}
	else {
		cout << "Al doilea brad are numele mai scurt." << endl;
	}
	return 0;
}