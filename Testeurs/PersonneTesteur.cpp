/**
 * \file PersonneTesteur.cpp
 * \brief Fichier de tests unitaires pour la classe Adresse
 * \date 2020-11-04
 * \author Maxime Chantal
 */

#include<gtest/gtest.h>
#include "Personne.h"
#include <sstream>

using namespace util;
using namespace elections;

/**
 * \class PersonneTest
 * \brief classe de test permettant de tester la classe abstraite Personne
 */
class PersonneTest: public Personne
{
public:
	PersonneTest(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom,
		         const Date& p_dateNaissance, const Adresse& p_adresse) :
	    Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
{
}
	virtual std::string reqPersonneFormate() const
	{
		return Personne::reqPersonneFormate();
	}

	virtual Personne* clone() const
	{
		return new PersonneTest(*this);
	}

};

/**
 * \brief Test du constructeur avec paramètres de Personne::Personne(string, string, string, Date, Adresse)
 *
 *        cas valide :
 *          Création d'une personne valide : ParametresValides
 *
 *        cas invalides :
 *        	nas invalide : NasInvalide,
 *        	prenom  invalide : PrenomInvalide,
 *        	nom invalide : NomInvalide.
 */
TEST(Personne, ParametresValides)
{
	PersonneTest PersonneDeTest("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998),
						        Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"));
	ASSERT_EQ("046 454 237", PersonneDeTest.reqNas());
	ASSERT_EQ("Maxime", PersonneDeTest.reqPrenom());
	ASSERT_EQ("Chantal", PersonneDeTest.reqNom());
	ASSERT_EQ(Date(26, 07, 1998), PersonneDeTest.reqDateNaissance());
	ASSERT_EQ(Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"), PersonneDeTest.reqAdresse());
}

// numéro nas invalide
TEST(Personne, NasInvalide)
{
	ASSERT_THROW(PersonneTest p1("046 454 236", "Maxime", "Chantal", Date(26, 07, 1998),
			     Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc")), PreconditionException);
}

// numéro prénom invalide
TEST(Personne, PrenomInvalide)
{
	ASSERT_THROW(PersonneTest p2("046 454 237", "", "Chantal", Date(26, 07, 1998),
			     Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc")), PreconditionException);
}

// numéro nom invalide
TEST(Personne, NomInvalide)
{
	ASSERT_THROW(PersonneTest p3("046 454 237", "Maxime", "", Date(26, 07, 1998),
			     Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc")), PreconditionException);
}

/**
 * \class UnePersonne
 * \brief Fixture pour les tests sur une personne
 */
class UnePersonne: public ::testing::Test
{
public:
	UnePersonne() :
		f_personneTest("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998),
					   Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"))
	{
	}
	;

	PersonneTest f_personneTest;
};

/**
 * \brief Test de la méthode string& Personne::reqNas()
 *        cas valide reqNas: Création personne valide connue et test du nas
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnePersonne, reqNas)
{
	ASSERT_EQ("046 454 237", f_personneTest.reqNas());
}

/**
 * \brief Test de la méthode string& Personne::reqPrenom()
 *        cas valide reqPrenom: Création personne valide connue et test du prenom
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnePersonne, reqPrenom)
{
	ASSERT_EQ("Maxime", f_personneTest.reqPrenom());
}

/**
 * \brief Test de la méthode string& Personne::reqNom()
 *        cas valide reqNom: Création personne valide connue et test du Nom
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnePersonne, reqNom)
{
	ASSERT_EQ("Chantal", f_personneTest.reqNom());
}

/**
 * \brief Test de la méthode Date& Personne::reqDateNaissance()
 *        cas valide reqDateNaissance: Création personne valide connue et test de la date de naissance
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnePersonne, reqDateNaissance)
{
	ASSERT_EQ(Date(26, 07, 1998), f_personneTest.reqDateNaissance());
}

/**
 * \brief Test de la méthode Adresse& Personne::reqAdresse()
 *        cas valide reqAdresse: Création personne valide connue et test de l'adresse
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnePersonne, reqAdresse)
{
	ASSERT_EQ(Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"), f_personneTest.reqAdresse());
}

/**
 * \brief  Test de la méthode string Personne::reqPersonneFormate()
 *        cas valide PersonneFormate: Personne connue dont on connaît le format.
 *        cas invalide Aucun d'identifié
 */
TEST_F(UnePersonne, PersonneFormate)
{
	std::ostringstream os;
	os << "NAS               : " << "046 454 237" << std::endl
	   << "Prenom            : " << "Maxime" << std::endl
	   << "Nom               : " << "Chantal" << std::endl
	   << "Date de naissance : " << Date(26, 07, 1998).reqDateFormatee() << std::endl
	   << "Adresse           : " << Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc").reqAdresseFormate()
	   	   	   	   	   	   	   	 << std::endl;
	ASSERT_EQ(os.str(), f_personneTest.reqPersonneFormate());
}

/**
 * \class DeuxPersonnes
 * \brief Fixture pour les tests comparaisons de deux adresses
 */
class DeuxPersonnes: public ::testing::Test
{
public:
	DeuxPersonnes() :
			f_personne1("046 454 237", "Maxime", "Chantal", Date(26, 07, 1998),
					   Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc")),
			f_personne2("640 454 237", "Frédérique", "Brousseau", Date(10, 07, 1999),
					   Adresse(5465, "5e avenue Ouest", "Québec", "G1H 7E1", "Qc"))
	{
	}
	;

	PersonneTest f_personne1;
	PersonneTest f_personne2;
};
/**
 * \brief  Test de la méthode bool Adresse::operator== (const Adresse& obj)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Adresse indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Adresses différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F(DeuxPersonnes, OperatorEgalEgalVrai)
{
	ASSERT_EQ(f_personne1, f_personne1);
}

TEST_F(DeuxPersonnes, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(f_personne1 == f_personne2);
}
