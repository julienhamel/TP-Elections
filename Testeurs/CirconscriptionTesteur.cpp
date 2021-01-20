/**
 * \file CirconscriptionTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Circonscription
 * \date 2020-11-11
 * \author Maxime Chantal
 */

#include <gtest/gtest.h>
#include "Circonscription.h"
#include "Electeur.h"
#include "PersonneException.h"

using namespace util;
using namespace elections;

/**
 * \brief Test du constructeur avec paramètres de Circonscription::Circonscription(string, Candidat)
 *
 *        cas valide :
 *          Création d'une circonscription valide : ParametresValides
 *
 *        cas invalides :
 *        	nom circonscription invalide : CirconscriptionInvalide,
 */
TEST(Circonscription, ParametresValides)
{
	Candidat c1("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998), Adresse(5465, "5e avenue Ouest",
			"Québec", "G1H 7E1", "Qc"), LIBERAL);
	Circonscription CirconscriptionTest("circonscription n° 1", c1);
	ASSERT_EQ("circonscription n° 1", CirconscriptionTest.reqNomCirconscription());
	ASSERT_EQ(c1, CirconscriptionTest.reqDeputeElu());
}

// nom circonscription invalide
TEST(Circonscription, CirconscriptionInvalide)
{
	Candidat c1("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998), Adresse(5465, "5e avenue Ouest",
				"Québec", "G1H 7E1", "Qc"), LIBERAL);
	ASSERT_THROW(Circonscription CirconscriptionTest2("", c1), PreconditionException);
}

/**
 * \class UneCirconscription
 * \brief Fixture pour les tests sur une circonscription
 */

class UneCirconscription: public ::testing::Test
{
public:
	UneCirconscription() :
			f_CirconscriptionTest("circonscription n° 1", Candidat("046 454 286", "Jean", "Louis",
					util::Date(12, 05, 1979), util::Adresse(235, "Rue de l'Université", "Québec", "G1V 0A7", "QC"),
					BLOC_QUEBECOIS))
	{

	}
	;

	Circonscription f_CirconscriptionTest;
};

/**
 * \brief Test de la méthode string& Circonscription::reqNomCirconscription()
 *        cas valide reqNomCirconscription: Création circonscription valide connue et test du nom de circonscription
 *        cas invalide Aucun d'identifié
 */
TEST_F(UneCirconscription, reqNomCirconscription)
{
	ASSERT_EQ("circonscription n° 1", f_CirconscriptionTest.reqNomCirconscription());
}

/**
 * \brief Test de la méthode Candidat& Circonscription::reqDeputeElu()
 *        cas valide reqDeputeElu: Création circonscription valide connue et test du depute elu
 *        cas invalide Aucun d'identifié
 */
TEST_F(UneCirconscription, reqDeputeElu)
{
	ASSERT_EQ(Candidat("046 454 286", "Jean", "Louis", util::Date(12, 05, 1979), util::Adresse(235, "Rue de l'Université",
			"Québec", "G1V 0A7", "QC"), BLOC_QUEBECOIS), f_CirconscriptionTest.reqDeputeElu());
}

/**
 * \brief  Test de la méthode std::string Adresse::reqCirconscriptionFormate()
 *        cas valide CirconscriptionFormate: Circonscription connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(UneCirconscription, reqCirconscriptionFormate)
{
	std::ostringstream os;
	os << "circonscription : " << "circonscription n° 1" << std::endl
	   << "Depute sortant :" << std::endl
	   << "Candidat" << std::endl
	   << "----------------------------------------------" << std::endl
	   << "NAS               : " << "046 454 286" << std::endl
	   << "Prenom            : " << "Jean" << std::endl
	   << "Nom               : " << "Louis" << std::endl
	   << "Date de naissance : " << Date(12, 05, 1979).reqDateFormatee() << std::endl
	   << "Adresse           : " << Adresse(235, "Rue de l'Université", "Québec", "G1V 0A7", "QC").reqAdresseFormate()
	   	   	   	   	   	   	   	 << std::endl
	   << "Parti politique   : " << "Bloc quebecois" << std::endl
	   << std::endl << "Liste des inscrits:" << std::endl;
	ASSERT_EQ(os.str(), f_CirconscriptionTest.reqCirconscriptionFormate());
}

/**
 * \brief Test de la méthode void inscrire(const Personne& p_nouvelInscrit)
 *        cas valide inscire : Circonscription connue dont on connaît le format, vérification de l'inscription
 *        cas invalide inscrireInvalide : Inscription d'une personne déjà présente
 */
TEST_F(UneCirconscription, inscire)
{
	Electeur e("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998), Adresse(5465, "5e avenue Ouest",
				"Québec", "G1H 7E1", "Qc"));

	f_CirconscriptionTest.inscrire(e);

	std::ostringstream os;
	os << "circonscription : " << "circonscription n° 1" << std::endl
	   << "Depute sortant :" << std::endl
	   << "Candidat" << std::endl
	   << "----------------------------------------------" << std::endl
	   << "NAS               : " << "046 454 286" << std::endl
	   << "Prenom            : " << "Jean" << std::endl
	   << "Nom               : " << "Louis" << std::endl
	   << "Date de naissance : " << Date(12, 05, 1979).reqDateFormatee() << std::endl
	   << "Adresse           : " << Adresse(235, "Rue de l'Université", "Québec", "G1V 0A7", "QC").reqAdresseFormate()
	   	   	   	   	   	   	   	 << std::endl
	   << "Parti politique   : " << "Bloc quebecois" << std::endl
	   << std::endl << "Liste des inscrits:" << std::endl
	   << "Electeur" << std::endl
	   << "----------------------------------------------" << std::endl
	   << "NAS               : " << "046 454 237" << std::endl
	   << "Prenom            : " << "Maxime" << std::endl
	   << "Nom               : " << "Chantal" << std::endl
	   << "Date de naissance : " << Date(26, 07, 1998).reqDateFormatee() << std::endl
	   << "Adresse           : " << Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc").reqAdresseFormate()
	   	   	   	   	   	   	   	 << std::endl << std::endl;
	ASSERT_EQ(os.str(), f_CirconscriptionTest.reqCirconscriptionFormate());
}

// Personne déjà inscrite
TEST_F(UneCirconscription, inscireInvalide)
{
	Electeur e1("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998), Adresse(5465, "5e avenue Ouest",
				"Québec", "G1H 7E1", "Qc"));

	f_CirconscriptionTest.inscrire(e1);

	Electeur e2("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998), Adresse(5465, "5e avenue Ouest",
					"Québec", "G1H 7E1", "Qc"));

	ASSERT_THROW(f_CirconscriptionTest.inscrire(e2), PersonneDejaPresenteException);
}

/**
 * \brief Test du constructeur copie de la classe Circonscription
 *        cas valide ConstructeurCopieValide: Création circonscription valide connue et test du constructeur copie
 *        cas invalide Aucun d'identifié
 */
TEST_F(UneCirconscription, ConstructeurCopieValide)
{
	Circonscription f_CirconscriptionTest2(f_CirconscriptionTest);
	ASSERT_EQ(f_CirconscriptionTest.reqNomCirconscription(), f_CirconscriptionTest2.reqNomCirconscription());
	ASSERT_EQ(f_CirconscriptionTest.reqDeputeElu(), f_CirconscriptionTest2.reqDeputeElu());
	ASSERT_EQ(f_CirconscriptionTest.reqCirconscriptionFormate(), f_CirconscriptionTest2.reqCirconscriptionFormate());
}

/**
 * \brief Test de la méthode Circonscription& Circonscription::operator= (const Circonscription& p_circonscription)
 *        cas valide OperateurAssignationValide: Création circonscription valide connue et test de la méthode d'assignation
 *        cas invalide Aucun d'identifié
 */
TEST_F(UneCirconscription, OperateurAssignationValide)
{
	Circonscription f_CirconscriptionTest2 = f_CirconscriptionTest;
	ASSERT_EQ(f_CirconscriptionTest.reqNomCirconscription(), f_CirconscriptionTest2.reqNomCirconscription());
	ASSERT_EQ(f_CirconscriptionTest.reqDeputeElu(), f_CirconscriptionTest2.reqDeputeElu());
	ASSERT_EQ(f_CirconscriptionTest.reqCirconscriptionFormate(), f_CirconscriptionTest2.reqCirconscriptionFormate());
}

/**
 * \brief Test de la méthode void Circonscription::desinscrire(const std::string& p_nas)
 *        cas valide PersonneDesinscrite: Test la méthode desinscrire
 *        cas invalide PersonneDesinscriteInvalide : On essaye de desincrire une personne qui n'est pas dans la liste
 */
TEST_F(UneCirconscription, PersonneDesinscrite)
{
	Electeur e("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998), Adresse(5465, "5e avenue Ouest",
					"Québec", "G1H 7E1", "Qc"));

	f_CirconscriptionTest.inscrire(e);

	f_CirconscriptionTest.desinscrire("046 454 237");

	std::ostringstream os;
		os << "circonscription : " << "circonscription n° 1" << std::endl
		   << "Depute sortant :" << std::endl
		   << "Candidat" << std::endl
		   << "----------------------------------------------" << std::endl
		   << "NAS               : " << "046 454 286" << std::endl
		   << "Prenom            : " << "Jean" << std::endl
		   << "Nom               : " << "Louis" << std::endl
		   << "Date de naissance : " << Date(12, 05, 1979).reqDateFormatee() << std::endl
		   << "Adresse           : " << Adresse(235, "Rue de l'Université", "Québec", "G1V 0A7", "QC").reqAdresseFormate()
		   	   	   	   	   	   	   	 << std::endl
		   << "Parti politique   : " << "Bloc quebecois" << std::endl
		   << std::endl << "Liste des inscrits:" << std::endl;

	ASSERT_EQ(os.str(), f_CirconscriptionTest.reqCirconscriptionFormate());
}

// Desinscription d'une personne pas dans la liste
TEST_F(UneCirconscription, PersonneDesinscriteInvalide)
{
	ASSERT_THROW(f_CirconscriptionTest.desinscrire("046 454 237"), PersonneAbsenteException);
}
