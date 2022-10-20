/*
 * Noms       : Alan Sottile - Sara Camassa
 * Date rendu : 24.10.2022
 * Labo       : Puissance 4
 */
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void affichageQuadrillage(char quadrillage[6][7], int tour){
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 6; ++i) {
        cout << "|";
        for (int j = 0; j < 7; ++j) {
            if (tour == 0) {
                quadrillage[i][j] = ' ';      // s'assure que tous les elements du tableau soient "vides" en debut de partie
            }
            if(quadrillage[i][j] == 'o' ){  // Decide quelle couleur afficher
                SetConsoleTextAttribute(console_color, 3);
            }
            else{
                SetConsoleTextAttribute(console_color, 12);
            }
            cout << quadrillage[i][j];
            SetConsoleTextAttribute(console_color, 7); // remet la couleur en blanc
            cout <<  "|";
        }
        cout << endl;
        cout << " ";
    }
    cout << " 0 1 2 3 4 5 6" << endl;
}