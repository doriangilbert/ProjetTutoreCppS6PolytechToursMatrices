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