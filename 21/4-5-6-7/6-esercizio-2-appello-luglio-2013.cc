#include <iostream>

using namespace std;

void stampaArray(char v[],
                 int  dim);
void ruotaArrayInefficiente(char v[],
                            int  dim,
                            int  rotazione);
void ruotaArrayEfficiente(char v[],
                                  int  dim,
                                  int  rotazione);


int main() {
    int  j;
    char v[]      = { 'A', 'B', 'C', 'D', 'E' };
    const int dim = 5;

    cout << "Inserisci j: ";
    cin >> j;

    j = j % dim;

    stampaArray(v, dim);
    ruotaArrayInefficiente(v, dim, j);

    // ruotaArrayEfficiente(v, dim, j);
    stampaArray(v, dim);

    return 0;
}

void stampaArray(char v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void ruotaArrayEfficiente(char v[], int dim, int rotazione) {
    int *temp = new int[rotazione];

    for (int i = 0; i < rotazione; i++) {
        temp[i] = v[i];
    }

    for (int i = 0; i < dim - rotazione; i++) {
        v[i] = v[rotazione + i];
    }

    for (int i = 0; i < rotazione; i++) {
        v[dim - rotazione + i] = temp[i];
    }
    delete[] temp;
}

void ruotaArrayInefficiente(char v[], int dim, int rotazione) {
    int temp;

    for (int i = 0; i < rotazione; i++) {
        temp = v[0];

        for (int k = 0; k < dim - 1; k++) {
            v[k] = v[k + 1];
        }
        v[dim - 1] = temp;
    }
}
