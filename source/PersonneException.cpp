/**
 * \file   PersonneException.cpp
 * \brief  Implantation de la classe PersonneException et de ses héritiers
 * \date   2020-12-07
 * \author Maxime Chantal et Julien Hamel
 */

#include "PersonneException.h"

using namespace std;

namespace elections {

/**
 * \brief Constructeur de la classe de base PersonneException
 * \param p_raison chaîne de caractères représentant la raion de l'erreur
 */
PersonneException::PersonneException(const string& p_raison)
: runtime_error(p_raison)
{
}

/**
 * \brief Constructeur de la classe de base PersonneDejaPresenteException
 * \param p_raison chaîne de caractères représentant la raion de l'erreur
 */
PersonneDejaPresenteException::PersonneDejaPresenteException(const string& p_raison)
: PersonneException(p_raison)
{
}

/**
 * \brief Constructeur de la classe de base PersonneAbsenteException
 * \param p_raison chaîne de caractères représentant la raion de l'erreur
 */
PersonneAbsenteException::PersonneAbsenteException(const string& p_raison)
: PersonneException(p_raison)
{
}

} /* namespace elections */
