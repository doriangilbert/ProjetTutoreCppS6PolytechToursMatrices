#ifndef CMatrice_cpp
#define CMatrice_cpp

#include "CMatrice.h"

/***********************************************************************
***** CMATRICE<MTYPE> : Constructeur par défaut de CMatrice<MTYPE> *****
************************************************************************
***** Entrée :                                                     *****
***** Nécessite :                                                  *****
***** Sortie :                                                     *****
***** Entraine : Le contructeur a initialisé un objet              *****
***** CMatrice<MTYPE> avec uiMATNbLignes et uiMATNbColonnes égaux  *****
***** à 0 et pMATMatrice à NULL                                    *****
***********************************************************************/
//sur les constructeurs mettre MTYPE a un pointeur (char*) ne marche pas.
template<class MTYPE> CMatrice<MTYPE>::CMatrice()
{
	uiMATNbLignes = 0;
	uiMATNbColonnes = 0;
	pMATMatrice = NULL;
};

/***********************************************************************
***** CMATRICE<MTYPE> : Constructeur de recopie de CMatrice<MTYPE> *****
************************************************************************
***** Entrée : MATParam, un objet de type CMatrice<MTYPE>          *****
***** Nécessite :                                                  *****
***** Sortie :                                                     *****
***** Entraine : Le contructeur a initialisé un objet              *****
***** CMatrice<MTYPE> correspondant à une copie de l'objet         *****
***** MATParam                                                     *****
***********************************************************************/
template<class MTYPE> CMatrice<MTYPE>::CMatrice(CMatrice<MTYPE>& MATParam)
{
	uiMATNbColonnes = MATParam.MATLireNbColonnes();
	uiMATNbLignes = MATParam.MATLireNbLignes();
	pMATMatrice = new MTYPE*[uiMATNbLignes];
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		pMATMatrice[i] = new MTYPE[uiMATNbColonnes];
	}
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			pMATMatrice[i][j] = MATParam.MATLireElement(i, j);
		}
	}
};

/***********************************************************************
***** CMATRICE<MTYPE> : Constructeur de comfort de CMatrice<MTYPE> *****
************************************************************************
***** Entrée : - uiNbLignes, entier non signé, nombre de lignes de *****
***** la matrice à créer                                           *****
***** - uiNbColonnes, entier non signé, nombre de colonnes de la   *****
***** matrice à créer                                              *****
***** Nécessite : uiNbLignes et uiNbColonnes entiers positifs      *****
***** Sortie :                                                     *****
***** Entraine : Le contructeur a initialisé un objet              *****
***** CMatrice<MTYPE> comportant uiNbLignes et uiNbColonnes        *****
***********************************************************************/
template<class MTYPE> CMatrice<MTYPE>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;
	pMATMatrice = new MTYPE*[uiMATNbLignes];
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		pMATMatrice[i] = new MTYPE[uiMATNbColonnes];
	}
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			pMATMatrice[i][j] = NULL;
		}
	}
};

/************************************************************
***** ~CMATRICE<MTYPE> : Destructeur de CMatrice<MTYPE> *****
*************************************************************
***** Entrée :                                          *****
***** Nécessite :                                       *****
***** Sortie :                                          *****
***** Entraine : Le destructeur a désalloué tous les    *****
***** éléments de la matrice en mettant leur valeur à   *****
***** NULL                                              *****
************************************************************/
template<class MTYPE> CMatrice<MTYPE>::~CMatrice()
{
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			pMATMatrice[i][j] = NULL;
		}
	}
};

/*************************************************************************
***** MATLireNbLignes : Accesseur direct en lecture de uiMATNbLignes *****
**************************************************************************
***** Entrée :                                                       *****
***** Nécessite :                                                    *****
***** Sortie : entier, valeur de l'attribut uiMATNbLignes            *****
***** Entraine : MATLireNbLignes() = uiMATNbLignes                   *****
*************************************************************************/
template<class MTYPE> int CMatrice<MTYPE>::MATLireNbLignes()
{
	return uiMATNbLignes;
};

/*****************************************************************************
***** MATLireNbColonnes : Accesseur direct en lecture de uiMATNbColonnes *****
******************************************************************************
***** Entrée :                                                           *****
***** Nécessite :                                                        *****
***** Sortie : entier, valeur de l'attribut uiMATNbColonnes              *****
***** Entraine : MATLireNbLignes() = uiMATNbColonnes                     *****
*****************************************************************************/
template<class MTYPE> int CMatrice<MTYPE>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
};

/***************************************************************************************************************************************
***** MATLireElement : Fonction permettant de lire un élément à une position donnée (accesseur indirect en lecture de pMATMatrice) *****
****************************************************************************************************************************************
***** Entrée : - uiIndiceLignes, entier non signé, indice de la ligne de l'élément à lire                                          *****
***** - uiIndiceColonnes, entier non signé, indice de la colonne de l'élément à lire                                               *****
***** Nécessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants à des lignes et colonnes valides              *****
***** Sortie : type générique MTYPE, élément à la ligne uiIndiceLigne et à la colonne uiIndiceColonne                              *****
***** Entraine : MATLireElement(uiIndiceLigne, uiIndiceColonne) = élément à la ligne et à la colonne donnés en paramètres          *****
***************************************************************************************************************************************/
template<class MTYPE> MTYPE CMatrice<MTYPE>::MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{
	// faut tester si uiIndiceLigne >= nbLignes ou si uiIndiceColonne >= nbColonnes
	return pMATMatrice[uiIndiceLigne][uiIndiceColonne];
};

/************************************************************************************************************************************************
***** MATModifierElement : Fonction permettant de modifier un élément à une position donnée (accesseur indirect en écriture de pMATMatrice) *****
*************************************************************************************************************************************************
***** Entrée : - uiIndiceLignes, entier non signé, indice de la ligne de l'élément à modifier                                               *****
***** - uiIndiceColonnes, entier non signé, indice de la colonne de l'élément à modifier                                                    *****
***** - valeur, type générique MTYPE, valeur de l'élément à modifier                                                                        *****
***** Nécessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants à des lignes et colonnes valides et valeur est du même *****
***** type que la matrice                                                                                                                   *****
***** Sortie :                                                                                                                              *****
***** Entraine : élément à la ligne uiIndiceLigne et à la colonne uiIndiceColonne = valeur                                                  *****
************************************************************************************************************************************************/
template<class MTYPE> void CMatrice<MTYPE>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur)
{
	pMATMatrice[uiIndiceLigne][uiIndiceColonne] = valeur;
};

/********************************************************************************************************
***** operator= : Surcharge de l'opérateur = de CMatrice<MTYPE> prenant un CMatrice<MTYPE> à droite *****
*********************************************************************************************************
***** Entrée : MATParam, un objet de type CMatrice<MTYPE>                                           *****
***** Nécessite :                                                                                   *****
***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                        *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à une copie de l'objet     *****
***** MATParam                                                                                      *****
********************************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator=(CMatrice<MTYPE>& MATParam) 
{
	if (pMATMatrice != nullptr) {
		for (unsigned int i = 0; i < uiMATNbLignes; i++) {
			delete[] pMATMatrice[i];
		}
		delete [] pMATMatrice;
	}
	uiMATNbColonnes = MATParam.MATLireNbColonnes();
	uiMATNbLignes = MATParam.MATLireNbLignes();

	pMATMatrice = new MTYPE*[uiMATNbLignes];
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		pMATMatrice[i] = new MTYPE[uiMATNbColonnes];
	}

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			pMATMatrice[i][j] = MATParam.MATLireElement(i, j);
		}
	}
	return *this;
};

/**************************************************************************************************************************************************
***** operator* : Surcharge de l'opérateur * de CMatrice<MTYPE> prenant un entier à droite permettant de multiplier une matrice par un nombre *****
***************************************************************************************************************************************************
***** Entrée : iParam, entier, entier avec lequel multiplier la matrice                                                                       *****
***** Nécessite :                                                                                                                             *****
***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                                  *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat de la multiplication de la matrice avec l'entier en      *****
***** paramètre                                                                                                                               *****
**************************************************************************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator*(int iParam) 
{
	CMatrice<MTYPE>* M1=new CMatrice<MTYPE>(uiMATNbLignes,uiMATNbColonnes);

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			M1->MATModifierElement(i,j, pMATMatrice[i][j]*iParam);
		}
	}
	return *M1;
};

/*
template<class MTYPE> CMatrice<MTYPE>& operator*(int iParam,CMatrice<MTYPE> MATParam)
{
	unsigned int uiMATNbLignes = MATParam.MATLireNbLignes();
	unsigned int uiMATNbColonnes = MATParam.MATLireNbColonnes();
	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			M1->MATModifierElement(i, j, MATParam.MATLireElement(i,j) *iParam);
		}
	}
	return *M1;
};*/

/***********************************************************************************************************************************************
***** operator/ : Surcharge de l'opérateur / de CMatrice<MTYPE> prenant un entier à droite permettant de diviser une matrice par un nombre *****
************************************************************************************************************************************************
***** Entrée : iParam, entier, entier avec lequel diviser la matrice                                                                       *****
***** Nécessite :                                                                                                                          *****
***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                               *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat de la division de la matrice avec l'entier en         *****
***** paramètre                                                                                                                            *****
***********************************************************************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator/(int iParam)
{
	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			M1->MATModifierElement(i, j, (MTYPE)(pMATMatrice[i][j] / iParam));
		}
	}
	return *M1;
};

/*****************************************************************************
***** MATAfficher : Fonction permettant d'afficher une matrice à l'écran *****
******************************************************************************
***** Entrée :                                                           *****
***** Nécessite :                                                        *****
***** Sortie :                                                           *****
***** Entraine : La fonction à affiché le contenu de la matrice à        *****
***** l'écran                                                            *****
*****************************************************************************/
template<class MTYPE> void CMatrice<MTYPE>::MATAfficher() {
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			cout << pMATMatrice[i][j] << " ";
		}
		cout << "\n";
	}
}

/**************************************************************************************
***** MATTransposer : Fonction permettant de calculer la transposée d'une matrice *****
***************************************************************************************
***** Entrée :                                                                    *****
***** Nécessite :                                                                 *****
***** Sortie : objet CMatrice<MTYPE>, retourné par référence                      *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à la     *****
***** transposée de la matrice (les lignes et les colonnes ont été échangées      *****
**************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::MATTransposer()
{
	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbColonnes,uiMATNbLignes);

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			M1->MATModifierElement(j, i, pMATMatrice[i][j]);
		}
	}
	return *M1;
};

/****************************************************************************************************************************************
***** operator+ : Surcharge de l'opérateur + de CMatrice<MTYPE> prenant une matrice à droite permettant d'additionner deux matrices *****
*****************************************************************************************************************************************
***** Entrée : MATParam, un objet de type CMatrice<MTYPE>                                                                           *****
***** Nécessite : La matrice appelante est de la même taille que MATParam                                                           *****
***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                        *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat de la addition de la matrice avec la matrice   *****
***** en paramètre                                                                                                                  *****
****************************************************************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator+(CMatrice<MTYPE> &MATParam) {
	//Faire une exception si les tailles ne sont pas egales.
	
	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			M1->MATModifierElement(i, j, pMATMatrice[i][j]+ MATParam.MATLireElement(i,j));
		}
	}
	return *M1;
};

/****************************************************************************************************************************************
***** operator- : Surcharge de l'opérateur - de CMatrice<MTYPE> prenant une matrice à droite permettant de soustraire deux matrices *****
*****************************************************************************************************************************************
***** Entrée : MATParam, un objet de type CMatrice<MTYPE>                                                                           *****
***** Nécessite : La matrice appelante est de la même taille que MATParam                                                           *****
***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                        *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat de la soustraction de la matrice avec la       *****
***** matrice en paramètre                                                                                                          *****
****************************************************************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator-(CMatrice<MTYPE> &MATParam) {
	//Faire une exception si les tailles ne sont pas egales.

	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			M1->MATModifierElement(i, j, pMATMatrice[i][j] - MATParam.MATLireElement(i, j));
		}
	}
	return *M1;
}

/**********************************************************************************************************************************************
***** operator* : Surcharge de l'opérateur * de CMatrice<MTYPE> prenant une matrice à droite permettant de faire le produit deux matrices *****
***********************************************************************************************************************************************
***** Entrée : MATParam, un objet de type CMatrice<MTYPE>                                                                                 *****
***** Nécessite : La matrice appelante est de la même taille que MATParam                                                                 *****
***** Sortie : objet CMatrice<MTYPE>, retourné par référence                                                                              *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant au résultat du produit de la matrice avec la matrice en          *****
***** paramètre                                                                                                                           *****
**********************************************************************************************************************************************/
template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator*(CMatrice<MTYPE> &MATParam) {
	//Faire une exception si les tailles ne sont pas egales.

	CMatrice<MTYPE>* M1 = new CMatrice<MTYPE>(uiMATNbLignes, uiMATNbColonnes);

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			M1->MATModifierElement(i, j, pMATMatrice[i][j] * MATParam.MATLireElement(i, j));
		}
	}
	return *M1;
}

#endif