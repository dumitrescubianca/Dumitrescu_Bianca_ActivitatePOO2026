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
};

int main()
{
	bradCraciun b1("Brad cu zapada");
	cout << "Bradul a fost creat cu succes" << endl; 
	cout << "ID Brad:" << b1.getIdBrad() << endl;
	return 0;
}