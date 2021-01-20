#ifndef MONGUI_H
#define MONGUI_H

#include <QtGui/QMainWindow>
#include "ui_mongui.h"
#include "Personne.h"
#include "Circonscription.h"
#include "Candidat.h"
#include "Electeur.h"
#include <vector>



class monGui : public QMainWindow
{
    Q_OBJECT

public:
    monGui(QWidget *parent = 0);
    ~monGui();



private slots:
	void dialogElecteur();
	void dialogCandidat();
	void dialogdesinscrire();


private:
    Ui::monGuiClass ui;
    elections::Circonscription m_circonscription;

};

#endif // MONGUI_H
