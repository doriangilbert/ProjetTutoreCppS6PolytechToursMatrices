#ifndef CMatrice_cpp
#define CMatrice_cpp

#include "CMatrice.h"
//sur les constructeurs mettre MTYPE a un pointeur (char*) ne marche pas.
template<class MTYPE> CMatrice<MTYPE>::CMatrice()
{
	uiMATNbLignes = 0;
	uiMATNbColonnes = 0;
	pMATMatrice = NULL;
};

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
	//VOIR POUR UTILISER NEW AU LIEU DE MALLOC
};

template<class MTYPE> CMatrice<MTYPE>::~CMatrice()
{
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			pMATMatrice[i][j] = NULL;
		}
	}
};

template<class MTYPE> int CMatrice<MTYPE>::MATLireNbLignes()
{
	return uiMATNbLignes;
};

template<class MTYPE> int CMatrice<MTYPE>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
};

template<class MTYPE> MTYPE CMatrice<MTYPE>::MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{
	// faut tester si uiIndiceLigne >= nbLignes ou si uiIndiceColonne >= nbColonnes
	return pMATMatrice[uiIndiceLigne][uiIndiceColonne];
};

template<class MTYPE> void CMatrice<MTYPE>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur)
{
	pMATMatrice[uiIndiceLigne][uiIndiceColonne] = valeur;
};

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

template<class MTYPE> CMatrice<MTYPE>& CMatrice<MTYPE>::operator*(int iParam) 
{
	CMatrice<MTYPE>* M1=new CMatrice<MTYPE>(uiMATNbLignes,uiMATNbColonnes);

	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			M1->MATModifierElement(i,j, (MTYPE)(pMATMatrice[i][j]*iParam));
		}
	}
	return *M1;
};

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
template<class MTYPE> void CMatrice<MTYPE>::MATAfficher() {
	for (unsigned int i = 0; i < uiMATNbLignes; i++) {
		for (unsigned int j = 0; j < uiMATNbColonnes; j++) {
			cout << pMATMatrice[i][j] << " ";
		}
		cout << "\n";
	}
}
#endif