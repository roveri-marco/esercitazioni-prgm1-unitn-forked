#include <iostream>
#include <fstream>

using namespace std;

struct nodo {
    int   value;
    nodo *left;
    nodo *right;
};
typedef nodo *albero;


albero creaAlberoDiRicercaBinaria(char *inputFile);
void   inserisciNodoInAlberoDiRicercaBinaria(albero radice,
                                             nodo  *nuovoNodo);
void   stampaAlbero(albero radice,
                    int    spazio = 2);


int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: ./a.out <nome_file>" << endl;
        exit(1);
    }

    albero radice = creaAlberoDiRicercaBinaria(argv[1]);

    if (radice == NULL) {
        exit(2);
    } else {
        stampaAlbero(radice);
    }

    return 0;
}

albero creaAlberoDiRicercaBinaria(char *inputFile) {
    albero  radice = NULL;
    fstream input;

    input.open(inputFile, ios::in);

    if (input.fail()) {
        cout << "Errore in lettura" << endl;
    }
    else {
        int numero;
        input >> numero;
        radice = new nodo{ numero, NULL, NULL };

        while (input >> numero) {
            nodo *nuovoNodo = new nodo{ numero, NULL, NULL };
            inserisciNodoInAlberoDiRicercaBinaria(radice, nuovoNodo);
        }
    }

    input.close();

    return radice;
}

void inserisciNodoInAlberoDiRicercaBinaria(albero radice, nodo *nuovoNodo) {
    if (nuovoNodo->value > radice->value) {
        if (radice->right == NULL) {
            radice->right = nuovoNodo;
        }
        else {
            inserisciNodoInAlberoDiRicercaBinaria(radice->right, nuovoNodo);
        }
    }
    else {
        if (radice->left == NULL) {
            radice->left = nuovoNodo;
        }
        else {
            inserisciNodoInAlberoDiRicercaBinaria(radice->left, nuovoNodo);
        }
    }
}

void stampaAlbero(albero radice, int spazio) {
    if (radice != NULL) {
        spazio++;

        stampaAlbero(radice->right, spazio);

        for (int i = 1; i < spazio; i++) {
            cout << "\t";
        }
        cout << radice->value << "\n";

        stampaAlbero(radice->left, spazio);
    }
}
