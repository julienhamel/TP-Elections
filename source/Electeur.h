/**
 * \file Electeur.h
 * \brief Déclaration de la classe Electeur
 * \date 2020-11-05
 * \author Maxime Chantal
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_

#include "Personne.h"

namespace elections {

/**
 * \class Electeur
 * \brief Classe Electeur permettant de modéliser les objets Electeur
 */
class Electeur : public Personne
{
public:
	Electeur(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
			 const util::Date& p_dateNaissance, const util::Adresse& p_adresse);

	virtual std::string reqPersonneFormate() const;

	virtual Personne* clone() const;

};

} /* namespace elections */

#endif /* ELECTEUR_H_ */
