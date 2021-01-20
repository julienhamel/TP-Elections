/**
 * \file Candidat.cpp
 * \brief Implémentation de la classe Candidat
 * \date 2020-11-05
 * \author Maxime Chantal
 */

#include "Candidat.h"
#include <iostream>
#include <sstream>
#include "validationFormat.h"
using namespace std;
using namespace elections;

namespace elections {

/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Candidat à partir de valeurs passées en paramètres.
 * \param[in] p_nas est un string qui représente le numéro d'assurance social
 * \param[in] p_prenom est un string qui représente le prenom
 * \param[in] p_nom est un string qui représente le nom
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naissance
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse
 * \param[in] p_partiPolitique est un int qui représente le parti politique en utilisant la liste d'énumération des partis:
 *                  enum PartisPolitiques {BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL, NOUVEAU_PARTI_DEMOCRATIQUE}
 */
Candidat::Candidat(const string& p_nas, const string& p_prenom, const string& p_nom,
		           const util::Date& p_dateNaissance, const util::Adresse& p_adresse, int p_partiPolitique)
: Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse), m_partiPolitique(p_partiPolitique)
{
	PRECONDITION (p_partiPolitique >= BLOC_QUEBECOIS and p_partiPolitique <= NOUVEAU_PARTI_DEMOCRATIQUE);

	POSTCONDITION (reqPartiPolitique() == p_partiPolitique);

	INVARIANTS();
}

/**
 * \brief retourne le nom de le parti politique du candidat
 * \return un entier qui représente le parti
 */
int Candidat::reqPartiPolitique() const
{
	return m_partiPolitique;
}

/**
 * \brief retourne un candidat formaté dans une chaîne de caractères (string)
 * \return un candidat formaté dans une chaîne de caractères
 */
string Candidat::reqPersonneFormate() const
{
	string parti;
	switch(m_partiPolitique)
	{
	case 0 : parti = "Bloc quebecois"; break;
	case 1 : parti = "Conservateur"; break;
	case 2 : parti = "Independant"; break;
	case 3 : parti = "Liberal"; break;
	case 4 : parti = "Nouveau parti democratique"; break;
	}

	ostringstream os;
	os << "Candidat" << endl;
	os << "----------------------------------------------" << endl;
	os << Personne::reqPersonneFormate();
	os << "Parti politique   : " << parti << endl;
	return os.str();
}

/**
 *  \brief Méthode permettant de faire une copie allouée sur le monceau de l'objet courant
 */
Personne* Candidat::clone() const
{
	return new Candidat(*this);
}

/**
 * \brief Teste l'invariant de la classe Candidat. L'invariant de cette classe s'assure que le candidat est valide
 */
void Candidat::verifieInvariant() const
{
	INVARIANT(m_partiPolitique >= BLOC_QUEBECOIS and m_partiPolitique <= NOUVEAU_PARTI_DEMOCRATIQUE)
}

} /* namespace elections */
