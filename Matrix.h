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
    string getStrFichier();
    char* getFichier();
    int getNlignes();
    int getNcolonnes();

    void afficher();
    int get(int l, int c);
    int getL(string ligne);
    int getC(string ligne);
    int getV(string ligne);
    void setV(string &ligne, int V);

    void operator=(Matrix m2);

    void produit(int a, char *new_fichier);
    void produit(int a);

    bool produit(Matrix m2, char *);

    //Matrix *produit(int a);
    //Matrix operator*(const int &a);

};

#endif // MATRIX_H
