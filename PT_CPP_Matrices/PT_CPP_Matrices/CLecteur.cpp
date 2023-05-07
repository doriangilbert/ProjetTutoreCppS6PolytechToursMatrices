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
	pcLECNomFichier = NULL;
}

char* CLecteur::LECLireNomFichier()
{
	return pcLECNomFichier;
}

void CLecteur::LECModifierNomFichier(char* pcNomFichier)
{
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

CLecteur& CLecteur::operator=(CLecteur& LECParam) 
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
	return *this;
}

CMatrice<double>& CLecteur::LECLireFichierMatrice()
{
	if (!pcLECNomFichier) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NomFichierManquant);
		throw EXCErreur;
	}
	FILE* fichier = fopen(pcLECNomFichier, "r");
	if (!fichier) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(EchecOuvertureFichier);
		throw EXCErreur;
	}
	char pcLigne[1024] = "";
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	char pcTypeMatrice[1024] = "";
	if (strncmp(pcLigne, "TypeMatrice=", 12) != 0) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else 
	{
		sscanf(pcLigne, "TypeMatrice=%s", pcTypeMatrice); //Pour les sscanf : vérifier si on a bien eu le bon type
		if (strcmp(pcTypeMatrice, "double") != 0)
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(TypeMatriceFichierInvalide);
			throw EXCErreur;
		}
	}
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	int iNBLignes = 0;
	unsigned int uiNBLignes = 0;
	if (strncmp(pcLigne, "NBLignes=", 9) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else
	{
		sscanf(pcLigne, "NBLignes=%d", &iNBLignes);
		if (iNBLignes < 0) 
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else 
		{
			uiNBLignes = iNBLignes;
		}
	}
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	int iNBColonnes = 0;
	unsigned int uiNBColonnes = 0;
	if (strncmp(pcLigne, "NBColonnes=", 11) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else
	{
		sscanf(pcLigne, "NBColonnes=%d", &iNBColonnes);
		if (iNBColonnes < 0) 
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else {
			uiNBColonnes = iNBColonnes;
		}
	}
	CMatrice<double>* MATMatrice = new CMatrice<double>(uiNBLignes, uiNBColonnes);
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	if (strncmp(pcLigne, "Matrice=[", 9) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	for (unsigned int uiBoucleIndiceLigne = 0; uiBoucleIndiceLigne < uiNBLignes; uiBoucleIndiceLigne++)
	{
		if (!fgets(pcLigne, 1024, fichier))
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		if (strncmp(pcLigne, "]", 1) == 0)
		{
			//ERREUR : Pas assez de lignes par rapport au NBLignes indiqué
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
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
			//ERREUR : Différence entre le NBColonnes indiqué et le nombre réel de valeurs dans la ligne
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
	}
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	if (strncmp(pcLigne, "]", 1) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	if (fichier)
	{
		fclose(fichier);
	}
	return *MATMatrice;
}