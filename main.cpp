#include "Matrix.h"
#include <iostream>

using namespace std;

int main ()
{


    Matrix m1("mtest1.txt");
    m1.afficher();

    Matrix m2("mtest2.txt");    //On crée les deux matrices.
    m2.afficher();

    cout<<endl<<endl;

    m1.produit(m2, "resultat.txt"); //On les multiplie et stocke le resultat dans un nouveau fichier.

    Matrix m3("resultat.txt");      //On affiche le resultat.
    m3.afficher();

    //m1.produit(2,"test_produit.txt"); //multiplie m1 par 2 dans un nouveau fichier
    //m1.produit(2); //remplace m1
}
