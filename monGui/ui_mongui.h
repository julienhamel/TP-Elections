/********************************************************************************
** Form generated from reading UI file 'mongui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONGUI_H
#define UI_MONGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monGuiClass
{
public:
    QAction *actionInscription_Candidat;
    QAction *actionInscription_lecteur;
    QAction *actionD_sinscription;
    QAction *Inscription_Candidat;
    QAction *Inscription_Electeur;
    QAction *Desinscription_Personne;
    QAction *Quitter;
    QAction *Inscription_Candidat69;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *monGuiClass)
    {
        if (monGuiClass->objectName().isEmpty())
            monGuiClass->setObjectName(QString::fromUtf8("monGuiClass"));
        monGuiClass->resize(359, 605);
        actionInscription_Candidat = new QAction(monGuiClass);
        actionInscription_Candidat->setObjectName(QString::fromUtf8("actionInscription_Candidat"));
        actionInscription_lecteur = new QAction(monGuiClass);
        actionInscription_lecteur->setObjectName(QString::fromUtf8("actionInscription_lecteur"));
        actionD_sinscription = new QAction(monGuiClass);
        actionD_sinscription->setObjectName(QString::fromUtf8("actionD_sinscription"));
        Inscription_Candidat = new QAction(monGuiClass);
        Inscription_Candidat->setObjectName(QString::fromUtf8("Inscription_Candidat"));
        Inscription_Electeur = new QAction(monGuiClass);
        Inscription_Electeur->setObjectName(QString::fromUtf8("Inscription_Electeur"));
        Desinscription_Personne = new QAction(monGuiClass);
        Desinscription_Personne->setObjectName(QString::fromUtf8("Desinscription_Personne"));
        Quitter = new QAction(monGuiClass);
        Quitter->setObjectName(QString::fromUtf8("Quitter"));
        Inscription_Candidat69 = new QAction(monGuiClass);
        Inscription_Candidat69->setObjectName(QString::fromUtf8("Inscription_Candidat69"));
        centralwidget = new QWidget(monGuiClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setEnabled(true);
        affichage->setGeometry(QRect(0, 0, 361, 581));
        affichage->setAcceptDrops(true);
        affichage->setReadOnly(true);
        monGuiClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(monGuiClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        monGuiClass->setStatusBar(statusbar);
        menuBar = new QMenuBar(monGuiClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 359, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        monGuiClass->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(Inscription_Candidat69);
        menuMenu->addAction(Inscription_Electeur);
        menuMenu->addAction(Desinscription_Personne);
        menuMenu->addSeparator();
        menuMenu->addAction(Quitter);

        retranslateUi(monGuiClass);
        QObject::connect(Quitter, SIGNAL(triggered()), monGuiClass, SLOT(close()));
        QObject::connect(Inscription_Electeur, SIGNAL(triggered()), monGuiClass, SLOT(dialogElecteur()));
        QObject::connect(Inscription_Candidat69, SIGNAL(triggered()), monGuiClass, SLOT(dialogCandidat()));
        QObject::connect(Desinscription_Personne, SIGNAL(triggered()), monGuiClass, SLOT(dialogdesinscrire()));

        QMetaObject::connectSlotsByName(monGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *monGuiClass)
    {
        monGuiClass->setWindowTitle(QApplication::translate("monGuiClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionInscription_Candidat->setText(QApplication::translate("monGuiClass", "Inscription Candidat", 0, QApplication::UnicodeUTF8));
        actionInscription_lecteur->setText(QApplication::translate("monGuiClass", "Inscription \303\211lecteur", 0, QApplication::UnicodeUTF8));
        actionD_sinscription->setText(QApplication::translate("monGuiClass", "D\303\251sinscription", 0, QApplication::UnicodeUTF8));
        Inscription_Candidat->setText(QApplication::translate("monGuiClass", "Inscription Candidat", 0, QApplication::UnicodeUTF8));
        Inscription_Electeur->setText(QApplication::translate("monGuiClass", "Inscription Electeur", 0, QApplication::UnicodeUTF8));
        Desinscription_Personne->setText(QApplication::translate("monGuiClass", "Desinscription Personne", 0, QApplication::UnicodeUTF8));
        Quitter->setText(QApplication::translate("monGuiClass", "Quitter", 0, QApplication::UnicodeUTF8));
        Inscription_Candidat69->setText(QApplication::translate("monGuiClass", "Inscription Candidat", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("monGuiClass", "Operations", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class monGuiClass: public Ui_monGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONGUI_H
