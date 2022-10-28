/*
 * Noms       : Alan Sottile - Sara Camassa
 * Date rendu : 24.10.2022
 * Labo       : Puissance 4
 */
#include <iostream>

using namespace std;

void choisirColonne(bool joueur1, char quadrillage[6][7]){
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
            if (quadrillage[i][colonneChoisie] == ' ') {  // verifie que la colonne choisie ne soit pas pleine, place le jeton le plus bas possible
                quadrillage[i][colonneChoisie] = symbole;
                colonnePleine = false;
                break;
            }
        }
    }
}