#ifndef ELECTEURINTERFACE_H
#define ELECTEURINTERFACE_H

#include <QtGui/QDialog>
#include "ui_electeurinterface.h"
#include "Date.h"

class ElecteurInterface : public QDialog
{
    Q_OBJECT

public:
    ElecteurInterface(QWidget *parent = 0);
    ~ElecteurInterface();

    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDateNaissance() const;
    QString reqNas() const;
    int reqNumCivic() const;
    QString reqNomRue() const;
    QString reqVille() const;
    QString reqCodePostal() const;
    QString reqProvince() const;

private slots:
	void validerElecteur();

private:
    Ui::ElecteurInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // ELECTEURINTERFACE_H
