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
	//LISMATListeMatrice[2] = *(new CMatrice<double>(4, 2));
	//for (unsigned int i = 0; i < 4; i++) {
	//	for (unsigned int j = 0; j < 2; j++) {
	//		LISMATListeMatrice[2].MATModifierElement(i, j, i + j + 2);
	//	}
	//}
	cout << "Entrer un entier \n";
	int c;
	if (cin >> c) {
		cout << "C'est un entier: " << c << endl;
		for (int k = 0; k < 5; k++) {
			cout << "Resultat M" << k << " * c \n";
			(LISMATListeMatrice[k] * c).MATAfficher();
		}
		for (int k = 0; k < 5; k++) {
			cout << "Resultat M" << k << " * c \n";
			(LISMATListeMatrice[k] / c).MATAfficher();
		}

	}
	else cout << "Ce n'est pas un entier" << endl;
	cout << "Resultat MSomme\n";
	try {
		CMatrice<double> MSomme(LISMATListeMatrice[0]);
		for (int k = 1; k < 5; k++) {
			MSomme = MSomme + LISMATListeMatrice[k];
		}
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
	catch (CException EXCErreur) {
		cout << "Erreur Taille de Matrice non conforme\n";
	}
	cout << "Resultat MProduit\n";
	try {
		CMatrice<double> MProduit(LISMATListeMatrice[0]);
		for (int k = 1; k < 5; k++) {
			MProduit = MProduit * LISMATListeMatrice[k];
		}
		MProduit.MATAfficher();
	}
	catch(CException EXCErreur){
		cout << "Erreur Taille de Matrice non conforme\n";
	}
	
}