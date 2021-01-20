/**
 * \file Personne.cpp
 * \brief Implémentation de la classe Personne
 * \date 2020-10-04
 * \author Maxime Chantal
 */

#include "Personne.h"
#include <iostream>
#include <sstream>
#include "validationFormat.h"
using namespace std;
using namespace util;

namespace elections {

/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Personne à partir de valeurs passées en paramètres.
 * \param[in] p_nas est un string qui représente le numéro d'assurance social
 * \param[in] p_prenom est un string qui représente le prenom
 * \param[in] p_nom est un string qui représente le nom
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naissance
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse
 */
Personne::Personne(const string& p_nas, const string& p_prenom, const string& p_nom,
		           const Date& p_dateNaissance, const Adresse& p_adresse)
: m_nas(p_nas), m_prenom(p_prenom), m_nom(p_nom), m_dateNaissance(p_dateNaissance), m_adresse(p_adresse)
{
	PRECONDITION (validerNas(p_nas));
	PRECONDITION (!p_prenom.empty());
	PRECONDITION (!p_nom.empty());
	// La validité de p_dateNaissance et p_adresse est validé par leurs classes respectives

	POSTCONDITION (reqNas() == p_nas);
	POSTCONDITION (reqPrenom() == p_prenom);
	POSTCONDITION (reqNom() == p_nom);
	POSTCONDITION (reqDateNaissance() == p_dateNaissance);
	POSTCONDITION (reqAdresse() == p_adresse);

	INVARIANTS();
}

/**
 * \brief retourne le numéro d'assurance social de la personne
 * \return un string qui représente le numéro d'assurance social de la personne
 */
const string& Personne::reqNas() const
{
	return m_nas;
}

/**
 * \brief retourne le prenom de la personne
 * \return un string qui représente le prenom de la personne
 */
const string& Personne::reqPrenom() const
{
	return m_prenom;
}

/**
 * \brief retourne le nom de la personne
 * \return un string qui représente le nom de la personne
 */
const string& Personne::reqNom() const
{
	return m_nom;
}

/**
 * \brief retourne la date de naissance de la personne
 * \return un objet Date qui représente la date de naissance de la personne
 */
const Date& Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}

/**
 * \brief retourne l'adresse de la personne
 * \return un objet Adresse qui représente l'adresse de la personne
 */
const Adresse& Personne::reqAdresse() const
{
	return m_adresse;
}

/**
 * \brief Assigne des nouvelles valeurs à l'objet courant
 * \param[in] p_nas est un string qui représente le numéro d'assurance social
 * \param[in] p_prenom est un string qui représente le prenom
 * \param[in] p_nom est un string qui représente le nom
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naissance
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse
 */
void Personne::asgNouvelleAdressePersonne(int p_numeroCivic, const string& p_nomRue,
		const string& p_ville, const string& p_codePostal, const string& p_province)
{
	// La validité des prés et post conditions sont vérifiées dans Adresse::asgNouvelleAdresse()

	m_adresse.asgNouvelleAdresse(p_numeroCivic, p_nomRue, p_ville, p_codePostal, p_province);

	INVARIANTS();
}

/**
 * \brief retourne une personne formatée dans une chaîne de caractères (string)
 * \return une personne formatée dans une chaîne de caractères
 */
string Personne::reqPersonneFormate() const
{
	ostringstream os;
	os << "NAS               : " << m_nas << endl
	   << "Prenom            : " << m_prenom << endl
	   << "Nom               : " << m_nom << endl
	   << "Date de naissance : " << m_dateNaissance.reqDateFormatee() << endl
	   << "Adresse           : " << m_adresse.reqAdresseFormate() << endl;
	return os.str();
}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_personne qui est une personne valide
 * \return un booléen true indiquant si les deux personnes sont égales, false sinon
 */
bool Personne::operator==(const Personne& p_personne) const
{
	return m_nas == p_personne.m_nas and m_prenom == p_personne.m_prenom
	       and m_nom == p_personne.m_nom and m_dateNaissance == p_personne.m_dateNaissance
		   and m_adresse == p_personne.m_adresse;
}

/**
 * \brief Teste l'invariant de la classe Personne. L'invariant de cette classe s'assure que la personne est valide
 */
void Personne::verifieInvariant() const
{
	INVARIANT(validerNas(m_nas));
	INVARIANT(!m_prenom.empty());
	INVARIANT(!m_nom.empty());
}

} /* namespace elections */
