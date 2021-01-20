#include "electeurinterface.h"
#include "Date.h"
#include <QMessageBox>
#include "validationFormat.h"

using namespace util;

ElecteurInterface::ElecteurInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

ElecteurInterface::~ElecteurInterface()
{

}

QString ElecteurInterface::reqNom() const
{
	return ui.lineEdit_nom->text();
}

QString ElecteurInterface::reqPrenom() const
{
	return ui.lineEdit_prenom->text();
}

util::Date ElecteurInterface::reqDateNaissance() const
{
	return m_dateNaissance;
}

QString ElecteurInterface::reqNas() const
{
	return ui.lineEdit_nas->text();
}

int ElecteurInterface::reqNumCivic() const
{
	return ui.lineEdit_nCivic->text().toInt();
}

QString ElecteurInterface::reqNomRue() const
{
	return ui.lineEdit_rue->text();
}

QString ElecteurInterface::reqVille() const
{
	return ui.lineEdit_ville->text();
}

QString ElecteurInterface::reqCodePostal() const
{
	return ui.lineEdit_codePostal->text();
}

QString ElecteurInterface::reqProvince() const
{
	return ui.lineEdit_province->text();
}

void ElecteurInterface::validerElecteur()
{
	if (ui.lineEdit_nom->text().isEmpty())
	{
		QString message("Le nom ne doit pas etre vide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_prenom->text().isEmpty())
	{
		QString message("Le prenom ne doit pas etre vide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	QDate qDate = QDate::currentDate();
	if(ui.dateEdit->date() >= qDate)
	{
		QString message("La date de naissance n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(!validerNas(ui.lineEdit_nas->text().toStdString()))
	{
		QString message("Le numero d'assurance social n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_nCivic->text().toInt() < 0 or ui.lineEdit_nCivic->text().isEmpty())
	{
		QString message("Le numero civic n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_rue->text().isEmpty())
	{
		QString message("Le nom de la rue n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_ville->text().isEmpty())
	{
		QString message("Le nom de la ville n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_codePostal->text().isEmpty())
	{
		QString message("Le code postal n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_province->text().isEmpty())
	{
		QString message("La province n'est pas valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	else
	{
	m_dateNaissance.asgDate(ui.dateEdit->date().day(), ui.dateEdit->date().month(),
	ui.dateEdit->date().year());
	accept();
	}
}
