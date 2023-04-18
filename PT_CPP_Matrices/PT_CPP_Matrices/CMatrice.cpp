#ifndef CMatrice_cpp
#define CMatrice_cpp

#include "CMatrice.h"

/***********************************************************************
***** CMATRICE<MTYPE> : Constructeur par d�faut de CMatrice<MTYPE> *****
************************************************************************
***** Entr�e :                                                     *****
***** N�cessite :                                                  *****
***** Sortie :                                                     *****
***** Entraine : Le contructeur a initialis� un objet              *****
***** CMatrice<MTYPE> avec uiMATNbLignes et uiMATNbColonnes �gaux  *****
***** � 0 et pMATMatrice � NULL                                    *****
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
***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>          *****
***** N�cessite :                                                  *****
***** Sortie :                                                     *****
***** Entraine : Le contructeur a initialis� un objet              *****
***** CMatrice<MTYPE> correspondant � une copie de l'objet         *****
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
***** Entr�e : - uiNbLignes, entier non sign�, nombre de lignes de *****
***** la matrice � cr�er                                           *****
***** - uiNbColonnes, entier non sign�, nombre de colonnes de la   *****
***** matrice � cr�er                                              *****
***** N�cessite : uiNbLignes et uiNbColonnes entiers positifs      *****
***** Sortie :                                                     *****
***** Entraine : Le contructeur a initialis� un objet              *****
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
***** Entr�e :                                          *****
***** N�cessite :                                       *****
***** Sortie :                                          *****
***** Entraine : Le destructeur a d�sallou� tous les    *****
***** �l�ments de la matrice en mettant leur valeur �   *****
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
***** Entr�e :                                                       *****
***** N�cessite :                                                    *****
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
***** Entr�e :                                                           *****
***** N�cessite :                                                        *****
***** Sortie : entier, valeur de l'attribut uiMATNbColonnes              *****
***** Entraine : MATLireNbLignes() = uiMATNbColonnes                     *****
*****************************************************************************/
template<class MTYPE> int CMatrice<MTYPE>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
};

/***************************************************************************************************************************************
***** MATLireElement : Fonction permettant de lire un �l�ment � une position donn�e (accesseur indirect en lecture de pMATMatrice) *****
****************************************************************************************************************************************
***** Entr�e : - uiIndiceLignes, entier non sign�, indice de la ligne de l'�l�ment � lire                                          *****
***** - uiIndiceColonnes, entier non sign�, indice de la colonne de l'�l�ment � lire                                               *****
***** N�cessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants � des lignes et colonnes valides              *****
***** Sortie : type g�n�rique MTYPE, �l�ment � la ligne uiIndiceLigne et � la colonne uiIndiceColonne                              *****
***** Entraine : MATLireElement(uiIndiceLigne, uiIndiceColonne) = �l�ment � la ligne et � la colonne donn�s en param�tres          *****
***************************************************************************************************************************************/
template<class MTYPE> MTYPE CMatrice<MTYPE>::MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{
	// faut tester si uiIndiceLigne >= nbLignes ou si uiIndiceColonne >= nbColonnes
	return pMATMatrice[uiIndiceLigne][uiIndiceColonne];
};

/************************************************************************************************************************************************
***** MATModifierElement : Fonction permettant de modifier un �l�ment � une position donn�e (accesseur indirect en �criture de pMATMatrice) *****
*************************************************************************************************************************************************
***** Entr�e : - uiIndiceLignes, entier non sign�, indice de la ligne de l'�l�ment � modifier                                               *****
***** - uiIndiceColonnes, entier non sign�, indice de la colonne de l'�l�ment � modifier                                                    *****
***** - valeur, type g�n�rique MTYPE, valeur de l'�l�ment � modifier                                                                        *****
***** N�cessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants � des lignes et colonnes valides et valeur est du m�me *****
***** type que la matrice                                                                                                                   *****
***** Sortie :                                                                                                                              *****
***** Entraine : �l�ment � la ligne uiIndiceLigne et � la colonne uiIndiceColonne = valeur                                                  *****
************************************************************************************************************************************************/
template<class MTYPE> void CMatrice<MTYPE>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur)
{
	pMATMatrice[uiIndiceLigne][uiIndiceColonne] = valeur;
};

/********************************************************************************************************
***** operator= : Surcharge de l'op�rateur = de CMatrice<MTYPE> prenant un CMatrice<MTYPE> � droite *****
*********************************************************************************************************
***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>                                           *****
***** N�cessite :                                                                                   *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                        *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � une copie de l'objet     *****
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
***** operator* : Surcharge de l'op�rateur * de CMatrice<MTYPE> prenant un entier � droite permettant de multiplier une matrice par un nombre *****
***************************************************************************************************************************************************
***** Entr�e : iParam, entier, entier avec lequel multiplier la matrice                                                                       *****
***** N�cessite :                                                                                                                             *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                                  *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la multiplication de la matrice avec l'entier en      *****
***** param�tre                                                                                                                               *****
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
***** operator/ : Surcharge de l'op�rateur / de CMatrice<MTYPE> prenant un entier � droite permettant de diviser une matrice par un nombre *****
************************************************************************************************************************************************
***** Entr�e : iParam, entier, entier avec lequel diviser la matrice                                                                       *****
***** N�cessite :                                                                                                                          *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                               *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la division de la matrice avec l'entier en         *****
***** param�tre                                                                                                                            *****
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
***** MATAfficher : Fonction permettant d'afficher une matrice � l'�cran *****
******************************************************************************
***** Entr�e :                                                           *****
***** N�cessite :                                                        *****
***** Sortie :                                                           *****
***** Entraine : La fonction � affich� le contenu de la matrice �        *****
***** l'�cran                                                            *****
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
***** MATTransposer : Fonction permettant de calculer la transpos�e d'une matrice *****
***************************************************************************************
***** Entr�e :                                                                    *****
***** N�cessite :                                                                 *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                      *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � la     *****
***** transpos�e de la matrice (les lignes et les colonnes ont �t� �chang�es      *****
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
***** operator+ : Surcharge de l'op�rateur + de CMatrice<MTYPE> prenant une matrice � droite permettant d'additionner deux matrices *****
*****************************************************************************************************************************************
***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>                                                                           *****
***** N�cessite : La matrice appelante est de la m�me taille que MATParam                                                           *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                        *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la addition de la matrice avec la matrice   *****
***** en param�tre                                                                                                                  *****
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
***** operator- : Surcharge de l'op�rateur - de CMatrice<MTYPE> prenant une matrice � droite permettant de soustraire deux matrices *****
*****************************************************************************************************************************************
***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>                                                                           *****
***** N�cessite : La matrice appelante est de la m�me taille que MATParam                                                           *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                        *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat de la soustraction de la matrice avec la       *****
***** matrice en param�tre                                                                                                          *****
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
***** operator* : Surcharge de l'op�rateur * de CMatrice<MTYPE> prenant une matrice � droite permettant de faire le produit deux matrices *****
***********************************************************************************************************************************************
***** Entr�e : MATParam, un objet de type CMatrice<MTYPE>                                                                                 *****
***** N�cessite : La matrice appelante est de la m�me taille que MATParam                                                                 *****
***** Sortie : objet CMatrice<MTYPE>, retourn� par r�f�rence                                                                              *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant au r�sultat du produit de la matrice avec la matrice en          *****
***** param�tre                                                                                                                           *****
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