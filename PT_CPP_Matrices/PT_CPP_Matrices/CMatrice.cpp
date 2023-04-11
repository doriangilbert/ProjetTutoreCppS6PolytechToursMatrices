#ifndef CMatrice_cpp
#define CMatrice_cpp

#include "CMatrice.h"

template<class MTYPE> CMatrice<MTYPE>::CMatrice<MTYPE>()
{

};

template<class MTYPE> CMatrice<MTYPE>::CMatrice<MTYPE>(CMatrice<MTYPE>& MATParam)
{

};

template<class MTYPE> CMatrice<MTYPE>::CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiNbColonnes;
	pMATMatrice = (MTYPE**)malloc(sizeof(MTYPE*) * uiMATNbColonnes);
	for (unsigned int i = 0; i < uiMATNbColonnes; i++) {
		pMATMatrice[i] = (MTYPE*)malloc(sizeof(MTYPE) * uiMATNbLignes);
	}

	//VOIR POUR UTILISER NEW AU LIEU DE MALLOC
};

template<class MTYPE> CMatrice<MTYPE>::~CMatrice<MTYPE>()
{

};

template<class MTYPE> int CMatrice<MTYPE>::MATLireNbLignes()
{
	return uiMATNbLignes;
};

template<class MTYPE> int CMatrice<MTYPE>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
};

template<class MTYPE> MTYPE MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{
	
};

template<class MTYPE> void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur)
{
	
};

#endif