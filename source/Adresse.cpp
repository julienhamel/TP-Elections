/**
 * \file Adresse.cpp
 * \brief Implémentation de la classe Adresse
 * \date 2020-10-04
 * \author Maxime Chantal
 */

#include "Adresse.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace util {

/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Adresse à partir de valeurs passées en paramètres.
 * \param[in] p_numeroCivic est un entier qui représente le numéro civique
 * \param[in] p_nomRue est un string qui représente le nom de la rue
 * \param[in] p_ville est un string qui représente le nom de la ville
 * \param[in] p_codePostal est un string qui représente le code postal
 * \param[in] p_province est un string qui représente la province
 */
Adresse::Adresse(int p_numeroCivic, const string& p_nomRue,
		const string& p_ville, const string& p_codePostal, const string& p_province)
: m_numeroCivic(p_numeroCivic), m_nomRue(p_nomRue), m_ville(p_ville), m_codePostal(p_codePostal),
  m_province(p_province)
{
	PRECONDITION (p_numeroCivic >= 0);
	PRECONDITION (!p_nomRue.empty());
	PRECONDITION (!p_ville.empty());
	PRECONDITION (!p_codePostal.empty());
	PRECONDITION (!p_province.empty());

	POSTCONDITION (reqNumeroCivic() == p_numeroCivic);
	POSTCONDITION (reqNomRue() == p_nomRue);
	POSTCONDITION (reqVille() == p_ville);
	POSTCONDITION (reqCodePostal() == p_codePostal);
	POSTCONDITION (reqProvince() == p_province);

	INVARIANTS();
}

/**
 * \brief retourne le numéro civique de l'adresse
 * \return un entier qui représente le numéro civique de l'adresse
 */
int Adresse::reqNumeroCivic() const
{
	return m_numeroCivic;
}

/**
 * \brief retourne le nom de la rue de l'adresse
 * \return un string qui représente le nom de la rue de l'adresse
 */
const string& Adresse::reqNomRue() const
{
	return m_nomRue;
}

/**
 * \brief retourne le nom de la ville de l'adresse
 * \return un string qui représente le nom de la ville de l'adresse
 */
const string& Adresse::reqVille() const
{
	return m_ville;
}

/**
 * \brief retourne le code postal de l'adresse
 * \return un string qui représente le code postal de l'adresse
 */
const string& Adresse::reqCodePostal() const
{
	return m_codePostal;
}

/**
 * \brief retourne la province de l'adresse
 * \return un string qui représente la province de l'adresse
 */
const string& Adresse::reqProvince() const
{
	return m_province;
}

/**
 * \brief Assigne des nouvelles valeurs à l'objet courant
 * \param[in] p_numeroCivic est un entier qui représente le numéro civique
 * \param[in] p_nomRue est un string qui représente le nom de la rue
 * \param[in] p_ville est un string qui représente le nom de la ville
 * \param[in] p_codePostal est un string qui représente le code postal
 * \param[in] p_province est un string qui représente la province
 */
void Adresse::asgNouvelleAdresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville,
		const string& p_codePostal, const string& p_province)
{

	PRECONDITION (p_numeroCivic >= 0);
	PRECONDITION (!p_nomRue.empty());
	PRECONDITION (!p_ville.empty());
	PRECONDITION (!p_codePostal.empty());
	PRECONDITION (!p_province.empty());

	m_numeroCivic = p_numeroCivic;
	m_nomRue = p_nomRue;
	m_ville = p_ville;
	m_codePostal = p_codePostal;
	m_province = p_province;

	POSTCONDITION (reqNumeroCivic() == p_numeroCivic);
	POSTCONDITION (reqNomRue() == p_nomRue);
	POSTCONDITION (reqVille() == p_ville);
	POSTCONDITION (reqCodePostal() == p_codePostal);
	POSTCONDITION (reqProvince() == p_province);

	INVARIANTS();
}

/**
 * \brief retourne une adresse formatée dans une chaîne de caractères (string)
 * \return une adresse formatée dans une chaîne de caractères
 */
string Adresse::reqAdresseFormate() const
{
	ostringstream os;
	os << m_numeroCivic << ", " << m_nomRue << ", " << m_ville << ", "
	   << m_codePostal << ", " << m_province;
	return os.str();
}

/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_adresse qui est une adresse valide
 * \return un booléen indiquant si les deux personnes sont égales ou pas
 */
bool Adresse::operator==(const Adresse& p_adresse) const
{
	return m_numeroCivic == p_adresse.m_numeroCivic and m_nomRue == p_adresse.m_nomRue
	       and m_ville == p_adresse.m_ville and m_codePostal == p_adresse.m_codePostal
		   and m_province == p_adresse.m_province;
}

/**
 * \brief Teste l'invariant de la classe Adresse. L'invariant de cette classe s'assure que l'adresse est valide
 */
void Adresse::verifieInvariant() const
{
	INVARIANT(m_numeroCivic >= 0);
	INVARIANT(!m_nomRue.empty());
	INVARIANT(!m_ville.empty());
	INVARIANT(!m_codePostal.empty());
	INVARIANT(!m_province.empty());
}

} /* namespace util */
