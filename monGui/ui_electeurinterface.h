/********************************************************************************
** Form generated from reading UI file 'electeurinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELECTEURINTERFACE_H
#define UI_ELECTEURINTERFACE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ElecteurInterfaceClass
{
public:
    QLabel *label_rue;
    QPushButton *pushButton_valideElecteur;
    QLabel *label_nom;
    QLabel *label_dateNaissance;
    QLabel *label_nas;
    QLabel *label_nCivic;
    QLabel *label_titre;
    QLabel *label_ville;
    QLabel *label_prenom;
    QLabel *label_codePostal;
    QLabel *label_province;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_nas;
    QLineEdit *lineEdit_nCivic;
    QLineEdit *lineEdit_rue;
    QLineEdit *lineEdit_ville;
    QLineEdit *lineEdit_codePostal;
    QLineEdit *lineEdit_province;
    QPushButton *pushButton_Annuler;

    void setupUi(QDialog *ElecteurInterfaceClass)
    {
        if (ElecteurInterfaceClass->objectName().isEmpty())
            ElecteurInterfaceClass->setObjectName(QString::fromUtf8("ElecteurInterfaceClass"));
        ElecteurInterfaceClass->resize(400, 466);
        label_rue = new QLabel(ElecteurInterfaceClass);
        label_rue->setObjectName(QString::fromUtf8("label_rue"));
        label_rue->setGeometry(QRect(10, 240, 111, 31));
        pushButton_valideElecteur = new QPushButton(ElecteurInterfaceClass);
        pushButton_valideElecteur->setObjectName(QString::fromUtf8("pushButton_valideElecteur"));
        pushButton_valideElecteur->setGeometry(QRect(120, 410, 61, 27));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_valideElecteur->setFont(font);
        pushButton_valideElecteur->setAutoDefault(true);
        label_nom = new QLabel(ElecteurInterfaceClass);
        label_nom->setObjectName(QString::fromUtf8("label_nom"));
        label_nom->setGeometry(QRect(10, 40, 111, 31));
        label_dateNaissance = new QLabel(ElecteurInterfaceClass);
        label_dateNaissance->setObjectName(QString::fromUtf8("label_dateNaissance"));
        label_dateNaissance->setGeometry(QRect(10, 120, 111, 31));
        label_nas = new QLabel(ElecteurInterfaceClass);
        label_nas->setObjectName(QString::fromUtf8("label_nas"));
        label_nas->setGeometry(QRect(10, 160, 121, 31));
        label_nCivic = new QLabel(ElecteurInterfaceClass);
        label_nCivic->setObjectName(QString::fromUtf8("label_nCivic"));
        label_nCivic->setGeometry(QRect(10, 200, 111, 31));
        label_titre = new QLabel(ElecteurInterfaceClass);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));
        label_titre->setGeometry(QRect(70, 0, 271, 41));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_titre->setFont(font1);
        label_titre->setAlignment(Qt::AlignCenter);
        label_ville = new QLabel(ElecteurInterfaceClass);
        label_ville->setObjectName(QString::fromUtf8("label_ville"));
        label_ville->setGeometry(QRect(10, 280, 111, 31));
        label_prenom = new QLabel(ElecteurInterfaceClass);
        label_prenom->setObjectName(QString::fromUtf8("label_prenom"));
        label_prenom->setGeometry(QRect(10, 80, 111, 31));
        label_codePostal = new QLabel(ElecteurInterfaceClass);
        label_codePostal->setObjectName(QString::fromUtf8("label_codePostal"));
        label_codePostal->setGeometry(QRect(10, 320, 111, 31));
        label_province = new QLabel(ElecteurInterfaceClass);
        label_province->setObjectName(QString::fromUtf8("label_province"));
        label_province->setGeometry(QRect(10, 360, 111, 31));
        lineEdit_nom = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_nom->setObjectName(QString::fromUtf8("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(140, 40, 221, 31));
        lineEdit_prenom = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_prenom->setObjectName(QString::fromUtf8("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(140, 80, 221, 31));
        dateEdit = new QDateEdit(ElecteurInterfaceClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(140, 120, 121, 27));
        dateEdit->setMaximumDate(QDate(7937, 12, 31));
        dateEdit->setMinimumDate(QDate(1770, 1, 1));
        dateEdit->setCalendarPopup(true);
        lineEdit_nas = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_nas->setObjectName(QString::fromUtf8("lineEdit_nas"));
        lineEdit_nas->setGeometry(QRect(140, 160, 221, 31));
        lineEdit_nCivic = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_nCivic->setObjectName(QString::fromUtf8("lineEdit_nCivic"));
        lineEdit_nCivic->setGeometry(QRect(140, 200, 221, 31));
        lineEdit_rue = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_rue->setObjectName(QString::fromUtf8("lineEdit_rue"));
        lineEdit_rue->setGeometry(QRect(140, 240, 221, 31));
        lineEdit_ville = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_ville->setObjectName(QString::fromUtf8("lineEdit_ville"));
        lineEdit_ville->setGeometry(QRect(140, 280, 221, 31));
        lineEdit_codePostal = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_codePostal->setObjectName(QString::fromUtf8("lineEdit_codePostal"));
        lineEdit_codePostal->setGeometry(QRect(140, 320, 221, 31));
        lineEdit_province = new QLineEdit(ElecteurInterfaceClass);
        lineEdit_province->setObjectName(QString::fromUtf8("lineEdit_province"));
        lineEdit_province->setGeometry(QRect(140, 360, 221, 31));
        pushButton_Annuler = new QPushButton(ElecteurInterfaceClass);
        pushButton_Annuler->setObjectName(QString::fromUtf8("pushButton_Annuler"));
        pushButton_Annuler->setGeometry(QRect(200, 410, 80, 28));

        retranslateUi(ElecteurInterfaceClass);
        QObject::connect(pushButton_valideElecteur, SIGNAL(clicked()), ElecteurInterfaceClass, SLOT(validerElecteur()));
        QObject::connect(pushButton_Annuler, SIGNAL(clicked()), ElecteurInterfaceClass, SLOT(close()));

        QMetaObject::connectSlotsByName(ElecteurInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *ElecteurInterfaceClass)
    {
        ElecteurInterfaceClass->setWindowTitle(QApplication::translate("ElecteurInterfaceClass", "ElecteurInterface", 0, QApplication::UnicodeUTF8));
        label_rue->setText(QApplication::translate("ElecteurInterfaceClass", "Nom de rue :", 0, QApplication::UnicodeUTF8));
        pushButton_valideElecteur->setText(QApplication::translate("ElecteurInterfaceClass", "Ok", 0, QApplication::UnicodeUTF8));
        label_nom->setText(QApplication::translate("ElecteurInterfaceClass", "Nom :", 0, QApplication::UnicodeUTF8));
        label_dateNaissance->setText(QApplication::translate("ElecteurInterfaceClass", "Date de naissance :", 0, QApplication::UnicodeUTF8));
        label_nas->setText(QApplication::translate("ElecteurInterfaceClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Numero d'assurance</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">social :</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_nCivic->setText(QApplication::translate("ElecteurInterfaceClass", "Numero civic :", 0, QApplication::UnicodeUTF8));
        label_titre->setText(QApplication::translate("ElecteurInterfaceClass", "AJout d'un Electeur", 0, QApplication::UnicodeUTF8));
        label_ville->setText(QApplication::translate("ElecteurInterfaceClass", "Ville :", 0, QApplication::UnicodeUTF8));
        label_prenom->setText(QApplication::translate("ElecteurInterfaceClass", "Prenom :", 0, QApplication::UnicodeUTF8));
        label_codePostal->setText(QApplication::translate("ElecteurInterfaceClass", "Code postal :", 0, QApplication::UnicodeUTF8));
        label_province->setText(QApplication::translate("ElecteurInterfaceClass", "Province :", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("ElecteurInterfaceClass", "dd-MM-yyyy", 0, QApplication::UnicodeUTF8));
        pushButton_Annuler->setText(QApplication::translate("ElecteurInterfaceClass", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElecteurInterfaceClass: public Ui_ElecteurInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELECTEURINTERFACE_H
