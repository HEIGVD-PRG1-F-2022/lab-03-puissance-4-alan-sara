#include <iostream>

using namespace std;

//fonction affichage
//fonction verification lignes colon
//

int main(){
    cout << "===========" << endl;
    cout << "Puissance 4" << endl;
    cout << "===========" << endl;
    cout << "Jouez en choisissant une colonne (de 0 a 6) pour y placer un jeton.\nGagnez en en alignant 4 identiques.\n" << endl;
    char quadrillage[6][7];

    for (int i = 0; i < 6; ++i) {
        for(int j = 0; j < 7; ++j) {
            quadrillage[i][j] = ' ';
            cout << quadrillage[i][j] << "|";
        }

        cout << endl;
    }
    cout << "0 1 2 3 4 5 6" << endl;


    bool partieFinie = false;
    bool joueur1 = true;
    int tour = 0;


    while(partieFinie == false){
        int colonneChoisie;
        bool colonnePleine = true;

        int joueurActuel;
        if(joueur1){
            joueurActuel = 1;
        }
        else{
            joueurActuel = 2;
        }

        while(colonnePleine == true){

            char symbole;
            if(joueur1){
                symbole = 'o';
            }
            else{
                symbole = 'x';
            }

            do {
                cout << "joueur " << joueurActuel << ", choisissez une colonne valide: ";
                cin >> colonneChoisie;
            } while (colonneChoisie > 6 || colonneChoisie < 0);

            for (int i = 5; i >= 0; i--) {
                if(quadrillage[i][colonneChoisie] == ' '){
                    quadrillage[i][colonneChoisie] = symbole;
                    colonnePleine = false;
                    break;
                }
            }
        }

        for (int i = 0; i < 6; ++i) {
            cout << '|';
            for (int j = 0; j < 7; ++j) {
                cout << quadrillage[i][j] << "|";
            }
            cout << endl;
            cout << " ";
        }
        cout << " 0 1 2 3 4 5 6" << endl;

        //verification
        //lignes
        for (int i = 0; i < 6; ++i) { //toutes les lignes
            for (int j = 0; j <= 3; ++j) {
                if(quadrillage[i][j] == quadrillage[i][j+1] && quadrillage[i][j+1] == quadrillage[i][j+2] && quadrillage[i][j+2] == quadrillage[i][j+3] && quadrillage[i][j] != ' '){
                    //gagné
                    partieFinie = true;
                }
            }
        }

        //colonnes
        for(int k = 0; k < 7; k++) {
            for (int l = 5; l >= 3; l--) {
                if(quadrillage[l][k] == quadrillage[l-1][k] && quadrillage[l-1][k] == quadrillage[l-2][k] && quadrillage[l-2][k] == quadrillage[l-3][k] && quadrillage[l][k] != ' '){
                    //gagné
                    partieFinie = true;
                }
            }
        }

        //diagonales gauche-droite
        for(int k = 0; k <= 3; k++) {
            for (int l = 5; l >= 3; l--) {
                if(quadrillage[l][k] == quadrillage[l-1][k+1] && quadrillage[l-1][k+1] == quadrillage[l-2][k+2] && quadrillage[l-2][k+2] == quadrillage[l-3][k+3] && quadrillage[l][k] != ' '){
                    //gagné
                    partieFinie = true;
                }
            }
        }

        //diagonales droite-gauche
        for(int k = 6; k >= 3; k--) {
            for (int l = 5; l >= 3; l--) {
                if(quadrillage[l][k] == quadrillage[l-1][k-1] && quadrillage[l-1][k-1] == quadrillage[l-2][k-2] && quadrillage[l-2][k-2] == quadrillage[l-3][k-3] && quadrillage[l][k] != ' '){
                    //gagné
                    partieFinie = true;
                }
            }
        }
        tour++;
        joueur1 = !joueur1;
        cout << tour;
    }

    cout << "c'est fini" << endl;
    if(joueur1 && tour < 41){
        cout << "le joueur 2 a gagne" << endl;
    }
    else if(joueur1 == false && tour < 41){
        cout << "le joueur 1 a gagne" << endl;
    }
    else
    {
        cout << "Egalite" << endl;
    }
    return 0;
}
