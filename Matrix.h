#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
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
    int get(int l, int c);
    int getL(string ligne);
    int getC(string ligne);
    int getV(string ligne);
    void setV(string &ligne, int V);

    void operator=(Matrix m2);

    void produit(int a, char *fichier_destination);
    void produit(int a);
    void addition(Matrix m2, char *fichier_destination);
    void addition(Matrix m2);

    //Matrix *produit(int a);
    //Matrix operator*(const int &a);

};

#endif // MATRIX_H
