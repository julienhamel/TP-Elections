#include "mongui.h"
#include "electeurinterface.h"
#include "candidatinterface.h"
#include "desinscription.h"
#include "Adresse.h"
#include "PersonneException.h"
#include <QMessageBox>

using namespace elections;

monGui::monGui(QWidget *parent)
    : QMainWindow(parent), m_circonscription("Circonscription 0", Candidat("046 454 286", "inconnu", "inconnu", util::Date(12, 05, 1979),
				util::Adresse(1, "rue inconnue", "inconnue", "G1V 0A7", "QC"), 2))
{
	ui.setupUi(this);
}


monGui::~monGui()
{

}


void monGui::dialogElecteur()
{
	try
	{
		ElecteurInterface saisieElecteur(this);
		if(saisieElecteur.exec())
		{
			elections::Electeur electeur(saisieElecteur.reqNas().toStdString(), saisieElecteur.reqPrenom().toStdString(),
					saisieElecteur.reqNom().toStdString(), saisieElecteur.reqDateNaissance(),
					util::Adresse(saisieElecteur.reqNumCivic(), saisieElecteur.reqNomRue().toStdString(),
					saisieElecteur.reqVille().toStdString(), saisieElecteur.reqCodePostal().toStdString(),
					saisieElecteur.reqProvince().toStdString()));
			m_circonscription.inscrire(electeur);


			ui.affichage->setText(this->m_circonscription.reqCirconscriptionFormate().c_str());
		}
	}
	catch(PersonneDejaPresenteException& e)
	{
		QString message = (e.what());
		QMessageBox::information(this, "Erreur", message);
	}
}
void monGui::dialogCandidat()
{

	try
	{
		candidatinterface saisieCandidat(this);
		if(saisieCandidat.exec())
		{
			elections::Candidat candidat(saisieCandidat.reqNas().toStdString(), saisieCandidat.reqPrenom().toStdString(),
					saisieCandidat.reqNom().toStdString(), saisieCandidat.reqDateNaissance(),
					util::Adresse(saisieCandidat.reqNumCivic(), saisieCandidat.reqNomRue().toStdString(),
					saisieCandidat.reqVille().toStdString(), saisieCandidat.reqCodePostal().toStdString(),
					saisieCandidat.reqProvince().toStdString()), saisieCandidat.reqPartiPolitique() );
			m_circonscription.inscrire(candidat);

			ui.affichage->setText(this->m_circonscription.reqCirconscriptionFormate().c_str());
		}
	}
	catch(PersonneDejaPresenteException& e)
	{
		QString message = (e.what());
		QMessageBox::information(this, "Erreur", message);
	}
}

void monGui::dialogdesinscrire()
{
	try
	{
		desinscription saisieDesinscription(this);
		if (saisieDesinscription.exec())
		{
			m_circonscription.desinscrire(saisieDesinscription.reqNas().toStdString());

			ui.affichage->setText(this->m_circonscription.reqCirconscriptionFormate().c_str());
		}
	}
	catch(PersonneAbsenteException& e)
	{
		QString message = (e.what());
		QMessageBox::information(this, "Erreur", message);
	}
}
