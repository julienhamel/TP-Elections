#include "desinscription.h"
#include "validationFormat.h"
#include <QMessageBox>

using namespace util;

desinscription::desinscription(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

desinscription::~desinscription()
{

}

QString desinscription::reqNas() const
{
	return ui.lineEdit_Nas->text();
}

void desinscription::Destruction()
{
	if(!validerNas(ui.lineEdit_Nas->text().toStdString()))
	{
		QString message("Veuillez entrer un numero d'assurance social valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	else
	{
	accept();
	}
}
