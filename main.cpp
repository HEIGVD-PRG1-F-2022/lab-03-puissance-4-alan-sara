#include <iostream>

using namespace std;

int main(){
    char quadrillage[6][7];

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            quadrillage[i][j] = ' ';
            cout << quadrillage[i][j] << "|";
        }
        cout << endl;
        //cout << " _ _ _ _ _ _ _" << endl;
    }

    int colonneChoisie;
    cout << "choisissez une colonne: ";
    cin >> colonneChoisie;
    // si pas chiffre valide, redemande

    for (int i = 5; i >= 0; i--) {
        if(quadrillage[i][colonneChoisie] == ' '){
            quadrillage[i][colonneChoisie] = 'o';
            break;
        }
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            //quadrillage[i][j] = ' ';
            cout << quadrillage[i][j] << "|";
        }
        cout << endl;
        //cout << " _ _ _ _ _ _ _" << endl;
    }


    return 0;
}
