// PT_CPP_Matrices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "CMatrice.h"
#include "CLecteur.h"

using namespace std;

int main(int argc, char* argv[])
{
	//TODO : Vérifier la valeur de argc (argc > 0) et lire argv si la condition est remplie
	CLecteur * LECLecteur = new CLecteur(argv[1]);
	CMatrice<double> MATMatrice = LECLecteur->LECLireFichierMatrice();
	MATMatrice.MATAfficher();

 	CMatrice<double> LISMATListeMatrice[5];
	for (int uiBoucleIndiceListeMatrice = 0; uiBoucleIndiceListeMatrice < 5; uiBoucleIndiceListeMatrice++) {
		LISMATListeMatrice[uiBoucleIndiceListeMatrice] = *(new CMatrice<double>(2, 2));
		for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < 2; uiBoucleIndiceLigne++) {
			for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < 2;uiBoucleIndiceColonne++) {
				LISMATListeMatrice[uiBoucleIndiceListeMatrice].MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, uiBoucleIndiceLigne + uiBoucleIndiceColonne + uiBoucleIndiceListeMatrice);
			}
		}
		cout << "Resultat M"<< uiBoucleIndiceListeMatrice <<"\n";
		LISMATListeMatrice[uiBoucleIndiceListeMatrice].MATAfficher();
	}
	//LISMATListeMatrice[2] = *(new CMatrice<double>(4, 2));
	//for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < 4; uiBoucleIndiceLigne++) {
	//	for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < 2; uiBoucleIndiceColonne++) {
	//		LISMATListeMatrice[2].MATModifierElement(i, uiBoucleIndiceColonne, uiBoucleIndiceLigne + uiBoucleIndiceColonne + 2);
	//	}
	//}
	cout << "Entrer un entier \n";
	int c;
	if (cin >> c) {
		cout << "C'est un entier: " << c << endl;
		for (int uiBoucleIndiceListeMatrice = 0; uiBoucleIndiceListeMatrice < 5; uiBoucleIndiceListeMatrice++) {
			cout << "Resultat M" << uiBoucleIndiceListeMatrice << " * c \n";
			(LISMATListeMatrice[uiBoucleIndiceListeMatrice] * c).MATAfficher();
		}
		for (int uiBoucleIndiceListeMatrice = 0; uiBoucleIndiceListeMatrice < 5; uiBoucleIndiceListeMatrice++) {
			cout << "Resultat M" << uiBoucleIndiceListeMatrice << " * c \n";
			(LISMATListeMatrice[uiBoucleIndiceListeMatrice] / c).MATAfficher();
		}

	}
	else cout << "Ce n'est pas un entier" << endl;
	cout << "Resultat MSomme\n";
	try {
		CMatrice<double> MSomme(LISMATListeMatrice[0]);
		for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < 5; uiBoucleIndiceListeMatrice++) {
			MSomme = MSomme + LISMATListeMatrice[uiBoucleIndiceListeMatrice];
		}
		MSomme.MATAfficher();
		CMatrice<double> MSommeBizarre(LISMATListeMatrice[0]);
		for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < 5; uiBoucleIndiceListeMatrice++) {
			if (uiBoucleIndiceListeMatrice % 2 != 0) {
				MSommeBizarre = MSommeBizarre - LISMATListeMatrice[uiBoucleIndiceListeMatrice];
			}
			else {
				MSommeBizarre = MSommeBizarre + LISMATListeMatrice[uiBoucleIndiceListeMatrice];
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
		for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < 5; uiBoucleIndiceListeMatrice++) {
			MProduit = MProduit * LISMATListeMatrice[uiBoucleIndiceListeMatrice];
		}
		MProduit.MATAfficher();
	}
	catch(CException EXCErreur){
		cout << "Erreur Taille de Matrice non conforme\n";
	}
	
}