#include "Matrix.h"
#include <iostream>
#include <time.h>

using namespace std;

bool deleteFile(string nom);
void gererMatrices();
void displayMatrix();
void generateMatrixC();
void cGen(int nc, int nl, string fichier, int indice);

//Forme de la matrice dans le fichier:
    //*  NBLIGNES, NBCOLONNES  *//
    //*  LIGNE,COLONNE,VALEUR  *//
    //*  LIGNE,COLONNE,VALEUR  *//
    //*          ...           *//

//Lorsqu'une colonne est vide (pleine de 0) une val aléatoire entre 1 et 9 est rajoutée à la dernière ligne de cette colonne.
void cGen(int nc, int nl, string fichier, int indice) //Generateur de matrices creuse.
{
    int n(0), *grille, check(0), vn, ln;
    grille = new int[nc];

    if(indice < 1 || indice > 9)indice = 5;
    ofstream monFichier (fichier.c_str());

    srand (time(NULL));

    monFichier << nl << ' ' << nc << endl;
    for (int idxL = 0 ; idxL < nl ; idxL++)
    {

        //On remplie la colonne de nombres randoms entre 0 et 10.
        for (int idxC = 0 ; idxC < nc ; idxC++)
        {

            if((rand() % 10) < indice) //Pourcentage de 0.
            {
                grille[idxC] = 0;
            }
            else grille[idxC] = rand() % 9 + 1;
        }

        check = 0;

        //Si toute la colonne est nulle.
        for(int i = 0 ; i < nc ; i++)
        {
            if(grille[i] != 0)check = 1;
        }

        //On rajoute un nombre aléatoire à une ligne aléatoire
        if(check == 0)
        {
            ln = rand() % 10;
            vn = rand() % 9 + 1;

            grille[ln] = vn;
        }

        //Insertion dans le fichier
        for (int insC = 0 ; insC < nc ; insC++)
        {
            if(grille[insC]!=0) monFichier << idxL << ' ' << insC << ' ' << grille[insC] << endl;
        }

    }

    ifstream registre("registreMatrices.txt");
    ofstream registreo("registreMatrices.txt", ios::app);

    string checki;
    bool check2(false);
    while(!registre.eof())
    {
        getline(registre, checki);
        if(checki == fichier)check2 = true;
    }
    if(!check2)registreo << fichier << endl;
    registre.close();
    registreo.close();
}

void generateMatrixC()  //Appel au generateur de matrice creuse.
{
    int nc(0), nl(0), indice(0);
    string fichier = "matrice.txt";
    cout<<"Vous avez choisi de generer une matrice creuse."<<endl<<endl;

    cout<<"Veuillez choisir le nombre de colonnes."<<endl;
    cout<<">"<<endl<<endl;
    cin>>nc;

    cout<<"Veuillez choisir le nombre de lignes."<<endl;
    cout<<">"<<endl<<endl;
    cin>>nl;

    cout<<"Veuillez indiquer le nom du fichier a creer/modifier."<<endl;
    cout<<">"<<endl<<endl;
    cin>>fichier;

    cout<<"Veuillez indiquer un indice (entre 1 et 9) qui creera plus ou moins de zeros. (1 -> 10% de zeros  9 -> 90% de zeros)"<<endl;
    cout<<">"<<endl<<endl;
    cin>>indice;

    cout<<endl<<endl<<"RECAP: Vous avez demande une matrice creuse de "<<nc<<" colonnes et "<<nl<<" lignes que vous souhaitez stocker dans le fichier "<<fichier<<"."<<endl;

    cGen(nc, nl, fichier, indice);

    cout<<endl<<endl<<"Matrice creee avec succes !"<<endl;
}


void displayMatrix()
{
    cout << "Voici les matrices a votre disposition: " <<endl<<endl;;
    ifstream registre("registreMatrices.txt");
    string rline;
    while(!registre.eof())
    {
        getline(registre, rline);
        cout << rline << endl;
    }
    cout << endl;
}

int main ()
{

    cout << "               --- Bienvenue dans le gestionnaire de matrices --- " <<endl<<endl;

    while(true)
    {
clearE();
        displayMatrix();


        int choix(0);

        cout<<"1 - Generer une matrice aleatoirement."<<endl;
        cout<<"2 - Multiplier une matrice par un entier."<<endl;
        cout<<"3 - Multiplier une matrice par une matrice."<<endl;
        cout<<"4 - Soustraire un entier a une matrice."<<endl;
        cout<<"5 - Soustraire une matrice a une matrice."<<endl;
        cout<<"6 - Ajouter un entier a une matrice."<<endl;
        cout<<"7 - Ajouter une matrice a une matrice."<<endl;
        cout<<"8 - Transposee d'un matrice."<<endl<<endl;
        cout<<"0 - Quitter le gestionnaire."<<endl;

        do
        {
            cout<<'>';
            cin>>choix;
        }while(choix < 0 && choix > 8);

        char* fichier;
        char* fichierr;
        string newF, fichier1, newFichier, fichier2;
        char* newFile;
        int entier;

clearE();
        displayMatrix();
        switch(choix)
        {
            case 0: {
                    return 0;
                }

            case 1: {
                generateMatrixC();
                    break;
                }

            case 2: {
                cout << "Entrez le nom du fichier contenant la matrice: " << endl;
                cout<<'>';
                cin>>fichier1;
                fichier = (char*)fichier1.c_str();
                Matrix m1(fichier);
                cout << "Entrez l'entier par lequel multiplier la matrice: " << endl;
                cout<<'>';
                cin>>entier;
                cout << "Souhaitez vous entrer le resultat dans un nouveau fichier ou directement modifier le fichier appelant? (garder | ecraser)" << endl;
                do
                {
                    cout<<'>';
                    cin>>newF;
                }while(newF != "garder" && newF != "ecraser");

                if(newF == "garder")
                {
                    cout << "Entrez le nom du nouveau fichier" << endl;
                    cout<<'>';
                    cin>>newFichier;
                    newFile = (char*)newFichier.c_str();
                    m1.produit(entier, newFile);
                }
                if(newF == "ecraser")m1.produit(entier);

                    break;
                }

            case 3: {
                cout << "Entrez le nom du fichier contenant la premiere matrice: " << endl;
                cout<<'>';
                cin>>fichier1;
                fichier = (char*)fichier1.c_str();
                Matrix m1(fichier);
                cout << "Entrez le nom du fichier contenant la deuxieme matrice: " << endl;
                cout<<'>';
                cin>>fichier2;
                fichierr = (char*)fichier2.c_str();
                Matrix m2(fichierr);

                    cout << "Entrez le nom du nouveau fichier" << endl;
                    cout<<'>';
                    cin>>newFichier;
                    newFile = (char*)newFichier.c_str();
                    m1.produit(m2, newFile);

                    break;
                }

            case 4: {

                cout << "Entrez le nom du fichier contenant la matrice: " << endl;
                cout<<'>';
                cin>>fichier1;
                fichier = (char*)fichier1.c_str();
                Matrix m1(fichier);
                cout << "Entrez l'entier a soustraire a la matrice: " << endl;
                cout<<'>';
                cin>>entier;
                cout << "Souhaitez vous entrer le resultat dans un nouveau fichier ou directement modifier le fichier appelant? (garder | ecraser)" << endl;
                do
                {
                    cout<<'>';
                    cin>>newF;
                }while(newF != "garder" && newF != "ecraser");

                if(newF == "garder")
                {
                    cout << "Entrez le nom du nouveau fichier" << endl;
                    cout<<'>';
                    cin>>newFichier;
                    newFile = (char*)newFichier.c_str();
                    m1.soustraction(entier, newFile);
                }
                if(newF == "ecraser")m1.soustraction(entier);

                    break;
                }

            case 5: {

                cout << "Entrez le nom du fichier contenant la premiere matrice: " << endl;
                cout<<'>';
                cin>>fichier1;
                fichier = (char*)fichier1.c_str();
                Matrix m1(fichier);
                cout << "Entrez le nom du fichier contenant la deuxieme matrice: " << endl;
                cout<<'>';
                cin>>fichier2;
                fichierr = (char*)fichier2.c_str();
                Matrix m2(fichierr);

                    cout << "Entrez le nom du nouveau fichier" << endl;
                    cout<<'>';
                    cin>>newFichier;
                    newFile = (char*)newFichier.c_str();
                    m1.soustraction(m2, newFile);

                    break;
                }

            case 6: {

                cout << "Entrez le nom du fichier contenant la matrice: " << endl;
                cout<<'>';
                cin>>fichier1;
                fichier = (char*)fichier1.c_str();
                Matrix m1(fichier);
                cout << "Entrez l'entier a additionner a la matrice: " << endl;
                cout<<'>';
                cin>>entier;
                cout << "Souhaitez vous entrer le resultat dans un nouveau fichier ou directement modifier le fichier appelant? (garder | ecraser)" << endl;
                do
                {
                    cout<<'>';
                    cin>>newF;
                }while(newF != "garder" && newF != "ecraser");

                if(newF == "garder")
                {
                    cout << "Entrez le nom du nouveau fichier" << endl;
                    cout<<'>';
                    cin>>newFichier;
                    newFile = (char*)newFichier.c_str();
                    m1.addition(entier, newFile);
                }
                if(newF == "ecraser")m1.addition(entier);

                    break;
                }

            case 7: {

                cout << "Entrez le nom du fichier contenant la premiere matrice: " << endl;
                cout<<'>';
                cin>>fichier1;
                fichier = (char*)fichier1.c_str();
                Matrix m1(fichier);
                cout << "Entrez le nom du fichier contenant la deuxieme matrice: " << endl;
                cout<<'>';
                cin>>fichier2;
                fichierr = (char*)fichier2.c_str();
                Matrix m2(fichierr);

                    cout << "Entrez le nom du nouveau fichier" << endl;
                    cout<<'>';
                    cin>>newFichier;
                    newFile = (char*)newFichier.c_str();
                    m1.addition(m2, newFile);

                    break;
                }

            case 8: {

                cout << "Entrez le nom du fichier contenant la matrice: " << endl;
                cout<<'>';
                cin>>fichier1;
                fichier = (char*)fichier1.c_str();
                Matrix m1(fichier);

                cout << "Entrez le nom du nouveau fichier" << endl;
                cout<<'>';
                cin>>newFichier;
                newFile = (char*)newFichier.c_str();

                m1.transposee(newFile);

                    break;
                }

        }
    }
}
