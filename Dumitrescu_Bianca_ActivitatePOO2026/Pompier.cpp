
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum Functie {
    servant,
    sefFormatie,
    voluntar,
    sofer,
};

class Pompier {
private:
    const int idPompier;
    char* nume;
    Functie functie;
    int nrInterventii;
    float* durate;

public:
    static int nrPompieri; // variabila comuna clasei, pe care o voi folosi pt generarea identificatorilor

    Pompier() :idPompier(++nrPompieri) {
        this->nume = nullptr;
        this->functie = servant;
        this->nrInterventii = 0;
        this->durate = nullptr;
    }

    Pompier(const char* nume, Functie functie)
        : idPompier(++nrPompieri) {

        this->nume = new char[strlen(nume) + 1];
        strcpy_s(this->nume, strlen(nume) + 1, nume);

        this->functie = functie;
        this->nrInterventii = 0;
        this->durate = nullptr;
    }

    Pompier(const Pompier& copie)
        : idPompier(++nrPompieri) {

        this->functie = copie.functie;
        this->nrInterventii = copie.nrInterventii;

        if (copie.nume != nullptr) {
            size_t dim = strlen(copie.nume) + 1;
            this->nume = new char[dim];
            strcpy_s(this->nume, dim, copie.nume);
        }
        else {
            this->nume = nullptr;
        }

        if (copie.durate != nullptr && copie.nrInterventii > 0) {
            this->durate = new float[this->nrInterventii];

            for (int i = 0; i < this->nrInterventii; i++) {
                this->durate[i] = copie.durate[i];
            }
        }
        else {
            this->durate = nullptr;
        }
    }

    ~Pompier() {    // Destructor
        delete[] this->nume;
        delete[] this->durate;
    }

    // EXERCITIUL 4 - Operatorul de afisare
    friend ostream& operator<<(ostream& out, const Pompier& p) {
        out << endl << "ID Pompier: " << p.idPompier;

        out << endl << "Nume: ";
        if (p.nume != nullptr) {
            out << p.nume;
        }
        else {
            out << "Necunoscut";
        }

        out << endl << "Functie: ";
        switch (p.functie) {
        case servant:
            out << "Servant";
            break;
        case sefFormatie:
            out << "Sef formatie";
            break;
        case voluntar:
            out << "Voluntar";
            break;
        case sofer:
            out << "Sofer";
            break;
        }

        out << endl << "Numar interventii: " << p.nrInterventii;

        if (p.durate != nullptr && p.nrInterventii > 0) {
            out << endl << "Durate interventii: ";
            for (int i = 0; i < p.nrInterventii; i++) {
                out << p.durate[i] << " ore ";
            }
        }

        return out;
    }
};

int Pompier::nrPompieri = 0;

int main() {

    Pompier p1;
    Pompier p2;
    Pompier p3;

    cout << "Numar pompieri: "
        << Pompier::nrPompieri << endl;

    Pompier p4("ION Marius", sofer);

    cout << "Numar pompieri dupa p4: "
        << Pompier::nrPompieri << endl;

    Pompier p5 = p4;

    cout << "Numar pompieri dupa copiere: "
        << Pompier::nrPompieri << endl;

    cout << endl << "Afisare pompier p4:";
    cout << p4;

    cout << endl << "Afisare pompier p5:";
    cout << p5;

    return 0;
}
