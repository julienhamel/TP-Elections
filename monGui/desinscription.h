#ifndef DESINSCRIPTION_H
#define DESINSCRIPTION_H

#include <QtGui/QDialog>
#include "ui_desinscription.h"

class desinscription : public QDialog
{
    Q_OBJECT

public:
    desinscription(QWidget *parent = 0);
    ~desinscription();

   QString reqNas() const;

private slots:
	void Destruction();
private:
    Ui::desinscriptionClass ui;
};

#endif // DESINSCRIPTION_H
