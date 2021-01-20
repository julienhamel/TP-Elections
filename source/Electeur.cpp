/**
 * \file Electeur.cpp
 * \brief Implémentation de la classe Electeur
 * \date 2020-11-05
 * \author Maxime Chantal
 */

#include "Electeur.h"
#include <iostream>
#include <sstream>
#include "validationFormat.h"
using namespace std;
using namespace elections;

namespace elections {

/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Electeur à partir de valeurs passées en paramètres.
 * \param[in] p_nas est un string qui représente le numéro d'assurance social
 * \param[in] p_prenom est un string qui représente le prenom
 * \param[in] p_nom est un string qui représente le nom
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naissance
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse
 */
Electeur::Electeur(const string& p_nas, const string& p_prenom, const string& p_nom,
		           const util::Date& p_dateNaissance, const util::Adresse& p_adresse)
: Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
{
	// L'invariant est vérifié par la classe personne, il n'y a aucun autre paramètre de plus
	// ou différent ici.
}

/**
 * \brief retourne un electeur formaté dans une chaîne de caractères (string)
 * \return un electeur formaté dans une chaîne de caractères
 */
string Electeur::reqPersonneFormate() const
{
	ostringstream os;
		os << "Electeur" << endl;
		os << "----------------------------------------------" << endl;
		os << Personne::reqPersonneFormate();
		return os.str();
}

/**
 *  \brief Méthode permettant de faire une copie allouée sur le monceau de l'objet courant
 */
Personne* Electeur::clone() const
{
	return new Electeur(*this);
}

} /* namespace elections */
