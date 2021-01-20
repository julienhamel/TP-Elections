/**
 * \file validationFormat.h
 * \brief Déclaration des fonctions de validation d'un NAS et d'un format de fichier
 * \date 2020-09-22
 * \author Maxime Chantal
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

namespace util {

bool validerNas(const std::string& p_nas);

bool validerFormatFichier(std::istream& p_is);

} /* namespace util */

#endif /* VALIDATIONFORMAT_H_ */
