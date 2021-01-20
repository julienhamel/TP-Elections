#ifndef CANDIDATINTERFACE_H
#define CANDIDATINTERFACE_H

#include <QtGui/QDialog>
#include <QComboBox>
#include "ui_candidatinterface.h"
#include "Date.h"

class candidatinterface : public QDialog
{
    Q_OBJECT

public:
    candidatinterface(QWidget *parent = 0);
    ~candidatinterface();

    int reqPartiPolitique() const;
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
	void validerCandidat();

private:
    Ui::candidatinterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // CANDIDATINTERFACE_H
