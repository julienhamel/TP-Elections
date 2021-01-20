/**
 * \file CandidatTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Candidat
 * \date 2020-11-10
 * \author Maxime Chantal
 */

#include <gtest/gtest.h>
#include "Candidat.h"

using namespace util;
using namespace elections;

/**
 * \brief Test du constructeur avec paramètres de Candidat::Candidat(string, string, string, Date, Adresse, int)
 *
 *        cas valide :
 *          Création d'un candidat valide : ParametresValides
 *
 *        cas invalides :
 *        	parti politique invalide : PartiePolitiqueInvalide
 */
TEST(Candidat, ParametresValides)
{
	Candidat CandidatTest("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998),
	           	          Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"), LIBERAL);
	ASSERT_EQ(3, CandidatTest.reqPartiPolitique());
}

// parti politique invalide
TEST(Candidat, PartiePolitiqueInvalide)
{
	ASSERT_THROW(Candidat c1("046 454 236", "Maxime", "Chantal", Date(26, 07, 1998),
			     Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"), 5), PreconditionException);
}

/**
 * \class UnCandidat
 * \brief Fixture pour les tests sur un candidat
 */
class UnCandidat: public ::testing::Test
{
public:
	UnCandidat() :
		f_candidatTest("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998),
					   Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"), LIBERAL)
	{
	}
	;

	Candidat f_candidatTest;
};

/**
 * \brief Test de la méthode int Candidat::reqPartiPolitique()
 *        cas valide reqPartiPolitique: Création candidat valide connue et test du parti politique
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnCandidat, reqPartiPolitique)
{
	ASSERT_EQ(3, f_candidatTest.reqPartiPolitique());
}

/**
 * \brief  Test de la méthode string Candidat::reqPersonneFormate()
 *        cas valide CandidatFormate: Candidat connu dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnCandidat, CandidatFormate)
{
	std::ostringstream os;
	os << "Candidat" << std::endl
	   << "----------------------------------------------" << std::endl
	   << "NAS               : " << "046 454 237" << std::endl
	   << "Prenom            : " << "Maxime" << std::endl
	   << "Nom               : " << "Chantal" << std::endl
	   << "Date de naissance : " << Date(26, 07, 1998).reqDateFormatee() << std::endl
	   << "Adresse           : " << Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc").reqAdresseFormate()
	   	   	   	   	   	   	   	 << std::endl
	   << "Parti politique   : " << "Liberal" << std::endl;
	ASSERT_EQ(os.str(), f_candidatTest.reqPersonneFormate());
}

/**
 * \brief  Test de la méthode Personne* Candidat::clone() const
 *        cas valide CandidatCloneValide: clone identique au candidat originial
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnCandidat, CandidatCloneValide)
{
	Personne* candidatClone = f_candidatTest.clone();

	Candidat* candidatCloneTest = (Candidat*) candidatClone;

	ASSERT_EQ(f_candidatTest.reqPersonneFormate(), candidatCloneTest->reqPersonneFormate());
}
