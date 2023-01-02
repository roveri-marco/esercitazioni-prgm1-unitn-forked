#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Studente {
    char nome[31];
    char cognome[31];
    int matricola;
    float media;
};

void stampa_studente(Studente * s);
Studente* genera_studente(char nome[], char cognome[], int matricola, float media);
bool riempi_database(Studente ** database, char file [], int dim);

int main (int argc, char * argv[]) {

    if (argc != 3) {
        cout << "Usage: ./a.out <file> <dim>" << endl;
        exit(0);
    }
    
    int dim = atoi(argv[2]);
    Studente ** database = new Studente* [dim];
    
    if (riempi_database(database, argv[1], dim)) {
        stampa_studente(database[0]);
    }
    
    for (int i = 0; i < dim; i++) {
        delete database[i];
    }
    delete[] database;

    return 0;
}


void stampa_studente(Studente * s) {
    cout << "Studente (matricola: " << s->matricola << ") :" << endl;
    cout << "\tNome: " << s->nome << endl;
    cout << "\tCognome: " << s->cognome << endl;
    cout << "\tMedia: " << s->media << endl;
}

Studente* genera_studente(char * nome, char * cognome, int matricola, float media) {
    Studente * s = new Studente;
    s->matricola = matricola;
    s->media = media;
    strcpy(s->nome, nome);
    strcpy(s->cognome, cognome);
    return s;
}

bool riempi_database(Studente ** database, char file [], int dim) {
    bool risultato;
    fstream input;
    input.open(file, ios::in);
    if (input.fail()) {
    	cout << "Errore nella lettura del file" << endl;
    	risultato = false;
    } else {
    
        int indice = 0;
        
    	char nome[31], cognome[31];
    	int matricola;
    	float media;
    	
    	while (input >> nome >> cognome >> matricola >> media) {
    	    database[indice] = genera_studente(nome, cognome, matricola, media);
    	    indice++;
    	}
    	risultato = true;
    }
    input.close();

    return risultato;
}
