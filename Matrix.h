#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
    string matrice;
    int nLigne;
    int nColonne;

public:
    Matrix(string fichier);
    bool produit(string M1, string M2);
    int readLine(string);
    void print();

};

#endif // MATRIX_H
