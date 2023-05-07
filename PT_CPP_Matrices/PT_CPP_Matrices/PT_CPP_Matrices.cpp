// PT_CPP_Matrices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "CMatrice.h"
#include "CLecteur.h"


int main(int argc,char* argv[])
{

	int iNombreParametres = (argc - 1);
	cout << iNombreParametres << "\n";
	//On voit si on a bien des parametres en entrée
	if (iNombreParametres > 0) {
		CMatrice<double>* LISMATListeMatrice1 = new CMatrice<double>[iNombreParametres];
		CLecteur LECLecteur;
		try {
			//Boucle pour remplir la liste de Matrice
			for (int iBoucle = 1; iBoucle < argc; iBoucle++) {
				LECLecteur.LECModifierNomFichier(argv[iBoucle]);
				CMatrice<double> MATMatrice = LECLecteur.LECLireFichierMatrice();
				LISMATListeMatrice1[iBoucle - 1] = MATMatrice;
				cout << "Resultat M" << iBoucle << "\n";
				(LISMATListeMatrice1[iBoucle - 1]).MATAfficher();
			}
			cout << "Entrer un entier \n";
			int c;
			// Si c'est bien un entier on peut faire la multiplication Mk*c ou Mk/c
			if (cin >> c) {
				cout << "C'est un entier: " << c << endl;
				try {
					//Resultat des Mk *c
					for (int uiBoucleIndiceListeMatrice = 0; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
						cout << "Resultat M" << uiBoucleIndiceListeMatrice + 1 << " * c \n";
						(LISMATListeMatrice1[uiBoucleIndiceListeMatrice] * c).MATAfficher();
					}
					//Resultat des Mk / c
					for (int uiBoucleIndiceListeMatrice = 0; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
						cout << "Resultat M" << uiBoucleIndiceListeMatrice + 1 << " / c \n";
						(LISMATListeMatrice1[uiBoucleIndiceListeMatrice] / c).MATAfficher();
					}
				}
				catch (CException EXCErreur) {
					if (EXCErreur.EXCLireValeur() == DivisionPar0) cout << "Division par 0\n";
				}

			}
			else cout << "Ce n'est pas un entier" << endl;
			// On calcule la somme des Mk et la somme des M1+M2-M3....
			cout << "Resultat MSomme\n";
			try {
				CMatrice<double> MSomme(LISMATListeMatrice1[0]);
				for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
					MSomme = MSomme + LISMATListeMatrice1[uiBoucleIndiceListeMatrice];
				}
				MSomme.MATAfficher();
				CMatrice<double> MSommeBizarre(LISMATListeMatrice1[0]);
				for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
					if (uiBoucleIndiceListeMatrice % 2 != 0) {
						MSommeBizarre = MSommeBizarre - LISMATListeMatrice1[uiBoucleIndiceListeMatrice];
					}
					else {
						MSommeBizarre = MSommeBizarre + LISMATListeMatrice1[uiBoucleIndiceListeMatrice];
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
				CMatrice<double> MProduit(LISMATListeMatrice1[0]);
				for (int uiBoucleIndiceListeMatrice = 1; uiBoucleIndiceListeMatrice < iNombreParametres; uiBoucleIndiceListeMatrice++) {
					MProduit = MProduit * LISMATListeMatrice1[uiBoucleIndiceListeMatrice];
				}
				MProduit.MATAfficher();
			}
			catch (CException EXCErreur) {
				cout << "Erreur Taille de Matrice non conforme\n";
			}
		}
		catch (CException EXCErreur) {
			cout << "Code d'erreur"<<EXCErreur.EXCLireValeur()<< endl;
		}
		delete[] LISMATListeMatrice1;
	}
	else {
		cout << "Pas de paramètre \n";
	}
	
}