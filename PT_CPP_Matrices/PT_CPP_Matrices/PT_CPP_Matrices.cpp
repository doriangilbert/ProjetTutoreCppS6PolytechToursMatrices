// PT_CPP_Matrices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "CMatrice.h"

using namespace std;

int main()
{
 	CMatrice<double> LISMATListeMatrice[5];
	for (int k = 0; k < 5; k++) {
		LISMATListeMatrice[k] = *(new CMatrice<double>(2, 2));
		for (unsigned int i = 0; i < 2; i++) {
			for (unsigned int j = 0; j < 2;j++) {
				LISMATListeMatrice[k].MATModifierElement(i, j, i + j + k);
			}
		}
		cout << "Resultat M"<< k <<"\n";
		LISMATListeMatrice[k].MATAfficher();
	}
	cout << "Entrer un entier \n";
	int c;
	cin >> c;
	for (int k = 0; k < 5; k++) {
		cout << "Resultat M" << k << " * c \n";
		(LISMATListeMatrice[k] * c).MATAfficher();
	}
	for (int k = 0; k < 5; k++) {
		cout << "Resultat M" << k << " * c \n";
		(LISMATListeMatrice[k] / c).MATAfficher();
	}
	CMatrice<double> MSomme(LISMATListeMatrice[0]);
	for (int k = 1; k < 5; k++) {
		MSomme = MSomme + LISMATListeMatrice[k];
	}
	cout << "Resultat MSomme\n";
	MSomme.MATAfficher();
	CMatrice<double> MSommeBizarre(LISMATListeMatrice[0]);
	for (int k = 1; k < 5; k++) {
		if (k % 2 != 0) {
			MSommeBizarre = MSommeBizarre - LISMATListeMatrice[k];
		}
		else {
			MSommeBizarre = MSommeBizarre + LISMATListeMatrice[k];
		}
	}
	cout << "Resultat MSommeBizarre\n";
	MSommeBizarre.MATAfficher();
	
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
