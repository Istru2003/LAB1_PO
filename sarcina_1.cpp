#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string nume;
    string specialitate;
    int an;
    double media;

    Student(const string& nume, const string& specialitate, int an, double media)
        : nume(nume), specialitate(specialitate), an(an), media(media) {}

    // Funcții de setare
    void setNume(const string& newNume) {
        nume = newNume;
    }

    void setSpecialitate(const string& newSpecialitate) {
        specialitate = newSpecialitate;
    }

    void setAn(int newAn) {
        an = newAn;
    }

    void setMedia(double newMedia) {
        media = newMedia;
    }

    // Modificare a datelor
    void incrementeazaAn() {
        an++;
    }

    void cresteMedia(double increment) {
        media += increment;
    }
};

//Funcția de comparație
bool comparareStudenti(const Student& a, const Student& b) {
    if (a.specialitate != b.specialitate) {
        return a.specialitate < b.specialitate;
    } else {
        return a.media > b.media;
    }
}

int main() {
    Student student1("Jhon", "Informatica", 2, 9.5);
    Student student2("Alice", "Matematica", 3, 8.7);
    Student student3("Alex", "Informatica", 2, 8.0);

    vector<Student> listaStudenti = {student1, student2, student3};

    sort(listaStudenti.begin(), listaStudenti.end(), comparareStudenti);

    for (const Student& student : listaStudenti) {
        cout << "Nume: " << student.nume << endl;
        cout << "Specialitate: " << student.specialitate << endl;
        cout << "Anul de studii: " << student.an << endl;
        cout << "Media: " << student.media << endl;
        cout << endl;
    }

    int optiune;
    bool auFostModificari = false;

    cout << "Doriti sa modificati anul de studii sau media al unui student? (1 - da, 0 - nu): ";
    cin >> optiune;

       while (optiune) {

        cout << "Anul de studii sau media? (1 - an, 0 - media): ";
        cin >> optiune;
        int numarStudent;

        if (optiune == 1) {
            cout << "Introduceti numarul studentului pentru a aplica incrementeaza An (0 - student1, 1 - student2, etc.): ";
            cin >> numarStudent;

            if (numarStudent >= 0 && numarStudent < listaStudenti.size()) {
                listaStudenti[numarStudent].incrementeazaAn();
                auFostModificari = true;
            } else {
                cout << "Numarul studentului introdus nu este valid." << endl;
            }
        } else if (optiune == 0) {
            cout << "Introduceti numarul studentului pentru a aplica cresterea Media (0 - student1, 1 - student2, etc.): ";
            cin >> numarStudent;

            if (numarStudent >= 0 && numarStudent < listaStudenti.size()) {
                double incrementMedia;
                cout << "Introduceti valoarea cu care sa cresteti media: ";
                cin >> incrementMedia;
                listaStudenti[numarStudent].cresteMedia(incrementMedia);
                auFostModificari = true;
            } else {
                cout << "Numarul studentului introdus nu este valid." << endl;
            }
        }

        cout << "\nDoriti sa modificati alt student? (1 - da, 0 - nu): ";
        cin >> optiune;
    }

    if (auFostModificari) {
        sort(listaStudenti.begin(), listaStudenti.end(), comparareStudenti);

        cout << "\nLista de studenti actualizata:" << endl;
        for (const Student& student : listaStudenti) {
            cout << "Nume: " << student.nume << endl;
            cout << "Specialitate: " << student.specialitate << endl;
            cout << "Anul de studii: " << student.an << endl;
            cout << "Media: " << student.media << endl;
            cout << endl;
        }
    }

    return 0;
}
