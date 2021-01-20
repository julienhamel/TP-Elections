/**
 * \file validationFormat.cpp
 * \brief Implémentation des fonctions de validation d'un NAS et d'un format de fichier
 * \date 2020-09-22
 * \author Maxime Chantal
 */

#include "validationFormat.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

namespace util {

/**
 * \brief Fonction qui valide le format d'un numéro d'assurance sociale
 * \param[in] p_nas une chaîne de caractères qui représente le numéro d'assurance sociale
 * \return un booléen qui indique si le format du numéro d'assurance sociale est valide ou non
 * \pre le numéro d'assurance social doit être sous le format 000*000*000 où * peut être n'importe quel caractère
 */
bool validerNas(const string& p_nas)
{
	int somme = 0;
	int chiffre = 0;
	for(int i = 0; i <= 2 ; i++) // Pour les 3 premiers chiffres du NAS
	{
		chiffre = p_nas[i] - '0'; // Code ASCII de l'entier - '0' = l'entier
		if(i % 2 == 0)
		{
			somme = somme + chiffre;
		}
		else
		{
			chiffre = 2 * chiffre;
			if(chiffre > 9)
			/* Si le résultat de la multiplication est un nombre à deux chiffres,
			on les additionne ensemble*/
			{
				if (chiffre == 10) // 2 * 5
				{
					chiffre = 1;
				}
				else if (chiffre == 12) // 2 * 6
				{
					chiffre = 3;
				}
				else if (chiffre == 14) // 2 * 7
				{
					chiffre = 5;
				}
				else if (chiffre == 16) // 2 * 8
				{
					chiffre = 7;
				}
				else if (chiffre == 18) // 2 * 9
				{
					chiffre = 9;
				}
			}
			somme = somme + chiffre;
		}
	}

	for(int i = 4; i <= 6 ; i++) // Pour les chiffres 4 à 6 du NAS
	{
		chiffre = p_nas[i] - '0'; // Code ASCII de l'entier - '0' = l'entier
		if(i % 2 == 0)
		{
			chiffre = 2 * chiffre;
			if(chiffre > 9)
			/* Si le résultat de la multiplication est un nombre à deux chiffres,
			on les additionne ensemble*/
			{
				if (chiffre == 10) // 2 * 5
				{
					chiffre = 1;
				}
				else if (chiffre == 12) // 2 * 6
				{
					chiffre = 3;
				}
				else if (chiffre == 14) // 2 * 7
				{
					chiffre = 5;
				}
				else if (chiffre == 16) // 2 * 8
				{
					chiffre = 7;
				}
				else if (chiffre == 18) // 2 * 9
				{
					chiffre = 9;
				}
			}
			somme = somme + chiffre;
		}
		else
		{
			somme = somme + chiffre;
		}
	}

	for(int i = 8; i <= 10 ; i++) // Pour les chiffres 7 à 9 du NAS
	{
		chiffre = p_nas[i] - '0'; // Code ASCII de l'entier - '0' = l'entier
		if(i % 2 == 0)
		{
			somme = somme + chiffre;
		}
		else
		{
			chiffre = 2 * chiffre;
			if(chiffre > 9)
			/* Si le résultat de la multiplication est un nombre à deux chiffres,
			on les additionne ensemble*/
			{
				if (chiffre == 10) // 2 * 5
				{
					chiffre = 1;
				}
				else if (chiffre == 12) // 2 * 6
				{
					chiffre = 3;
				}
				else if (chiffre == 14) // 2 * 7
				{
					chiffre = 5;
				}
				else if (chiffre == 16) // 2 * 8
				{
					chiffre = 7;
				}
				else if (chiffre == 18) // 2 * 9
				{
					chiffre = 9;
				}
			}
			somme = somme + chiffre;
		}
	}

	if(somme % 10 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * \brief Fonction qui valide le format d'un fichier du député élu et des électeurs d'un circonscription
 * \param[in] p_is un fichier de données texte lu par l’intermédiaire d’un flux d’entrée
 * \return un booléen qui indique si le format du fichier est valide ou non
 * \pre le numéro d'assurance social doit être sous le format 000*000*000 où * peut être n'importe quel autre caractère
 *      et la date de naissance sous le format JJ*MM*AAAA où * peut être aussi n'importe quel caractère
 */
bool validerFormatFichier(std::istream& p_is)
{
	char ligne[256];
	const int NOMBRE_MAX_LIGNES = 100;
	string listeLigne[NOMBRE_MAX_LIGNES];
	int nombreLigne = 0;
	while(p_is.getline(ligne, 255))
	{
		listeLigne[nombreLigne] = ligne;
		nombreLigne++;
	}

	int i = 1;
	while(i < nombreLigne)
	{
		// On véfrifie si c'est un candidat ou nom
		if(listeLigne[i] == "CONSERVATEUR" or listeLigne[i] == "CONSERVATEUR" or listeLigne[i] == "INDEPENDANT"
				or listeLigne[i] == "LIBERAL" or listeLigne[i] == "NOUVEAU_PARTI_DEMOCRATIQUE")
		{
			i++; // On passe à la première information du candidat
			bool nasValide = validerNas(listeLigne[i]); // Vérification de la validité du NAS
			if(nasValide == 0)
			{
				return false;
			}
			i++;
			if(listeLigne[i] == "") // On vérifie que la ligne du prénom n'est pas vide
			{
				return false;
			}
			i++;
			if(listeLigne[i] == "") // On vérifie que la ligne du nom n'est pas vide
			{
				return false;
			}
			i++;
			/* Si l'une des informations précédentes est manquante, lors de la vérification de la
			   date de naissance, nous aurons une erreur */
			if(listeLigne[i] == "") // On vérifie que la ligne de la date de naissance n'est pas vide
			{
				return false;
			}
			else // Si elle n'est pas vide, on vérifie la date est sous un format valide
			{
				int chiffre = 0;
				for(int j = 0; j <= 1; j++) // Pour les deux chiffres du jours
				{
					chiffre = listeLigne[i][j] - '0'; // Code ASCII de l'entier - '0' = l'entier
					if((0 <= chiffre and chiffre <= 9) == false)
					{
						return false;
					}
				}
				for(int j = 3; j <= 4; j++) // Pour les deux chiffres du mois
				{
					chiffre = listeLigne[i][j] - '0'; // Code ASCII de l'entier - '0' = l'entier
					if((0 <= chiffre and chiffre <= 9) == false)
					{
						return false;
					}
				}
				for(int j = 6; j <= 9; j++) // Pour les quatres chiffres de l'année
				{
					chiffre = listeLigne[i][j] - '0'; // Code ASCII de l'entier - '0' = l'entier
					if((0 <= chiffre and chiffre <= 9) == false)
					{
						return false;
					}
				}

			}
			i++;
			if(listeLigne[i] == "") // On vérifie que la ligne de l'adresse n'est pas vide
			{
				return false;
			}
			i++;
		}
		else // Si l'électeur n'est pas un candidat
		{
			bool nasValide = validerNas(listeLigne[i]); // Vérification de la validité du NAS
			if(nasValide == 0)
			{
				return false;
			}
			i++;
			if(listeLigne[i] == "") // On vérifie que la ligne du prénom n'est pas vide
			{
				return false;
			}
			i++;
			if(listeLigne[i] == "") // On vérifie que la ligne du nom n'est pas vide
			{
				return false;
			}
			i++;
			/* Si l'une des informations précédentes est manquante, lors de la vérification de la
			   date de naissance, nous aurons une erreur */
			if(listeLigne[i] == "") // On vérifie que la ligne de la date de naissance n'est pas vide
			{
				return false;
			}
			else // Si elle n'est pas vide, on vérifie la date est sous un format valide
			{
				int chiffre = 0;
				for(int j = 0; j <= 1; j++) // Pour les deux chiffres du jours
				{
					chiffre = listeLigne[i][j] - '0'; // Code ASCII de l'entier - '0' = l'entier
					if((0 <= chiffre and chiffre <= 9) == false)
					{
						return false;
					}
				}
				for(int j = 3; j <= 4; j++) // Pour les deux chiffres du mois
				{
					chiffre = listeLigne[i][j] - '0'; // Code ASCII de l'entier - '0' = l'entier
					if((0 <= chiffre and chiffre <= 9) == false)
					{
						return false;
					}
				}
				for(int j = 6; j <= 9; j++) // Pour les quatres chiffres de l'année
				{
					chiffre = listeLigne[i][j] - '0'; // Code ASCII de l'entier - '0' = l'entier
					if((0 <= chiffre and chiffre <= 9) == false)
					{
						return false;
					}
				}

			}
			i++;
			if(listeLigne[i] == "") // On vérifie que la ligne de l'adresse n'est pas vide
			{
				return false;
			}
			i++;
		}

	}

	return true;
}

} /* namespace util */
