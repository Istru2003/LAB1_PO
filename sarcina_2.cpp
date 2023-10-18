#include <iostream>
using namespace std;

struct Vector {
    long* data;
    int size;
};

//Functia de iniţializare
void initializeVector(Vector& v, int initialSize) {
    v.size = initialSize;
    v.data = new long[initialSize];
}
// Funcția pentru obținerea elementului din vector
long& getElement(Vector& v, int index) {
    if (index >= 0 && index < v.size) {
        return v.data[index];
    }
    throw out_of_range("Index invalid");
}

// Funcția pentru calculul sumei elementelor pare din vector
long sumOfEvenElements(Vector& v) {
    long sum = 0;
    for (int i = 0; i < v.size; i++) {
        if (v.data[i] % 2 == 0) {
            sum += v.data[i];
        }
    }
    return sum;
}

// Funcția pentru adăugarea unui element la sfârșitul vectorului
void pushBack(Vector& v, long element) {

    int newSize = v.size + 1;
    long* newData = new long[newSize];

    for (int i = 0; i < v.size; i++) {
        newData[i] = v.data[i];
    }

    newData[newSize - 1] = element;

    delete[] v.data;
    v.data = newData;
    v.size = newSize;
}
// Funcția pentru eliminarea ultimului element din vector
void popBack(Vector& v) {
    if (v.size > 0) {
        int newSize = v.size - 1;
        long* newData = new long[newSize];

        for (int i = 0; i < newSize; i++) {
            newData[i] = v.data[i];
        }

        delete[] v.data;
        v.data = newData;
        v.size = newSize;
    }
}
// Funcția pentru redimensionarea vectorului
void resizeVector(Vector& v, int newSize) {
    if (newSize < 0) {
        throw invalid_argument("Dimensiunea trebuie sa fie un numar pozitiv sau zero.");
    }

    if (newSize < v.size) {
        cout << "Doriti sa reduceti dimensiunea vectorului? (da-1/nu-0): ";
        int response;
        cin >> response;

        if (response == 1) {
            while (v.size > newSize) {
                popBack(v);
            }
        }
    } else if (newSize > v.size) {
        cout << "Doriti sa cresteti dimensiunea vectorului? (da-1/nu-0): ";
        int response;
        cin >> response;

        if (response == 1) {
            while (v.size < newSize) {
                cout << "Introduceti un nou element pentru pozitia " << v.size << ": ";
                long newElement;
                cin >> newElement;
                if (v.size == newSize) {
                    break;
                }
                pushBack(v, newElement);
            }
        }
    }

    // Actualizăm dimensiunea la dimensiunea dorită
    v.size = newSize;
    cout << "Elementele vectorului dupa modificare:" << endl;
    for (int i = 0; i < v.size; i++) {
        cout << v.data[i] << " ";
    }
    cout << endl;
}

// Funcția de ștergere a vectorului
void deleteVector(Vector& v) {
    delete[] v.data;
    v.size = 0;
}

int main() {
    int size;
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> size;

    if (size < 0) {
        cerr << "Dimensiunea trebuie să fie un număr pozitiv sau zero." << endl;
        return 1;
    }

    Vector myVector;
    initializeVector(myVector, size);

    cout << "Introduceti elementele vectorului:\n";
    for (int i = 0; i < myVector.size; i++) {
        cin >> myVector.data[i];
    }

    long evenSum = sumOfEvenElements(myVector);
    cout << "\nSuma elementelor pare: " << evenSum << endl;

    long maxElement = myVector.data[0];
    int maxElementIndex = 0;
    for (int i = 1; i < myVector.size; i++) {
        if (myVector.data[i] > maxElement) {
            maxElement = myVector.data[i];
            maxElementIndex = i;
        }
    }
    cout << "\nElementul maxim este " << maxElement << " la pozitia " << maxElementIndex << endl;

    int indexToAccess;
    cout << "\nIntroduceti indexul pentru accesarea elementului: ";
    cin >> indexToAccess;

    if (indexToAccess < 0 || indexToAccess >= myVector.size) {
        cerr << "Index invalid" << endl;
    } else {
        long& accessedElement = getElement(myVector, indexToAccess);
        cout << "Elementul de la indexul " << indexToAccess << " este: " << accessedElement << endl;
    }

    int newSize;
    cout << "\nDoriti sa reduceti dimensiunea vectorului? (da-1/nu-0): ";
    int response;
    cin >> response;

    if (response == 1) {
        cout << "Introduceti noua dimensiune pentru redimensionare: ";
        cin >> newSize;

        if (newSize < 0) {
            cerr << "Dimensiunea trebuie să fie un număr pozitiv sau zero." << endl;
        } else {
            try {
                resizeVector(myVector, newSize);
                cout << "Vectorul a fost redimensionat cu succes la dimensiunea " << newSize << endl;
            } catch (const invalid_argument& e) {
                cerr << e.what() << endl;
            }
        }

    }

    deleteVector(myVector);

    if (myVector.data != nullptr) {
        delete[] myVector.data;
    }

    return 0;
}
