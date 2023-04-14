#ifndef CMatrice_h
#define CMatrice_h
#define NULL 0;

template<class MTYPE> class CMatrice
{
	private:
		unsigned int uiMATNbLignes;
		unsigned int uiMATNbColonnes;
		MTYPE** pMATMatrice;

	public:
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
		CMatrice<MTYPE>();

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
		CMatrice<MTYPE>(CMatrice<MTYPE> &MATParam);

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
		CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes);

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
		~CMatrice<MTYPE>();

		int MATLireNbLignes();
		int MATLireNbColonnes();
		MTYPE MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);
		void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur);
		CMatrice<MTYPE>& operator=(CMatrice<MTYPE> &MATParam);
		CMatrice<MTYPE>& operator*(int iParam);
		CMatrice<MTYPE>& operator/(int iParam);
		void MATAfficher();
		CMatrice<MTYPE>& MATTransposer();
		CMatrice<MTYPE>& operator+(CMatrice<MTYPE> &MATParam);
		CMatrice<MTYPE>& operator-(CMatrice<MTYPE> &MATParam);
		CMatrice<MTYPE>& operator*(CMatrice<MTYPE> &MATParam);

};

#include "CMatrice.cpp"

#endif