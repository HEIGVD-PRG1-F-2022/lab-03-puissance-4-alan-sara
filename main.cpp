#include <iostream>

using namespace std;

void affichageQuadrillage(char quadrillage[6][7], int tour);                // permet d'afficher le quadrillage
void choisirColonne(bool joueur1, char quadrillage[6][7]);                  // permet de choisir une colonne et y placer un jeton
bool verificationAlignements(char quadrillage[6][7], bool& partieFinie);    // permet de verifier si la partie est finie (si les jetons sont alignés)

int main() {
    cout << "===========" << endl;
    cout << "Puissance 4" << endl;
    cout << "===========" << endl;
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

void affichageQuadrillage(char quadrillage[6][7], int tour) {
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

void choisirColonne(bool joueur1, char quadrillage[6][7]) {
    int colonneChoisie;                   // variable pour stocker la colonne choisie par le joueur
    bool colonnePleine = true;            // variable pour verifier si la colonne choisie est pleine
    int joueurActuel;                     // variable pour noter le numero du joueur actuel

    if (joueur1) {                          // permet d'afficher le bon joueur dans le texte plus bas (choisissez une colonne valide)
        joueurActuel = 1;
    } else {
        joueurActuel = 2;
    }

    while (colonnePleine == true) {
        char symbole;

        if (joueur1) {  // definit le symbole a placer par rapport au joueur dont c'est le tour
            symbole = 'o';
        } else {
            symbole = 'x';
        }

        do {  // verifie que le chiffre entré est valide
            cout << "joueur " << joueurActuel << ", choisissez une colonne valide: ";
            cin >> colonneChoisie;
        } while (colonneChoisie > 6 || colonneChoisie < 0);

        for (int i = 5; i >= 0; i--) {
            if (quadrillage[i][colonneChoisie] ==
                ' ') {  // verifie que la colonne choisie ne soit pas pleine, place le jeton le plus bas possible
                quadrillage[i][colonneChoisie] = symbole;
                colonnePleine = false;
                break;
            }
        }
    }
}

bool verificationAlignements(char quadrillage[6][7], bool& partieFinie) {

    //lignes
    for (int i = 0; i < 6; ++i) { // pour toutes les lignes
        for (int j = 0; j <= 3; ++j) { // pour les 4 premieres colonnes
            if (quadrillage[i][j] == quadrillage[i][j + 1] && quadrillage[i][j + 1] == quadrillage[i][j + 2] &&
                quadrillage[i][j + 2] == quadrillage[i][j + 3] && quadrillage[i][j] != ' ') {
                partieFinie = true;
                return partieFinie;
            }
        }
    }

    //colonnes
    for (int k = 0; k < 7; k++) { // pour toutes les colonnes
        for (int l = 5; l >= 3; l--) { // pour les 3 dernieres lignes
            if (quadrillage[l][k] == quadrillage[l - 1][k] && quadrillage[l - 1][k] == quadrillage[l - 2][k] &&
                quadrillage[l - 2][k] == quadrillage[l - 3][k] && quadrillage[l][k] != ' ') {
                partieFinie = true;
                return partieFinie;
            }
        }
    }

    //diagonales gauche-droite
    for (int k = 0; k <= 3; k++) { // pour les 4 premieres colonnes
        for (int l = 5; l >= 3; l--) { // pour les 3 dernieres lignes
            if (quadrillage[l][k] == quadrillage[l - 1][k + 1] &&
                quadrillage[l - 1][k + 1] == quadrillage[l - 2][k + 2] &&
                quadrillage[l - 2][k + 2] == quadrillage[l - 3][k + 3] && quadrillage[l][k] != ' ') {
                partieFinie = true;
                return partieFinie;
            }
        }
    }

    //diagonales droite-gauche
    for (int k = 6; k >= 3; k--) { // pour les 4 dernieres colonnes
        for (int l = 5; l >= 3; l--) { // pour les 3 dernieres lignes
            if (quadrillage[l][k] == quadrillage[l - 1][k - 1] &&
                quadrillage[l - 1][k - 1] == quadrillage[l - 2][k - 2] &&
                quadrillage[l - 2][k - 2] == quadrillage[l - 3][k - 3] && quadrillage[l][k] != ' ') {
                partieFinie = true;
                return partieFinie;
            }
        }
    }
    return partieFinie;
}