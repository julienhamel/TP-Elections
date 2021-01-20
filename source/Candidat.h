/**
 * \file Candidat.h
 * \brief Déclaration de la classe Candidat
 * \date 2020-11-05
 * \author Maxime Chantal
 */

#ifndef CANDIDAT_H_
#define CANDIDAT_H_

#include "Personne.h"
#include "ContratException.h"

namespace elections {

enum PartisPolitiques {BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL, NOUVEAU_PARTI_DEMOCRATIQUE};

/**
 * \class Candidat
 * \brief Classe Candidat permettant de modéliser les objets Candidat
 */
class Candidat : public Personne
{
public:
	Candidat(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
			 const util::Date& p_dateNaissance, const util::Adresse& p_adresse, int p_partiPolitique);

	int reqPartiPolitique() const;

	virtual std::string reqPersonneFormate() const;

	virtual Personne* clone() const;

	void verifieInvariant() const;

private:
	int m_partiPolitique;
};

} /* namespace elections */

#endif /* CANDIDAT_H_ */
