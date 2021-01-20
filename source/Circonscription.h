/**
 * \file Circonscription.h
 * \brief Déclaration de la classe Circonscription
 * \date 2020-11-11
 * \author Maxime Chantal et Julien Hamel
 */


#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_

#include "Personne.h"
#include "Candidat.h"
#include "validationFormat.h"
#include <vector>

namespace elections {

/**
 * \class Circonscription
 * \brief Classe Circonscription permettant de modéliser les objets Circonscription
 */
class Circonscription
{
public:
	Circonscription(const std::string& p_nomCirconscription, const elections::Candidat& p_deputeElu);

	Circonscription(const Circonscription& p_circonscription);

	const std::string& reqNomCirconscription() const;

	const elections::Candidat& reqDeputeElu() const;

	std::string reqCirconscriptionFormate() const;

	void inscrire(const elections::Personne& p_nouvelInscrit);

	void desinscrire(const std::string& p_nas);

	const Circonscription& operator= (const Circonscription& p_circonscription);

	~ Circonscription ();

private:
	std::string m_nomCirconscription;
	elections::Candidat m_deputeElu;
	std::vector<Personne*> m_vInscrits;
	bool personneEstDejaPresente(const std::string& p_nas) const;
	void verifieInvariant() const;
};

} /* namespace elections */

#endif /* CIRCONSCRIPTION_H_ */
