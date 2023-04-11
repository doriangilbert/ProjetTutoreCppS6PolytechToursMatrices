#ifndef CMatrice_h
#define CMatrice_h

template<class MTYPE> class CMatrice
{
	private:
		unsigned int uiMATNbLignes;
		unsigned int uiMATNbColonnes;
		MTYPE** pMATMatrice;

	public:
		CMatrice<MTYPE>();
		CMatrice<MTYPE>(CMatrice<MTYPE> &MATParam);
		CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes);
		~CMatrice<MTYPE>();

		int MATLireNbLignes();
		int MATLireNbColonnes();
		MTYPE MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);
		void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MTYPE valeur);
};

#include "CMatrice.cpp"

#endif