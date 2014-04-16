#include <iostream>
#include "Matrix.h"
#include <fstream>

using namespace std;

Matrix::Matrix (string fichier)
{
    matrice = fichier;

    ifstream maMatrice (matrice.c_str());

    maMatrice.seekg(0, ios::beg);
    nLigne >> maMatrice;
    nColonne >> maMatrice;
}
/*
bool Matrix::produit(Matrix M1, Matrix M2)
{

}
*/
int Matrix::readLine (string ligne)
{
    string tampon, string res;

    ligne << tampon << res;

    return atoi(res.c_str());
}

void Matrix::print()
{
    cout<<"La matrice du fichier "<<matrice<<" comporte "<<nLigne<<" lignes et "<<NColonne<<" colonnes."<<endl;
}
