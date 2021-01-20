/**
 * \file AdresseTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Adresse
 * \date 2020-11-04
 * \author Maxime Chantal
 */

#include <gtest/gtest.h>
#include "Adresse.h"

using namespace util;

/**
 * \brief Test du constructeur avec paramètres de Adresse::Adresse(int, string, string, string, string)
 *
 *        cas valide :
 *          Création d'une adresse valide : ParametresValides
 *
 *        cas invalides :
 *        	numéro civique invalide : NumeroCiviqueInvalide,
 *        	nom rue invalide : NomRueInvalide,
 *        	ville invalide : VilleInvalide,
 *        	code postal invalide : CodePostalInvalide,
 *        	province invalide : ProvinceInvalide
 */
TEST(Adresse, ParametresValides)
{
	Adresse AdresseTest(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc");
	ASSERT_EQ(5465, AdresseTest.reqNumeroCivic());
	ASSERT_EQ("5e avenue Ouest", AdresseTest.reqNomRue());
	ASSERT_EQ("Québec", AdresseTest.reqVille());
	ASSERT_EQ("G1H 7E1", AdresseTest.reqCodePostal());
	ASSERT_EQ("Qc", AdresseTest.reqProvince());
}

// numéro civique invalide
TEST(Adresse, NumeroCiviqueInvalide)
{
	ASSERT_THROW(Adresse a1(-5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"), PreconditionException);
}

// nom rue invalide
TEST(Adresse, NomRueInvalide)
{
	ASSERT_THROW(Adresse a2(5465, "", "Québec", "G1H 7E1", "Qc"), PreconditionException);
}

// ville invalide
TEST(Adresse, VilleInvalide)
{
	ASSERT_THROW(Adresse a3(5465, "5e avenue Ouest", "", "G1H 7E1", "Qc"), PreconditionException);
}

// code postal invalide
TEST(Adresse, CodePostalInvalide)
{
	ASSERT_THROW(Adresse a4(5465, "5e avenue Ouest", "Québec", "", "Qc"), PreconditionException);
}

// province invalide
TEST(Adresse, ProvinceInvalide)
{
	ASSERT_THROW(Adresse a5(5465, "5e avenue Ouest", "Québec", "G1H 7E1", ""), PreconditionException);
}

/**
 * \class AdresseComplete
 * \brief Fixture pour les tests sur une adresse
 */

class AdresseComplete: public ::testing::Test // Une adresse (5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc")
{
public:
	AdresseComplete() :
			f_adresseTest(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc")
	{
	}
	;

	Adresse f_adresseTest;
};

/**
 * \brief Test de la méthode int Adresse::reqNumeroCivic()
 *        cas valide reqNumeroCivic: Création adresse valide connue et test du numéro civique
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseComplete, reqNumeroCivic)
{
	ASSERT_EQ(5465, f_adresseTest.reqNumeroCivic());
}

/**
 * \brief Test de la méthode string& Adresse::reqNomRue()
 *        cas valide reqNomRue: Création adresse valide connue et test du nom de rue
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseComplete, reqNomRue)
{
	ASSERT_EQ("5e avenue Ouest", f_adresseTest.reqNomRue());
}

/**
 * \brief Test de la méthode string& Adresse::reqVille()
 *        cas valide reqVille: Création adresse valide connue et test de la ville
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseComplete, reqVille)
{
	ASSERT_EQ("Québec", f_adresseTest.reqVille());
}

/**
 * \brief Test de la méthode string& Adresse::reqCodePostal()
 *        cas valide reqCodePostal: Création adresse valide connue et test du code postal
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseComplete, reqCodePostal)
{
	ASSERT_EQ("G1H 7E1", f_adresseTest.reqCodePostal());
}

/**
 * \brief Test de la méthode string& Adresse::reqProvince()
 *        cas valide reqProvince: Création adresse valide connue et test de la province
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseComplete, reqProvince)
{
	ASSERT_EQ("Qc", f_adresseTest.reqProvince());
}

/**
 * \brief Test de la méthode void Adresse::asgNouvelleAdresse()
 *     	cas valide
 *     		asgNouvelleAdresseValide: Assigner une adresse avec des entrées valides
 *   	cas invalides
 *        	numéro civique invalide : AsgNumeroCiviqueInvalide,
 *        	nom rue invalide :  AsgNomRueInvalide,
 *        	ville invalide :  AsgVilleInvalide,
 *        	code postal invalide :  AsgCodePostalInvalide,
 *        	province invalide :  AsgProvinceInvalide
 */
TEST_F(AdresseComplete, asgNouvelleAdresseValide)
{
	f_adresseTest.asgNouvelleAdresse(430, "place Gauvreau", "Montréal", "G1G 2P8", "QC");
	ASSERT_EQ(430, f_adresseTest.reqNumeroCivic());
	ASSERT_EQ("place Gauvreau", f_adresseTest.reqNomRue());
	ASSERT_EQ("Montréal", f_adresseTest.reqVille());
	ASSERT_EQ("G1G 2P8", f_adresseTest.reqCodePostal());
	ASSERT_EQ("QC", f_adresseTest.reqProvince());
}

//cas invalides
// numéro civique invalide
TEST_F(AdresseComplete, AsgNumeroCiviqueInvalide)
{
	ASSERT_THROW(f_adresseTest.asgNouvelleAdresse(-430, "place Gauvreau", "Montréal", "G1G 2P8", "QC"),
				 PreconditionException);
}

// nom rue invalide
TEST_F(AdresseComplete, AsgNomRueInvalide)
{
	ASSERT_THROW(f_adresseTest.asgNouvelleAdresse(430, "", "Montréal", "G1G 2P8", "QC"), PreconditionException);
}

// ville invalide
TEST_F(AdresseComplete, AsgVilleInvalide)
{
	ASSERT_THROW(f_adresseTest.asgNouvelleAdresse(430, "place Gauvreau", "", "G1G 2P8", "QC"), PreconditionException);
}

// code postal invalide
TEST_F(AdresseComplete, AsgCodePostalInvalide)
{
	ASSERT_THROW(f_adresseTest.asgNouvelleAdresse(430, "place Gauvreau", "Montréal", "", "QC"), PreconditionException);
}

// province invalide
TEST_F(AdresseComplete, AsgProvinceInvalide)
{
	ASSERT_THROW(f_adresseTest.asgNouvelleAdresse(430, "place Gauvreau", "Montréal", "G1G 2P8", ""),
				 PreconditionException);
}

/**
 * \brief  Test de la méthode string Adresse::reqAdresseFormate()
 *        cas valide AdresseFormate: Adresse connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(AdresseComplete, AdresseFormate)
{
	ASSERT_EQ("5465, 5e avenue Ouest, Québec, G1H 7E1, Qc", f_adresseTest.reqAdresseFormate());
}

/**
 * \class DeuxAdresses
 * \brief Fixture pour les tests comparaisons de deux adresses
 */
class DeuxAdresses: public ::testing::Test
{
public:
	DeuxAdresses() :
			f_adresse1(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"),
			f_adresse2(430, "place Gauvreau", "Québec", "G1G 2P8", "Qc")
	{
	}
	;

	Adresse f_adresse1;
	Adresse f_adresse2;
};
/**
 * \brief  Test de la méthode bool Adresse::operator== (const Adresse& obj)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Adresse indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Adresses différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F(DeuxAdresses, OperatorEgalEgalVrai)
{
	ASSERT_EQ(f_adresse1, f_adresse1);
}

TEST_F(DeuxAdresses, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(f_adresse1 == f_adresse2);
}
