#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Matrix
{
    char * matrice;
    int nLigne;
    int nColonne;

public:
    Matrix(char * fichier);
    void afficher();
    int get(int x, int y);
    int getL(string ligne);
    int getC(string ligne);
    int getV(string ligne);
    bool produit(string M1, string M2);
};

#endif // MATRIX_H
