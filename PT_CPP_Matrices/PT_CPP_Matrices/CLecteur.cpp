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
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

CLecteur::~CLecteur()
{
	delete[] pcLECNomFichier;
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
	return *this;
}

CMatrice<double>& CLecteur::LECLireFichierMatrice()
{
	//TODO : Vérifier qu'il y a un nom de fichier
	FILE* fichier = fopen(pcLECNomFichier, "r");
	if (!fichier) 
	{
		//TODO : Gérer erreur ouverture
	}
	char pcLigne[1024] = "";
	if (!fgets(pcLigne, 1024, fichier))
	{
		//TODO : ERREUR Lecture
	}
	char pcTypeMatrice[1024] = "";
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
	if (!fgets(pcLigne, 1024, fichier))
	{
		//TODO : ERREUR Lecture
	}
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
	if (!fgets(pcLigne, 1024, fichier))
	{
		//TODO : ERREUR Lecture
	}
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
	if (!fgets(pcLigne, 1024, fichier))
	{
		//TODO : ERREUR Lecture
	}
	if (strncmp(pcLigne, "Matrice=[", 9) != 0)
	{
		//TODO : ERREUR format
	}
	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiNBLignes; uiBoucleIndiceLigne++)
	{
		if (!fgets(pcLigne, 1024, fichier))
		{
			//TODO : ERREUR Lecture
		}
		if (strncmp(pcLigne, "]", 1) == 0)
		{
			//TODO : ERREUR format (car pas assez de lignes)
		}
		double dElement = 0;
		char* pcParcoursChaine = pcLigne;
		unsigned int uiBoucleIndiceColonne = 0;
		while (*pcParcoursChaine != '\n')
		{
			sscanf(pcParcoursChaine, "%lf", &dElement);
			if (uiBoucleIndiceColonne < uiNBColonnes) {
				MATMatrice->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, dElement);
			}
			if (strchr(pcParcoursChaine, ' ')) 
			{
				pcParcoursChaine = strchr(pcParcoursChaine, ' ');
				pcParcoursChaine++;
			}
			else
			{
				pcParcoursChaine = strchr(pcParcoursChaine, '\n');
			}
			uiBoucleIndiceColonne++;
		}
		if (uiBoucleIndiceColonne != uiNBColonnes) 
		{
			//TODO : ERREUR format (car pas assez ou trop de valeurs dans la ligne)
		}
	}
	if (!fgets(pcLigne, 1024, fichier))
	{
		//TODO : ERREUR Lecture
	}
	if (strncmp(pcLigne, "]", 1) != 0)
	{
		//TODO : ERREUR format
	}
	return *MATMatrice;
}