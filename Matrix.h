#ifndef MATRIX_H
#define MATRIX_H

/*!
 * \file Matrix.h
 * \brief Opérations sur des matrices creuses
 *
 * \author Dupuy Nicolas
 * \author Cartoux Tristan
 * \author Soubirou Clément
 * \author Merah Vincent
 *
 * \date 29/05/2014
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;


/*! \class Matrix
 * \brief Classe représentant des matrices vides
 *
 *  La classe gère le stockage de matrices creuses dans des fichiers ainsi que les opérations standards sur matrices.
 */
class Matrix
{
    char * matrice; /*!< Fichier dans lequel la matrice est stockée*/
    int nLigne; /*!< Nombre de lignes*/
    int nColonne; /*!< Nombre de colonnes*/

public:

    /*!
     *  \brief Constructeur
     *
     *  Construit une matrice à partir d'un fichier déjà existant et formaté LCV.
     *
     *  \param fichier : chemin/nom du fichier contenant la matrice
     */
    Matrix(char * fichier);

    /*!
     *  \brief Accesseur matrice
     *  \return Renvoie l'attribut matrice en tant que string.
     */
    string getStrFichier();

    /*!
     *  \brief Accesseur matrice
     *  \return Renvoie l'attribut matrice en tant char *
     */
    char* getFichier();

    /*!
     *  \brief Accesseur Nligne
     *  \return Renvoie le nombre de lignes de la matrice.
     */
    int getNlignes();

    /*!
     *  \brief Accesseur Nligne
     *  \return Renvoie le nombre de colonnes de la matrice.
     */
    int getNcolonnes();

    /*!
     *  \brief Affichage
     *
     *  Affiche la matrice dans la console (fonction pour tester de petites matrices seulement).
     */
    void afficher();

    /*!
     *  \brief Accesseur élément matrice
     *
     *  Permet de lire la valeur contenu dans une case de la matrice.
     *
     *  \param l : indice de la ligne à lire
     *  \param c : indice de la colonne à lire
     *
     *  \return Renvoie la valeur de l'élément l,c
     */
    int get(int c, int l);

    /*!
     *  \brief Lecture élément LCV
     *
     *  Permet de lire l'indice de ligne L d'un élément au format "L C V" (typiquement une ligne d'un fichier matrice)
     *
     *  \param ligne : string contenant un élément au format "L C V"
     *
     *  \return Renvoie l'indice L
     */
    int getL(string ligne);

    /*!
     *  \brief Lecture élément LCV
     *
     *  Permet de lire l'indice de colonne C d'un élément au format "L C V" (typiquement une ligne d'un fichier matrice)
     *
     *  \param ligne : string contenant un élément au format "L C V"
     *
     *  \return Renvoie l'indice C
     */
    int getC(string ligne);

    /*!
     *  \brief Lecture élément LCV
     *
     *  Permet de lire la valeur V d'un élément au format "L C V" (typiquement une ligne d'un fichier matrice)
     *
     *  \param ligne : string contenant un élément au format "L C V"
     *
     *  \return Renvoie la valeur V
     */
    int getV(string ligne);

    /*!
     *  \brief Modification d'élément LCV
     *
     *  Modifie la valeur V d'un élément au format "L C V".
     *
     *  \param ligne : string contenant un élément au format "L C V" (attention : elle sera directement modifée par référence)
     *  \param V : nouvelle valeur entière
     */
    void setV(string &ligne, int V);

    /*!
     *  \brief Opérateur d'assignation
     *
     *  Remplace la matrice appelante par une copie de la matrice m2.
     *
     *  \warning Le fichier de la matrice appelante sera supprimé.
     *
     *  \param m2 : matrice à copier
     */
    void operator=(Matrix m2);

    /*!
     *  \brief Multiplication par un entier
     *
     *  Multiplie la matrice par l'entier passé en paramètre et stocke le résultat dans un fichier.
     *  La matrice appelante n'est pas modifiée.
     *
     *  \param a : entier multiplicateur
     *  \param fichier_destination : chaîne de caractère désignant un fichier texte, déjà existant ou non, dans lequel le résultat sera stocké
     *  \warning Le fichier de destination sera écrasé si il existe déjà !
     */
    void produit(int a, char *fichier_destination);

    /*!
     *  \brief Multiplication par un entier
     *
     *  Multiplie la matrice par l'entier passé en paramètre. La matrice appelante est directement modifiée.
     *
     *  \param a : entier multiplicateur
     */
	void produit(int a);

    /*!
     *  \brief Soustraction par un entier
     *
     *  Soustrait à la matrice l'entier passé en paramètre et stocke le résultat dans un fichier.
     *  La matrice appelante n'est pas modifiée.
     *
     *  \param a : entier à soustraire
     *  \param fichier_destination : chaîne de caractère désignant un fichier texte, déjà existant ou non, dans lequel le résultat sera stocké
     *  \warning Le fichier de destination sera écrasé si il existe déjà !
     */
    void soustraction(int a, char *fichier_destination);

    void soustraction(int a);
    void addition(int a, char *fichier_destination);
    void addition(int a);

    /*!
     *  \brief Multiplication par une matrice
     *
     *  Multiplie deux matrices (matrice appelante * m2) et stocke le résultat dans un fichier.
     *  La matrice appelante n'est pas modifiée.
     *
     *  \param m2 : matrice multiplicatrice, élément droit du produit.
     *  \param fichier_destination : chaîne de caractère désignant un fichier texte, déjà existant ou non, dans lequel le résultat sera stocké
     *  \warning Le fichier de destination sera écrasé si il existe déjà !
     */
    bool produit(Matrix m2, char *fichier_destination);

    /*!
     *  \brief Transposition
     *
     *  Transpose la matrice appelante dans un autre fichier.
     *  La matrice appelante n'est pas modifiée.
     *
     *  \param fichier_destination : chaîne de caractère désignant un fichier texte, déjà existant ou non, dans lequel le résultat sera stocké
     *  \warning Le fichier de destination sera écrasé si il existe déjà !
     */
    void transposee(char* fichier_destination);

    //Matrix *produit(int a);
    //Matrix operator*(const int &a);

};

#endif // MATRIX_H
