#ifndef CMatrice_h
#define CMatrice_h

#include <iostream>
using namespace std;

#define NULL 0;

//CMatrice est un patron de classe permettant de manipuler des matrices d'�l�ments de type quelconque (type g�n�rique MTYPE)
template<class MTYPE> class CMatrice
{
	private:
		unsigned int uiMATNbLignes; //Entier non sign�, Nombre de lignes de la matrice
		unsigned int uiMATNbColonnes; //Entier non sign�, Nombre de colonnes de la matrice
		MTYPE** pMATMatrice; //Tableau 2D de MTYPE (type g�n�rique) stockant les �l�ments de la matrice

	public:
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
		CMatrice<MTYPE>();

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
		CMatrice<MTYPE>(CMatrice<MTYPE> &MATParam);

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
		CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes);

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
		~CMatrice<MTYPE>();

		/*************************************************************************
		***** MATLireNbLignes : Accesseur direct en lecture de uiMATNbLignes *****
		**************************************************************************
		***** Entr�e :                                                       *****
		***** N�cessite :                                                    *****
		***** Sortie : entier, valeur de l'attribut uiMATNbLignes            *****
		***** Entraine : MATLireNbLignes() = uiMATNbLignes                   *****
		*************************************************************************/
		int MATLireNbLignes();

		/*****************************************************************************
		***** MATLireNbColonnes : Accesseur direct en lecture de uiMATNbColonnes *****
		******************************************************************************
		***** Entr�e :                                                           *****
		***** N�cessite :                                                        *****
		***** Sortie : entier, valeur de l'attribut uiMATNbColonnes              *****
		***** Entraine : MATLireNbLignes() = uiMATNbColonnes                     *****
		*****************************************************************************/
		int MATLireNbColonnes();

		/***************************************************************************************************************************************
		***** MATLireElement : Fonction permettant de lire un �l�ment � une position donn�e (accesseur indirect en lecture de pMATMatrice) *****
		****************************************************************************************************************************************
		***** Entr�e : - uiIndiceLignes, entier non sign�, indice de la ligne de l'�l�ment � lire                                          *****
		***** - uiIndiceColonnes, entier non sign�, indice de la colonne de l'�l�ment � lire                                               *****
		***** N�cessite : uiIndiceLignes et uiIndiceColonnes entiers positifs correspondants � des lignes et colonnes valides              *****
		***** Sortie : type g�n�rique MTYPE, �l�ment � la ligne uiIndiceLigne et � la colonne uiIndiceColonne                              *****
		***** Entraine : MATLireElement(uiIndiceLigne, uiIndiceColonne) = �l�ment � la ligne et � la colonne donn�s en param�tres          *****
		***************************************************************************************************************************************/
		MTYPE MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);

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
		void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur);

		/**/
		CMatrice<MTYPE>& operator=(CMatrice<MTYPE> &MATParam);

		/**/
		CMatrice<MTYPE>& operator*(int iParam);

		/**/
		CMatrice<MTYPE>& operator/(int iParam);

		/**/
		void MATAfficher();

		/**/
		CMatrice<MTYPE>& MATTransposer();

		/**/
		CMatrice<MTYPE>& operator+(CMatrice<MTYPE> &MATParam);

		/**/
		CMatrice<MTYPE>& operator-(CMatrice<MTYPE> &MATParam);

		/**/
		CMatrice<MTYPE>& operator*(CMatrice<MTYPE> &MATParam);

};

#include "CMatrice.cpp"

#endif