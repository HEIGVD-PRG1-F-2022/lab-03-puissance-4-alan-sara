#include <iostream>

using namespace std;

//fonction affichage
//fonction verification lignes colon
//

int main(){
    cout << "Puissance 4\nJouez en choisissant une colonne (de 0 a 6) pour y placer un jeton.\nGagnez en en alignant 4 identiques.\n" << endl;
    char quadrillage[6][7];

    for (int i = 0; i < 6; ++i) {
        for(int j = 0; j < 7; ++j) {
            quadrillage[i][j] = ' ';
            cout << quadrillage[i][j] << "|";
        }
        cout << endl;
    }

    while(true){
        int colonneChoisie;
        bool colonnePleine = true;

        while(colonnePleine == true){

            do {
                cout << "choisissez une colonne valide: ";
                cin >> colonneChoisie;
            } while (colonneChoisie > 6 || colonneChoisie < 0);

            for (int i = 5; i >= 0; i--) {
                if(quadrillage[i][colonneChoisie] == ' '){
                    quadrillage[i][colonneChoisie] = 'o';
                    colonnePleine = false;
                    break;
                }
            }
        }

        for (int i = 0; i < 6; ++i) {
            cout << '|';
            for (int j = 0; j < 7; ++j) {
                // quadrillage[i][j] = ' ';
                cout << quadrillage[i][j] << "|";
            }
            cout << endl;
            //cout << " _ _ _ _ _ _ _" << endl;
        }

        //verification
        //lignes
        for (int i = 0; i < 6; ++i) { //toutes les lignes
            for (int j = 0; j <= 3; ++j) {
                if(quadrillage[i][j] == quadrillage[i][j+1] && quadrillage[i][j+1] == quadrillage[i][j+2] && quadrillage[i][j+2] == quadrillage[i][j+3] && quadrillage[i][j] != ' '){
                    //gagné
                    cout << "gagne" << endl;
                }
            }
        }

        //colonnes
        for(int k = 0; k < 7; k++) {
            for (int l = 5; l >= 3; l--) {
                if(quadrillage[l][k] == quadrillage[l-1][k] && quadrillage[l-1][k] == quadrillage[l-2][k] && quadrillage[l-2][k] == quadrillage[l-3][k] && quadrillage[l][k] != ' '){
                    //gagné
                    cout << "gagne" << endl;
                }
            }
        }

        //diagonales gauche-droite
        for(int k = 0; k <= 3; k++) {
            for (int l = 5; l >= 3; l--) {
                if(quadrillage[l][k] == quadrillage[l-1][k+1] && quadrillage[l-1][k+1] == quadrillage[l-2][k+2] && quadrillage[l-2][k+2] == quadrillage[l-3][k+3] && quadrillage[l][k] != ' '){
                    //gagné
                    cout << "gagne" << endl;
                }
            }
        }

        //diagonales droite-gauche
        for(int k = 6; k >= 3; k--) {
            for (int l = 5; l >= 3; l--) {
                if(quadrillage[l][k] == quadrillage[l-1][k-1] && quadrillage[l-1][k-1] == quadrillage[l-2][k-2] && quadrillage[l-2][k-2] == quadrillage[l-3][k-3] && quadrillage[l][k] != ' '){
                    //gagné
                    cout << "gagne" << endl;
                }
            }
        }

    }
    return 0;
}
