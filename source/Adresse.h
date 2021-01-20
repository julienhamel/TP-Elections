/**
 * \file Adresse.h
 * \brief Déclaration de la classe Adresse
 * \date 2020-10-04
 * \author Maxime Chantal
 */

#ifndef ADRESSE_H_
#define ADRESSE_H_
#include <string>
#include "ContratException.h"

namespace util
{
/**
 * \class Adresse
 * \brief Classe Adresse permettant de modéliser les objets Adresse
 */
class Adresse
{
public:
	Adresse(int p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville,
			const std::string& p_codePostal, const std::string& p_province);

	int reqNumeroCivic() const;

	const std::string& reqNomRue() const;

	const std::string& reqVille() const;

	const std::string& reqCodePostal() const;

	const std::string& reqProvince() const;

	void asgNouvelleAdresse(int p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville,
			const std::string& p_codePostal, const std::string& p_province);

	std::string reqAdresseFormate() const;

	bool operator==(const Adresse& p_adresse) const;

private:
	int m_numeroCivic;
	std::string m_nomRue;
	std::string m_ville;
	std::string m_codePostal;
	std::string m_province;
	void verifieInvariant() const;

};

} /* namespace util */

#endif /* ADRESSE_H_ */
