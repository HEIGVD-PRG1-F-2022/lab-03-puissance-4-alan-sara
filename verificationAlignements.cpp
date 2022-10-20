
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