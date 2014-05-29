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
    return getV(ligne);
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

void Matrix::setV(string &ligne, int V) //change la valeur d'une ligne, qui devient V
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
}

void Matrix::produit(int a, char *new_fichier)
{
    ofstream fichier_produit(new_fichier);

    ifstream m(matrice);
    string ligne;
    getline(m,ligne);//saut de la ligne des dimensions

    while(!m.eof())
    {
        getline(m,ligne);
        setV(ligne,getV(ligne)*2);
        fichier_produit<<ligne<<endl;
    }
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
}

bool Matrix::produit(Matrix m2, char * new_fichier)
{
    int calcul(0), tmp(0);
    if(nColonne != m2.getNlignes())
    {
        cerr << "Les deux matrices ne peut pas être multipliées !" << endl;
        return false;
    }

    ofstream sortie (new_fichier, ios::out | ios::trunc);
    ifstream mat1(matrice, ifstream::in);
    ifstream mat2(getFichier(), ifstream::in);

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
                    cout<<"Brackett"<<endl;
                    sortie << i << ' ' << idxCol << ' ' << calcul << endl;
                }
        }
    }


    return true;
}
