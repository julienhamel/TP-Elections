/**
 * \file ElecteurTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Electeur
 * \date 2020-11-11
 * \author Maxime Chantal
 */

#include <gtest/gtest.h>
#include "Electeur.cpp"

using namespace util;
using namespace elections;

// Le constructeur n'est pas testé ici puisqu'on construit essentiellement un objet Personne.
// Seule la méthode Electeur::reqPersonneFormate() est augmentée dans cette classe.

/**
 * \class UnElecteur
 * \brief Fixture pour les tests sur un electeur
 */
class UnElecteur: public ::testing::Test
{
public:
	UnElecteur() :
		f_electeurTest("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998),
				   Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"))
	{
	}
	;

	Electeur f_electeurTest;
};

/**
 * \brief  Test de la méthode string Electeur::reqPersonneFormate()
 *        cas valide ElecteurFormate: Electeur connu dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnElecteur, ElecteurFormate)
{
	std::ostringstream os;
	os << "Electeur" << std::endl
	   << "----------------------------------------------" << std::endl
	   << "NAS               : " << "046 454 237" << std::endl
	   << "Prenom            : " << "Maxime" << std::endl
	   << "Nom               : " << "Chantal" << std::endl
	   << "Date de naissance : " << Date(26, 07, 1998).reqDateFormatee() << std::endl
	   << "Adresse           : " << Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc").reqAdresseFormate()
	   	   	   	   	   	   	   	 << std::endl;
	ASSERT_EQ(os.str(), f_electeurTest.reqPersonneFormate());
}

/**
 * \brief  Test de la méthode Personne* Electeur::clone() const
 *        cas valide ElecteurCloneValide: clone identique à l'électeur originial
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnElecteur, ElecteurCloneValide)
{
	Personne* electeurClone = f_electeurTest.clone();

	Electeur* electeurCloneTest = (Electeur*) electeurClone;

	ASSERT_EQ(f_electeurTest.reqPersonneFormate(), electeurCloneTest->reqPersonneFormate());
}
