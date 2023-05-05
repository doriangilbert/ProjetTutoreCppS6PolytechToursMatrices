#include "CLecteur.h"

CLecteur::CLecteur()
{
	pcLECNomFichier = NULL;
}

CLecteur::CLecteur(CLecteur &LECParam) 
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
}

CLecteur::CLecteur(char* pcNomFichier)
{
	//TODO : Allouer chaine
}

CLecteur::~CLecteur()
{
	//TODO : Désallouer suite
}

char* CLecteur::LECLireNomFichier()
{
	return pcLECNomFichier;
}

void CLecteur::LECModifierValeur(char* pcNomFichier)
{
	strcpy(pcLECNomFichier, pcNomFichier);
}

CLecteur& CLecteur::operator=(CLecteur& LECParam) 
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
}

CMatrice<double>& CLecteur::LECLireFichierMatrice()
{
	//TODO : Vérifier qu'il y a un nom de fichier
	FILE* fichier = fopen(pcLECNomFichier, "r");
	if (!fichier) 
	{
		//TODO : Gérer erreur ouverture
	}
	char* pcLigne = NULL;
	fgets(pcLigne, 1024, fichier);
	char* pcTypeMatrice = NULL;
	if (strncmp(pcLigne, "TypeMatrice=", 12) != 0) 
	{
		//TODO : ERREUR format
	}
	else 
	{
		sscanf(pcLigne, "TypeMatrice=%s", pcTypeMatrice); //Pour les sscanf : vérifier si on a bien eu le bon type
		if (strcmp(pcTypeMatrice, "double") != 0)
		{
			//TODO : ERREUR type non double
		}
	}
	fgets(pcLigne, 1024, fichier);
	int iNBLignes = 0;
	unsigned int uiNBLignes = 0;
	if (strncmp(pcLigne, "NBLignes=", 9) != 0)
	{
		//TODO : ERREUR format
	}
	else
	{
		sscanf(pcLigne, "NBLignes=%d", &iNBLignes);
		if (iNBLignes < 0) 
		{
			//TODO : ERREUR valeur négative
		}
		else 
		{
			uiNBLignes = iNBLignes;
		}
	}
	fgets(pcLigne, 1024, fichier);
	int iNBColonnes = 0;
	unsigned int uiNBColonnes = 0;
	if (strncmp(pcLigne, "NBColonnes=", 11) != 0)
	{
		//TODO : ERREUR format
	}
	else
	{
		sscanf(pcLigne, "NBColonnes=%d", &iNBColonnes);
		if (iNBColonnes < 0) 
		{
			//TODO : ERREUR valeur négative
		}
		else {
			uiNBColonnes = iNBColonnes;
		}
	}
	CMatrice<double>* MATMatrice = new CMatrice<double>(uiNBLignes, uiNBColonnes);
	fgets(pcLigne, 1024, fichier);
	if (strncmp(pcLigne, "Matrice=[", 9) != 0)
	{
		//TODO : ERREUR format
	}


	//TODO : Parcourir la suite du fichier et remplir la matrice

	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiNBLignes; uiBoucleIndiceLigne++)
	{
		fgets(pcLigne, 1024, fichier);
		double dElement = 0;
		unsigned int uiIndiceColonne = 0;
		while (sscanf(pcLigne, "%lf", &dElement))
		{
			MATMatrice->MATModifierElement(uiBoucleIndiceLigne, uiIndiceColonne, dElement);
			uiIndiceColonne++;
			if (uiIndiceColonne > uiNBColonnes)
			{
				//TODO : ERREUR format
			}
		}
	}


	fgets(pcLigne, 1024, fichier);
	if (strncmp(pcLigne, "]", 1) != 0)
	{
		//TODO : ERREUR format
	}
	return *MATMatrice;
}