// PT_CPP_Matrices.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "CMatrice.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 
    CMatrice<int> M1(3,4);
    cout << M1.MATLireNbLignes() << "\n";
    cout << M1.MATLireNbColonnes() << "\n";

	CMatrice<int> M2(2, 5);
	M2.MATModifierElement(1, 3, 5);
	cout << M2.MATLireElement(1, 3) << "\n";
	CMatrice<int> M3(M2),M4;
	cout << M3.MATLireElement(1, 3) << "\n";
	//marche pas avec les pointeur voila.
	M4 = M3;
	cout << M4.MATLireElement(1, 3) << "\n";
	M3=M3*4;
	cout << M3.MATLireElement(1, 3) << "\n";


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
