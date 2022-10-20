//
//
//
#include <iostream>

using namespace std;

void affichageQuadrillage(char quadrillage[6][7], int tour){
    for (int i = 0; i < 6; ++i) {
        cout << "|";
        for (int j = 0; j < 7; ++j) {
            if (tour == 0) {
                quadrillage[i][j] = ' ';      // s'assure que tous les elements du tableau soient "vides" en debut de partie
            }
            cout << quadrillage[i][j] << "|";
        }
        cout << endl;
        cout << " ";
    }
    cout << " 0 1 2 3 4 5 6" << endl;
}