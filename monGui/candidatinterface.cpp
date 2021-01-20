#include "candidatinterface.h"
#include "Date.h"
#include <QMessageBox>
#include "validationFormat.h"

using namespace util;

candidatinterface::candidatinterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

candidatinterface::~candidatinterface()
{

}

int candidatinterface::reqPartiPolitique() const
{
	return ui.comboBox->currentIndex();


}

QString candidatinterface::reqNom() const
{
	return ui.lineEdit_nomC->text();
}

QString candidatinterface::reqPrenom() const
{
	return ui.lineEdit_prenomC->text();
}

util::Date candidatinterface::reqDateNaissance() const
{
	return m_dateNaissance;
}

QString candidatinterface::reqNas() const
{
	return ui.lineEdit_nasC->text();
}

int candidatinterface::reqNumCivic() const
{
	return ui.lineEdit_nCivicC->text().toInt();
}

QString candidatinterface::reqNomRue() const
{
	return ui.lineEdit_rueC->text();
}

QString candidatinterface::reqVille() const
{
	return ui.lineEdit_villeC->text();
}

QString candidatinterface::reqCodePostal() const
{
	return ui.lineEdit_codePostalC->text();
}

QString candidatinterface::reqProvince() const
{
	return ui.lineEdit_provinceC->text();


}
void candidatinterface::validerCandidat()
{
	if (ui.lineEdit_nomC->text().isEmpty())
	{
		QString message("Le nom ne doit pas etre vide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_prenomC->text().isEmpty())
	{
		QString message("Le prenom ne doit pas etre vide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	QDate qDate = QDate::currentDate();
	if(ui.dateEditC->date() >= qDate)
	{
		QString message("La date de naissance n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(!validerNas(ui.lineEdit_nasC->text().toStdString()))
	{
		QString message("Le numero d'assurance social n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_nCivicC->text().toInt() < 0 or ui.lineEdit_nCivicC->text().isEmpty())
	{
		QString message("Le numero civic n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_rueC->text().isEmpty())
	{
		QString message("Le nom de la rue n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_villeC->text().isEmpty())
	{
		QString message("Le nom de la ville n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_codePostalC->text().isEmpty())
	{
		QString message("Le code postal n'est pas valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.lineEdit_provinceC->text().isEmpty())
	{
		QString message("La province n'est pas valide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	else
	{
	m_dateNaissance.asgDate(ui.dateEditC->date().day(), ui.dateEditC->date().month(),
	ui.dateEditC->date().year());
	accept();
	}
}
