#include <fstream>
#include <iostream>

using namespace std;

int leggiECalcolaMedia(char nome_file[]);
int calcolaLunghezza(char parola[]);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: ./a.out <input_file>" << endl;
        exit(1);
    }
    else {
        int media = leggiECalcolaMedia(argv[1]);

        if (media != -1) {
            cout << "la media è " << media << endl;
        }
    }

    return 0;
}

int calcolaLunghezza(char parola[]) {
    int  lunghezza         = 0;
    char carattereCorrente = parola[lunghezza];

    while (carattereCorrente != '\0') {
        lunghezza++;
        carattereCorrente = parola[lunghezza];
    }
    return lunghezza;
}

int leggiECalcolaMedia(char nome_file[]) {
    fstream input, output;
    char    parola[11];
    int     media     = 0;
    int     contatore = 0;

    input.open(nome_file, ios::in);

    if (input.fail()) {
        cout << "Errore nell’apertura del file " << nome_file << endl;
        media = -1;
    }
    else {
        while (input >> parola) {
            media += calcolaLunghezza(parola);
            contatore++;
        }
        input.close();

        if (contatore != 0) {
            media = media / contatore;
        }

        output.open(nome_file, ios::out | ios::app);

        if (output.fail()) {
            cout << "Errore nell’apertura del file " << nome_file << endl;
            media = -1;
        }
        else {
            output << endl;

            for (int i = 0; i < media; i++) {
                output << '*';
            }
            output.close();
        }
    }
    return media;
}

// Variante con l'uso di una pila
// int leggiECalcolaMedia(char nome_file[]) {

//     // TODO aprire stream di input e append, controllare apertura
//     fstream read, app;
//     read.open(nome_file, ios::in);
//     app.open(nome_file, ios::app);

//     if (read.fail() || app.fail()) {
//         cout << "Errore in apertura file!" << endl;
//         exit(2);
//     }


//     // TODO leggere da file e calcolare somma e numero stringhe
//     pila_init();
//     char buffer[11];
//     int val;

//     while(read >> buffer) {
//         val = 0;
//         while(buffer[val] != '\0') {
//             val++;
//         }
//         pila_push(val);
//     }

//     // TODO calcolo media
//     int count = 0;
//     int media = 0;
//     while(pila_top(val)) {
//         media += val;
//         count++;
//         pila_pop();
//     }
//     media /= count;

//     // TODO scrittura della media in rappresentazione unaria sul file
//     for (int i = 0; i < media; i++) {
//         app << '*';
//     }

//     return media;
// }
