/*
 * Noms       : Alan Sottile - Sara Camassa
 * Date rendu : 24.10.2022
 * Labo       : Puissance 4
 */
#include <iostream>
#include "affichageQuadrillage.h"
#include "choisirColonne.h"
#include "verificationAlignements.h"
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {

    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(
            console_color, 3);
    cout << "===========" << endl;
    cout << "Puissance 4" << endl;
    cout << "===========" << endl;
    SetConsoleTextAttribute(
            console_color, 7);
    cout
            << "Jouez en choisissant une colonne (de 0 a 6) pour y placer un jeton.\nGagnez en alignant 4 jetons identiques.\n"
            << endl;

    char quadrillage[6][7];   // plateau de jeu
    int tour = 0;             // variable pour compter le nombre de tours

    cout << " ";              // pour aligner le quadrillage en debut de partie
    affichageQuadrillage(quadrillage, tour);

    bool partieFinie = false; // variable pour verifier si la partie est finie
    bool joueur1 = true;      // variable pour verifier si c'est le tour du joueur 1 ou 2


    while (partieFinie == false && tour < 42) {

        ++tour;

        choisirColonne(joueur1, quadrillage);
        affichageQuadrillage(quadrillage, tour);
        verificationAlignements(quadrillage, partieFinie);

        joueur1 = !joueur1;   // passe au joueur suivant
    }

    //affichage du message de fin et du joueur gagnant

    cout << "\nfin de la partie" << endl;
    if (joueur1 && tour < 42) {
        cout << "le joueur 2 a gagne" << endl;
    } else if (joueur1 == false && tour < 42) {
        cout << "le joueur 1 a gagne" << endl;
    } else {
        cout << "Egalite" << endl;
    }

    return 0;
}