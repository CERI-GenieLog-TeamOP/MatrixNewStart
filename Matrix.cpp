#include "Matrix.h"

/*!
 * \file Matrix.cpp
 * \brief Opérations sur des matrices creuses
 *
 * \author Dupuy Nicolas
 * \author Cartoux Tristan
 * \author Soubirou Clément
 * \author Merah Vincent
 *
 * \date 29/05/2014
 */

using namespace std;

Matrix::Matrix (char * fichier)
{
    cout<<"CONSTRUCTOR"<<endl;
    matrice = fichier;
    cout<<"CONSTRUCTOR1"<<endl;

    ifstream m (matrice,ifstream::in);
    string ligne;
    cout<<"CONSTRUCTOR2"<<endl;
    getline(m,ligne);
    nLigne=atoi((ligne.substr(0,ligne.find_first_of(' ')).c_str()));
    cout<<"CONSTRUCTOR3"<<endl;
    nColonne=atoi((ligne.substr(ligne.find_first_of(' ')+1,string::npos).c_str()));
    cout<<"CONSTRUCTOR4"<<endl;
    m.close();
}

string Matrix::getStrFichier()
{
    string rez(matrice);
    return rez;
}

char* Matrix::getFichier()
{
    return matrice;
}

int Matrix::getNlignes()
{
    return nLigne;
}

int Matrix::getNcolonnes()
{
    return nColonne;
}


void Matrix::afficher() //pour test petites matrices uniquement
{
    cout<<"Debut affichage de matrice "<<nLigne<<"*"<<nColonne<<endl;
    for(int i_l=0;i_l<nLigne;i_l++)
    {
        for(int i_c=0;i_c<nColonne;i_c++)
        {
            cout<<get(i_c,i_l)<<' ';
        }
        cout<<endl;
    }
}

int Matrix::get(int c, int l)
{
    ifstream m(matrice);
    string ligne;
    getline(m,ligne); // saut de la ligne contenant les dimensions de la matrice

    do
    {
        getline(m,ligne);
    }while( (getL(ligne)<l || (getL(ligne)==l && getC(ligne)<c)) && !m.eof());

    if(getL(ligne)!=l || getC(ligne)!=c) return 0;
    return getV(ligne);
    m.close();
}

int Matrix::getL(string ligne)
{
    string l=ligne.substr(0,ligne.find_first_of(' '));
    return atoi(l.c_str());
}

int Matrix::getC(string ligne)
{
    string c=ligne.substr(ligne.find_first_of(' ')+1,ligne.find_last_of(' ')-ligne.find_first_of(' ')-1);
    return atoi(c.c_str());
}

int Matrix::getV(string ligne)
{
    string v=ligne.substr(ligne.find_last_of(' ')+1,string::npos);
    return atoi(v.c_str());
}

void Matrix::setV(string &ligne, int V) //change la valeur d'une ligne récupérée dans un string, qui devient V
{
    string new_ligne=ligne.substr(0,ligne.find_last_of(' ')+1);
    stringstream ss;
    ss<<V;
    new_ligne+=ss.str();
    ligne=new_ligne;
}

void Matrix::operator=(Matrix m2)
{
    remove(matrice);

    string tempStr = m2.matrice;
    char *fichier = new char[tempStr.length()];
    strcpy(fichier,tempStr.c_str());

    delete[] matrice;
    matrice = fichier;

    ifstream m(matrice,ifstream::in);
    string ligne;
    getline(m,ligne);
    nLigne=atoi((ligne.substr(0,ligne.find_first_of(' ')).c_str()));
    nColonne=atoi((ligne.substr(ligne.find_first_of(' ')+1,string::npos).c_str()));
    m.close();
}

void Matrix::soustraction(int a, char *fichier_destination)
{
    ofstream fichier_produit(fichier_destination);

    ifstream m(matrice);
    string ligne;
    getline(m,ligne);//saut de la ligne des dimensions
    fichier_produit<<ligne<<endl;

    while(!m.eof())
    {
        getline(m,ligne);
        setV(ligne,getV(ligne)-a);
        fichier_produit<<ligne<<endl;
    }

    ifstream registre("registreMatrices.txt");
    ofstream registreo("registreMatrices.txt", ios::app);

    string check;
    bool check2(false);
    while(!registre.eof())
    {
        getline(registre, check);
        if(check == fichier_destination)check2 = true;
    }
    if(!check2)registreo << fichier_destination << endl;
    registre.close();
    registreo.close();


    m.close();
    fichier_produit.close();
}

void Matrix::soustraction(int a)
{
    ofstream fichier_produit("temp_produit.txt");

    ifstream m(matrice);
    string ligne;
    getline(m,ligne);//saut de la ligne des dimensions

    while(!m.eof())
    {
        getline(m,ligne);
        setV(ligne,getV(ligne)-a);
        fichier_produit<<ligne<<endl;
    }

    if(remove(matrice)!=0) cerr<<"Erreur: "<<matrice<<" n'a pas pu etre supprime.";
    rename("temp_produit.txt",matrice);
    m.close();
    fichier_produit.close();
}

void Matrix::addition(int a, char *fichier_destination)
{
    ofstream fichier_produit(fichier_destination);

    ifstream m(matrice);
    string ligne;
    getline(m,ligne);//saut de la ligne des dimensions
    fichier_produit<<ligne<<endl;

    while(!m.eof())
    {
        getline(m,ligne);
        setV(ligne,getV(ligne)+a);
        fichier_produit<<ligne<<endl;
    }

    ifstream registre("registreMatrices.txt");
    ofstream registreo("registreMatrices.txt", ios::app);

    string check;
    bool check2(false);
    while(!registre.eof())
    {
        getline(registre, check);
        if(check == fichier_destination)check2 = true;
    }
    if(!check2)registreo << fichier_destination << endl;
    registre.close();
    registreo.close();

    m.close();
    fichier_produit.close();
}

void Matrix::addition(int a)
{
    ofstream fichier_produit("temp_produit.txt");

    ifstream m(matrice);
    string ligne;
    getline(m,ligne);//saut de la ligne des dimensions

    while(!m.eof())
    {
        getline(m,ligne);
        setV(ligne,getV(ligne)+a);
        fichier_produit<<ligne<<endl;
    }

    if(remove(matrice)!=0) cerr<<"Erreur: "<<matrice<<" n'a pas pu etre supprime.";
    rename("temp_produit.txt",matrice);
    m.close();
    fichier_produit.close();
}

void Matrix::produit(int a, char *fichier_destination)
{
    ofstream fichier_produit(fichier_destination);

    ifstream m(matrice);
    string ligne;
    getline(m,ligne);//saut de la ligne des dimensions
    fichier_produit<<ligne<<endl;

    while(!m.eof())
    {
        getline(m,ligne);
        setV(ligne,getV(ligne)*a);
        fichier_produit<<ligne<<endl;
    }

    ifstream registre("registreMatrices.txt");
    ofstream registreo("registreMatrices.txt", ios::app);

    string check;
    bool check2(false);
    while(!registre.eof())
    {
        getline(registre, check);
        if(check == fichier_destination)check2 = true;
    }
    if(!check2)registreo << fichier_destination << endl;
    registre.close();
    registreo.close();


    m.close();
    fichier_produit.close();
}

void Matrix::produit(int a)
{
    ofstream fichier_produit("temp_produit.txt");

    ifstream m(matrice);
    string ligne;
    getline(m,ligne);//saut de la ligne des dimensions

    while(!m.eof())
    {
        getline(m,ligne);
        setV(ligne,getV(ligne)*2);
        fichier_produit<<ligne<<endl;
    }

    if(remove(matrice)!=0) cerr<<"Erreur: "<<matrice<<" n'a pas pu etre supprime.";
    rename("temp_produit.txt",matrice);
    m.close();
    fichier_produit.close();
}

bool Matrix::addition(Matrix m2, char *fichier_destination)
{
    if(m2.getNlignes() != nLigne || m2.getNcolonnes() != nColonne)
    {
        cerr << "Impossible d'additionner deux matrices de tailles differentes." << endl;
        return false;
    }

    ofstream sortie (fichier_destination, ios::out | ios::trunc);
    sortie << nLigne << ' ' << nColonne << endl;

    for(int idxL = 0 ; idxL < nLigne ; idxL++)
    {
        for(int idxC = 0 ; idxC < nColonne ; idxC++)
        {
            sortie << idxL << ' ' << idxC << ' ' << get(idxC, idxL) + m2.get(idxC, idxL) << endl;
        }
    }

    ifstream registre("registreMatrices.txt");
    ofstream registreo("registreMatrices.txt", ios::app);

    string check;
    bool check2(false);
    while(!registre.eof())
    {
        getline(registre, check);
        if(check == fichier_destination)check2 = true;
    }
    if(!check2)registreo << fichier_destination << endl;
    registre.close();
    registreo.close();


    sortie.close();
    return true;
}

bool Matrix::soustraction(Matrix m2, char *fichier_destination)
{
    if(m2.getNlignes() != nLigne || m2.getNcolonnes() != nColonne)
    {
        cerr << "Impossible d'additionner deux matrices de tailles differentes." << endl;
        return false;
    }

    ofstream sortie (fichier_destination, ios::out | ios::trunc);
    sortie << nLigne << ' ' << nColonne << endl;

    for(int idxL = 0 ; idxL < nLigne ; idxL++)
    {
        for(int idxC = 0 ; idxC < nColonne ; idxC++)
        {
            sortie << idxL << ' ' << idxC << ' ' << get(idxC, idxL) - m2.get(idxC, idxL) << endl;
        }
    }

    ifstream registre("registreMatrices.txt");
    ofstream registreo("registreMatrices.txt", ios::app);

    string check;
    bool check2(false);
    while(!registre.eof())
    {
        getline(registre, check);
        if(check == fichier_destination)check2 = true;
    }
    if(!check2)registreo << fichier_destination << endl;
    registre.close();
    registreo.close();


    sortie.close();
    return true;
}

bool Matrix::produit(Matrix m2, char * fichier_destination)
{
    int calcul(0), tmp(0);
    if(nColonne != m2.getNlignes())
    {
        cerr << "Les deux matrices ne peuvent pas être multipliées !" << endl;
        return false;
    }

    ofstream sortie (fichier_destination, ios::out | ios::trunc);

    sortie << nLigne << ' ' << m2.getNcolonnes() << endl;

    for(int i = 0 ; i < nLigne ; i++)
    {
        for(int idxCol = 0 ; idxCol < m2.getNcolonnes() ; idxCol++)
        {
                calcul = 0;
                for(int idx1 = 0 ; idx1 < nColonne ; idx1++)
                {
                     if(get(idx1, i) != 0 && m2.get(idxCol, idx1) != 0)
                     {
                        calcul += get(idx1, i) * m2.get(idxCol, idx1);
                     }
                }
                if(calcul != 0)
                {
                    sortie << i << ' ' << idxCol << ' ' << calcul << endl;
                }
        }
    }

    ifstream registre("registreMatrices.txt");
    ofstream registreo("registreMatrices.txt", ios::app);

    string check;
    bool check2(false);
    while(!registre.eof())
    {
        getline(registre, check);
        if(check == fichier_destination)check2 = true;
    }
    if(!check2)registreo << fichier_destination << endl;
    registre.close();
    registreo.close();

    sortie.close();
    return true;
}

void Matrix::transposee(char * fichier_destination)
{
    ofstream transpo(fichier_destination);

    ifstream m(matrice);
    string ligne;
    getline(m,ligne);
    transpo << getC(ligne) << ' ' << getL(ligne) << endl;

    for(int idxC = 0 ; idxC < nColonne ; idxC++)
    {
        for(int idxL = 0 ; idxL < nLigne ; idxL++)
        {
            if(get(idxC, idxL) != 0)transpo << idxC << ' ' << idxL << ' ' << get(idxC, idxL) << endl;
        }
    }

    ifstream registre("registreMatrices.txt");
    ofstream registreo("registreMatrices.txt", ios::app);

    string check;
    bool check2(false);
    while(!registre.eof())
    {
        getline(registre, check);
        if(check == fichier_destination)check2 = true;
    }
    if(!check2)registreo << fichier_destination << endl;
    registre.close();
    registreo.close();

    m.close();
    transpo.close();
}
