#ifndef CLecteur_h
#define CLecteur_h

#include "CMatrice.h"
#include "CException.h"

#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable : 4996) //Ligne utilis�e pour �viter l'erreur Visual Studio : C4996 This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS

#define NULL 0;
#define NomFichierManquant 5
#define EchecOuvertureFichier 6
#define FormatFichierInvalide 7
#define TypeMatriceFichierInvalide 8

//CLecteur est une classe utilis�e pour la lecture d'un fichier formatt� afin d'en r�cup�rer une matrice de type CMatrice
class CLecteur 
{
	private:
		char* pcLECNomFichier; //Chaine de caract�res, Nom du fichier � lire

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
		void LECModifierNomFichier(char* pcNomFichier);
		/**/
		CLecteur& operator=(CLecteur& LECParam);
		/**/
		CMatrice<double>& LECLireFichierMatrice(); //M�thode non faite sous la forme d'un constructeur de CMatrice car elle fait appel au constructeur CMatrice<MTYPE>(unsigned int uiNbLignes, unsigned int uiNbColonnes) et on ne peut pas appeler un contructeur sur une classe dans un contructeur de cette m�me classe
};

#endif