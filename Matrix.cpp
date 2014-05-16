#include "Matrix.h"

using namespace std;

Matrix::Matrix (char * fichier)
{
    matrice = fichier;

    ifstream m (matrice,ifstream::in);
    string ligne;
    getline(m,ligne);
    nLigne=atoi((ligne.substr(0,ligne.find_first_of(' ')).c_str()));
    nColonne=atoi((ligne.substr(ligne.find_first_of(' ')+1,string::npos).c_str()));
}
/*
bool Matrix::produit(Matrix M1, Matrix M2)
{

}
*/

void Matrix::afficher() //pour test petites matrices uniquement
{
    cout<<"Debut affichage de matrice "<<nLigne<<"*"<<nColonne<<endl;
    for(int i_l=0;i_l<nLigne;i_l++)
    {
        for(int i_c=0;i_c<nColonne;i_c++)
        {
            cout<<get(i_l,i_c)<<' ';
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
    else
    {
        setV(ligne,getV(ligne)+1);
        return getV(ligne);
    }
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

void Matrix::setV(string &ligne, int V)
{
    string new_ligne=ligne.substr(0,ligne.find_last_of(' ')+1);
    stringstream ss;
    ss<<V;
    new_ligne+=ss.str();
    ligne=new_ligne;
}
