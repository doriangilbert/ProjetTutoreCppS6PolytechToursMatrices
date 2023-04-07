#include "CMatrice.h"

template<class MTYPE> CMatrice<MTYPE>::CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	uiMATNbLignes = uiNbLignes;
	uiMATNbColonnes = uiMATNbColonnes;
	pMATMatrice = malloc(sizeof(MTYPE*)*uiMATNbColonnes);
	for (unsigned int i = 0; i < uiMATNbColonnes;i++) {
		pMATMatrice[i] = malloc(sizeof(MTYPE)*uiMATNbLignes);
	}
}

template<class MTYPE> int CMatrice<MTYPE>::MATLireNbLignes()
{
	return uiMATNbLignes;
}