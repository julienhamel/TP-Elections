/**
 * \file Personne.h
 * \brief Déclaration de la classe Personne
 * \date 2020-10-04
 * \author Maxime Chantal
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_
#include <string>
#include "Date.h"
#include "Adresse.h"
#include "ContratException.h"

namespace elections {

/**
 * \class Personne
 * \brief Classe Personne permettant de modéliser les objets Personne
 */
class Personne
{
public:
	Personne(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
			 const util::Date& p_dateNaissance, const util::Adresse& p_adresse);

	const std::string& reqNas() const;

	const std::string& reqPrenom() const;

	const std::string& reqNom() const;

	const util::Date& reqDateNaissance() const;

	const util::Adresse& reqAdresse() const;

	void asgNouvelleAdressePersonne(int p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville,
			const std::string& p_codePostal, const std::string& p_province);

	virtual std::string reqPersonneFormate() const = 0;

	bool operator==(const Personne& p_personne) const;

	virtual ~Personne() {} ;

	virtual Personne* clone() const = 0;

private:
	std::string m_nas;
	std::string m_prenom;
	std::string m_nom;
	util::Date m_dateNaissance;
	util::Adresse m_adresse;
	void verifieInvariant() const;

};

} /* namespace elections */

#endif /* PERSONNE_H_ */
