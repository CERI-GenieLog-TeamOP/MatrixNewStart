#include "Matrix.h"
#include <iostream>

using namespace std;

int main ()
{
    Matrix m1("mtest1.txt");
    m1.afficher();
    m1.produit(2,"test_produit.txt");
}
