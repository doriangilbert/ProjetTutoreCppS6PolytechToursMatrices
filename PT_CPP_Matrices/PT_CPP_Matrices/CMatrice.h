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
		CMatrice<MTYPE>(CMatrice<MTYPE>);
};

#endif 

