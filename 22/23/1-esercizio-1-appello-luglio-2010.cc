#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
    fstream myin;

    char tmp[100];
    int  numeroCifre    = 0;
    int  numeroStringhe = 0;
    int  numeroTarget   = 0;

    if (argc < 2) {
        cerr << "Usage: ./a.out <filename>" << endl;
        exit(EXIT_FAILURE);
    }

    myin.open(argv[1], ios::in);

    if (myin.fail()) {
        cerr << "Apertura del file fallita." << endl;
        exit(EXIT_FAILURE);
    }

    while (myin >> tmp) {
        for (int i = 0; i < 4; ++i) {
            if ((tmp[i] >= '0') && (tmp[i] <= '9')) {
                ++numeroCifre;
            }
        }

        if ((numeroCifre == 4) && (strlen(tmp) == 4)) {
            ++numeroStringhe;
        } else {
            numeroStringhe = 0;
        }

        numeroCifre = 0;

        if (numeroStringhe == 4) {
            ++numeroTarget;
            numeroStringhe = 0;
        }
    }

    myin.close();

    if (numeroTarget > 0) {
        cout << "Trovate " << numeroTarget <<
            " stringhe di quattro caratteri, costituite esclusivamente da cifre decimali."
             << endl;
    } else {
        cout << "Nessuna stringa di quattro cifre decimali trovata." << endl;
    }
    return 0;
}
