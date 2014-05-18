#include "Matrix.h"
#include <iostream>

using namespace std;

int main ()
{
    Matrix m1("mtest1.txt");
    m1.afficher();
    //m1.produit(2,"test_produit.txt"); //multiplie m1 par 2 dans un nouveau fichier
    m1.produit(2); //remplace m1
}
