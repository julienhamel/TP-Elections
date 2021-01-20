/**
 * \file Circonscription.cpp
 * \brief Implémentation de la classe Circonscription
 * \date 2020-11-11
 * \author Maxime Chantal et Julien Hamel
 */


#include "Circonscription.h"
#include "PersonneException.h"
#include <sstream>
#include <vector>

using namespace std;
using namespace elections;

namespace elections {

/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Circonscription à partir de valeurs passées en paramètres.
 * \param[in] p_nomCirconscription est un string qui représente le nom de la circonscription
 * \param[in] p_prenom est un objet Candidat qui représente le candidat sortant
 */
Circonscription::Circonscription(const string& p_nomCirconscription, const Candidat& p_deputeElu)
: m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_deputeElu)
{
	PRECONDITION(!p_nomCirconscription.empty());
	PRECONDITION(m_vInscrits.empty());

	POSTCONDITION(reqNomCirconscription() == p_nomCirconscription);
	POSTCONDITION(reqDeputeElu() == p_deputeElu);
	POSTCONDITION(m_vInscrits.empty());

	INVARIANTS();
}

/**
 * \ Constructeur copie de la classe Circonscription
 */
Circonscription::Circonscription(const Circonscription& p_circonscription)
: m_nomCirconscription(p_circonscription.reqNomCirconscription()), m_deputeElu(p_circonscription.reqDeputeElu())
{
	vector<Personne*>::const_iterator it;
	for(it = p_circonscription.m_vInscrits.begin(); it < p_circonscription.m_vInscrits.end(); it ++)
	{
		Circonscription::inscrire(*(*it));
	}
	INVARIANTS();
}

/**
 * \brief retourne le nom de la circonscription
 * \return un string qui représente le nom de la circonscription
 */
const string& Circonscription::reqNomCirconscription() const
{
	return m_nomCirconscription;
}

/**
 * \brief retourne le candidat sortant de la circonscription
 * \return un objet Candidat qui représente lle candidat sortant de la circonscription
 */
const Candidat& Circonscription::reqDeputeElu() const
{
	return m_deputeElu;
}

/**
 * \brief retourne une circonscription formatée dans une chaîne de caractères (string)
 * \return une circonscription formatée dans une chaîne de caractères
 */
string Circonscription::reqCirconscriptionFormate() const
{
	ostringstream os;
	os << "circonscription : " << reqNomCirconscription() << endl
	   << "Depute sortant :" << endl
	   << reqDeputeElu().reqPersonneFormate() << endl
	   << "Liste des inscrits:" << endl;

	vector<Personne*>::const_iterator it;
	for(it = m_vInscrits.begin(); it < m_vInscrits.end(); it++)
	{
		os << (*it)->reqPersonneFormate() << endl;
	}
	return os.str();
}

/**
 * \brief Inscrit des personnes à une circonscription
 * \param[in] p_nouvelInscrit est un objet Candida ou Electeur à inscrire à la liste
 */
void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	if (personneEstDejaPresente(p_nouvelInscrit.reqNas()))
	{
		ostringstream os;
		os << p_nouvelInscrit.reqPersonneFormate() << endl <<
			  "Personne deja presente dans la liste.";
		throw PersonneDejaPresenteException(os.str());
	}
	else
	{
	m_vInscrits.push_back(p_nouvelInscrit.clone());
	}


	POSTCONDITION(m_vInscrits.back()->reqNas() == p_nouvelInscrit.reqNas());
	POSTCONDITION(m_vInscrits.back()->reqPrenom() == p_nouvelInscrit.reqPrenom());
	POSTCONDITION(m_vInscrits.back()->reqNom() == p_nouvelInscrit.reqNom());
	POSTCONDITION(m_vInscrits.back()->reqDateNaissance() == p_nouvelInscrit.reqDateNaissance());
	POSTCONDITION(m_vInscrits.back()->reqAdresse() == p_nouvelInscrit.reqAdresse());

	INVARIANTS();
}

void Circonscription::desinscrire(const std::string& p_nas)
{
	if(!personneEstDejaPresente(p_nas))
	{
		throw PersonneAbsenteException("Impossible de desinscrire cette personne, elle n'est pas inscrite sur la liste.");
	}
	else
	{
		vector<Personne*>::const_iterator it;
		for(it = m_vInscrits.begin(); it < m_vInscrits.end(); it++)
		{
			if((*it)->reqNas() == p_nas)
			{
				delete (*it);
				m_vInscrits.erase(it);
			}
		}
	}

	INVARIANTS();
}

/**
 * \ Opérateur d'assignation de la classe Circonscription
 */
const Circonscription& Circonscription::operator= (const Circonscription& p_circonscription)
{
	if(this->m_vInscrits != p_circonscription.m_vInscrits or this->reqNomCirconscription() != p_circonscription.reqNomCirconscription()
			or this->reqDeputeElu().reqPersonneFormate() != p_circonscription.reqDeputeElu().reqPersonneFormate())
	{
		vector<Personne*>::const_iterator it;
		for(it = m_vInscrits.begin(); it < m_vInscrits.end(); it++)
		{
			delete (*it);
		}
		for(it = p_circonscription.m_vInscrits.begin(); it < p_circonscription.m_vInscrits.end(); it++)
		{
			Circonscription::inscrire(*(*it));
		}
	}
	return *this;

	INVARIANTS();
}

/**
 * \brief Destructeur de la classe Circonscription
 */
Circonscription::~Circonscription()
{
	vector<Personne*>::const_iterator it;
	for(it = m_vInscrits.begin(); it < m_vInscrits.end(); it++)
	{
		delete (*it);
	}
}

/**
 * \brief Vérfifie si une personne est déjà présente dans la liste électoral
 * \param[in] p_nas est un string représentant le numéro d'assurance social de la
 * 			  personne dont on veut vérfier la présence
 */
bool Circonscription::personneEstDejaPresente(const std::string& p_nas) const
{
	bool personnePresente = false;
	vector<Personne*>::const_iterator it;
	for(it = m_vInscrits.begin(); it < m_vInscrits.end(); it++)
	{
		if ((*it)->reqNas() == p_nas)
			personnePresente = true;
	}
	return personnePresente;
}

/**
 * \brief Teste l'invariant de la classe Circonscription. L'invariant de cette classe s'assure que la
 *        circonscription est valide.
 */
void Circonscription::verifieInvariant() const
{
	INVARIANT(!m_nomCirconscription.empty());
}

} /* namespace elections */
