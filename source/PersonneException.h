/**
 * \file   PersonneException.h
 * \brief  Fichier contenant la déclaration de la classe PersonneException et de ses héritiers
 * \date   2020-12-07
 * \author Maxime Chantal et Julien Hamel
 */

#ifndef PERSONNEEXCEPTION_H_
#define PERSONNEEXCEPTION_H_

#include <string>
#include <stdexcept>

namespace elections {

/**
 * \class PersonneException
 * \brief Classe de base des exceptions de personne.
 */
class PersonneException : public std::runtime_error
{
public:
	PersonneException(const std::string& p_raison);
};

/**
 * \class PersonneDejaPresenteException
 * \brief Classe pour la gestion des erreurs d'ajout de doublons dans la liste des inscrits.
 */
class PersonneDejaPresenteException: public PersonneException
{
public:
	PersonneDejaPresenteException(const std::string& p_raison);
};

/**
 * \class PersonneAbsenteException
 * \brief Classe pour la gestion des erreurs de tentatives d'effacement de personnes absentes
 * 		  de la liste des inscrits.
 */
class PersonneAbsenteException: public PersonneException
{
public:
	PersonneAbsenteException(const std::string& p_raison);
};

} /* namespace elections */

#endif /* PERSONNEEXCEPTION_H_ */
