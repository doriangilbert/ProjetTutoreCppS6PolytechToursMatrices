#ifndef CLecteur_h
#define CLecteur_h

#include "CMatrice.h"

#include <cstdio>
#include <cstring>
using namespace std;

#define NULL 0;

class CLecteur 
{
	private:
		char* pcLECNomFichier;

	public:
		CLecteur();
		CLecteur(char* pcNomFichier);

		CMatrice<double>& LECLireFichierMatrice();
};

#endif