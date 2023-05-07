#include "CLecteur.h"

/*********************************************************
***** CLECTEUR : Constructeur par d�faut de CLecteur *****
**********************************************************
***** Entr�e :                                       *****
***** N�cessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialis� un      *****
***** objet CLecteur avec pcLECNomFichier �gal       *****
***** � NULL                                         *****
*********************************************************/
CLecteur::CLecteur()
{
	pcLECNomFichier = NULL;
}

/*********************************************************
***** CLECTEUR : Constructeur de recopie de CLecteur *****
**********************************************************
***** Entr�e : LECParam, un objet de type CLecteur   *****
***** N�cessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialis� un      *****
***** objet CMatrice<MTYPE> correspondant � une      *****
***** copie de l'objet LECParam                      *****
*********************************************************/
CLecteur::CLecteur(CLecteur &LECParam) 
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
}

/*********************************************************
***** CLECTEUR : Constructeur de confort de CLecteur *****
**********************************************************
***** Entr�e : pcNomFichier, chaine de caract�res,   *****
***** nom du fichier � lire                          *****
***** N�cessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialis� un      *****
***** objet CLecteur ayant                           *****
***** pcLECNomFichier = pcNomFichier                 *****
*********************************************************/
CLecteur::CLecteur(char* pcNomFichier)
{
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

/**********************************************
***** ~CLECTEUR : Destructeur de CLecteur *****
***********************************************
***** Entr�e :                            *****
***** N�cessite :                         *****
***** Sortie :                            *****
***** Entraine : Le destructeur a         *****
***** d�sallou� les pointeurs             *****
**********************************************/
CLecteur::~CLecteur()
{
	pcLECNomFichier = NULL;
}

/*****************************************************************************
***** LECLIRENOMFICHIER : Accesseur direct en lecture de pcLECNomFichier *****
******************************************************************************
***** Entr�e :                                                           *****
***** N�cessite :                                                        *****
***** Sortie : chaine de caract�res, valeur de l'attribut                *****
***** pcLECNomFichier                                                    *****
***** Entraine : LECLireNomFichier() = pcLECNomFichier                   *****
*****************************************************************************/
char* CLecteur::LECLireNomFichier()
{
	return pcLECNomFichier;
}

/**********************************************************************************
***** LECMODIFIERNOMFICHIER : Accesseur direct en �criture de pcLECNomFichier *****
***********************************************************************************
***** Entr�e : pcNomFichier, chaine de caract�res, nouvelle valeur de         *****
***** pcLECNomFichier                                                         *****
***** N�cessite :                                                             *****
***** Sortie :                                                                *****
***** Entraine : pcLECNomFichier = pcNomFichier                               *****
**********************************************************************************/
void CLecteur::LECModifierNomFichier(char* pcNomFichier)
{
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

/******************************************************************************************
***** OPERATOR= : Surcharge de l'op�rateur = de CLecteur prenant un CLecteur � droite *****
*******************************************************************************************
***** Entr�e : LECParam, un objet de type CLecteur                                    *****
***** N�cessite :                                                                     *****
***** Sortie : objet CLecteur, retourn� par r�f�rence                                 *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � une copie  *****
***** de l'objet LECParam                                                             *****
******************************************************************************************/
CLecteur& CLecteur::operator=(CLecteur& LECParam) 
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
	return *this;
}

/*************************************************************************************************
***** LECLIREFICHIERMATRICE : Fonction permettant de cr�er une matrice � partir d'un fichier *****
**************************************************************************************************
***** Entr�e :                                                                               *****
***** N�cessite : - pcLECNomFichier contient un nom de fichier                               *****
***** - Le format du fichier est valide (TypeMatrice=double, NBLignes et NBColonnes �gaux �  *****
***** des entiers positifs, la matrice ne contient que des double et le nombre de            *****
***** lignes/colonnes correspond � NBLignes et NBColonnes                                    *****
***** Sortie : objet CMatrice<double>, retourn� par r�f�rence                                *****
***** Entraine : Un objet CMatrice<double> � �t� initialis� correspondant au contenu du      *****
***** fichier OU                                                                             *****
***** Exception NomFichierManquant : Nom de fichier manquant OU                              *****
***** Exception EchecOuvertureFichier : Echec d'ouverture de fichier OU                      *****
***** Exception FormatFichierInvalide : Format de fichier invalide OU                        *****
***** Exception TypeMatriceFichierInvalide : Type de matrice non pris en charge (!= double)  *****
*************************************************************************************************/
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
		sscanf(pcLigne, "TypeMatrice=%s", pcTypeMatrice); //Pour les sscanf : v�rifier si on a bien eu le bon type
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
			//ERREUR : Pas assez de lignes par rapport au NBLignes indiqu�
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
			//ERREUR : Diff�rence entre le NBColonnes indiqu� et le nombre r�el de valeurs dans la ligne
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