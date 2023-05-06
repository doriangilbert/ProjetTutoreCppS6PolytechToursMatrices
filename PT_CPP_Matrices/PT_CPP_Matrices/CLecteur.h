#ifndef CLecteur_h
#define CLecteur_h

#include "CMatrice.h"

#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable : 4996) //Ligne utilisée pour éviter l'erreur Visual Studio : C4996 This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS

#define NULL 0;

class CLecteur 
{
	private:
		char* pcLECNomFichier;

	public:
		/**/
		CLecteur();
		/**/
		CLecteur(CLecteur &LECParam);
		/**/
		CLecteur(char* pcNomFichier);
		/**/
		~CLecteur();
		/**/
		char* LECLireNomFichier();
		/**/
		void LECModifierValeur(char* pcNomFichier);
		/**/
		CLecteur& operator=(CLecteur& LECParam);
		/**/
		CMatrice<double>& LECLireFichierMatrice(); //Méthode non faite sous la forme d'un constructeur de CMatrice car elle fait appel au constructeur CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes) et on ne peut pas appeler un contructeur sur une classe dans un contructeur de cette même classe
};

#endif