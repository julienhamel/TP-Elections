/********************************************************************************
** Form generated from reading UI file 'candidatinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANDIDATINTERFACE_H
#define UI_CANDIDATINTERFACE_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_candidatinterfaceClass
{
public:
    QLabel *label_nomC;
    QLineEdit *lineEdit_nomC;
    QLabel *label_2;
    QLabel *label_prenimC;
    QLineEdit *lineEdit_prenomC;
    QLabel *label_dateNaissance;
    QDateEdit *dateEditC;
    QLabel *label_nas;
    QLineEdit *lineEdit_nasC;
    QLabel *label_nCivic;
    QLabel *label_rue;
    QLabel *label_ville;
    QLabel *label_codePostal;
    QLabel *label_province;
    QLineEdit *lineEdit_nCivicC;
    QLineEdit *lineEdit_rueC;
    QLineEdit *lineEdit_villeC;
    QLineEdit *lineEdit_codePostalC;
    QLineEdit *lineEdit_provinceC;
    QPushButton *pushButton_valideCandidat;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton_Annuler;

    void setupUi(QDialog *candidatinterfaceClass)
    {
        if (candidatinterfaceClass->objectName().isEmpty())
            candidatinterfaceClass->setObjectName(QString::fromUtf8("candidatinterfaceClass"));
        candidatinterfaceClass->resize(400, 513);
        label_nomC = new QLabel(candidatinterfaceClass);
        label_nomC->setObjectName(QString::fromUtf8("label_nomC"));
        label_nomC->setGeometry(QRect(10, 80, 121, 17));
        lineEdit_nomC = new QLineEdit(candidatinterfaceClass);
        lineEdit_nomC->setObjectName(QString::fromUtf8("lineEdit_nomC"));
        lineEdit_nomC->setGeometry(QRect(140, 80, 211, 27));
        label_2 = new QLabel(candidatinterfaceClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 10, 241, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_prenimC = new QLabel(candidatinterfaceClass);
        label_prenimC->setObjectName(QString::fromUtf8("label_prenimC"));
        label_prenimC->setGeometry(QRect(10, 120, 121, 17));
        lineEdit_prenomC = new QLineEdit(candidatinterfaceClass);
        lineEdit_prenomC->setObjectName(QString::fromUtf8("lineEdit_prenomC"));
        lineEdit_prenomC->setGeometry(QRect(140, 120, 211, 27));
        label_dateNaissance = new QLabel(candidatinterfaceClass);
        label_dateNaissance->setObjectName(QString::fromUtf8("label_dateNaissance"));
        label_dateNaissance->setGeometry(QRect(10, 160, 111, 31));
        dateEditC = new QDateEdit(candidatinterfaceClass);
        dateEditC->setObjectName(QString::fromUtf8("dateEditC"));
        dateEditC->setGeometry(QRect(140, 160, 121, 27));
        dateEditC->setMaximumDate(QDate(7937, 12, 31));
        dateEditC->setMinimumDate(QDate(1770, 1, 1));
        dateEditC->setCalendarPopup(true);
        label_nas = new QLabel(candidatinterfaceClass);
        label_nas->setObjectName(QString::fromUtf8("label_nas"));
        label_nas->setGeometry(QRect(10, 200, 121, 31));
        lineEdit_nasC = new QLineEdit(candidatinterfaceClass);
        lineEdit_nasC->setObjectName(QString::fromUtf8("lineEdit_nasC"));
        lineEdit_nasC->setGeometry(QRect(140, 200, 221, 31));
        label_nCivic = new QLabel(candidatinterfaceClass);
        label_nCivic->setObjectName(QString::fromUtf8("label_nCivic"));
        label_nCivic->setGeometry(QRect(10, 240, 111, 31));
        label_rue = new QLabel(candidatinterfaceClass);
        label_rue->setObjectName(QString::fromUtf8("label_rue"));
        label_rue->setGeometry(QRect(10, 280, 111, 31));
        label_ville = new QLabel(candidatinterfaceClass);
        label_ville->setObjectName(QString::fromUtf8("label_ville"));
        label_ville->setGeometry(QRect(10, 320, 111, 31));
        label_codePostal = new QLabel(candidatinterfaceClass);
        label_codePostal->setObjectName(QString::fromUtf8("label_codePostal"));
        label_codePostal->setGeometry(QRect(10, 360, 111, 31));
        label_province = new QLabel(candidatinterfaceClass);
        label_province->setObjectName(QString::fromUtf8("label_province"));
        label_province->setGeometry(QRect(10, 390, 111, 31));
        lineEdit_nCivicC = new QLineEdit(candidatinterfaceClass);
        lineEdit_nCivicC->setObjectName(QString::fromUtf8("lineEdit_nCivicC"));
        lineEdit_nCivicC->setGeometry(QRect(140, 240, 221, 31));
        lineEdit_nCivicC->setInputMethodHints(Qt::ImhNone);
        lineEdit_rueC = new QLineEdit(candidatinterfaceClass);
        lineEdit_rueC->setObjectName(QString::fromUtf8("lineEdit_rueC"));
        lineEdit_rueC->setGeometry(QRect(140, 280, 221, 31));
        lineEdit_villeC = new QLineEdit(candidatinterfaceClass);
        lineEdit_villeC->setObjectName(QString::fromUtf8("lineEdit_villeC"));
        lineEdit_villeC->setGeometry(QRect(140, 320, 221, 31));
        lineEdit_codePostalC = new QLineEdit(candidatinterfaceClass);
        lineEdit_codePostalC->setObjectName(QString::fromUtf8("lineEdit_codePostalC"));
        lineEdit_codePostalC->setGeometry(QRect(140, 360, 221, 31));
        lineEdit_provinceC = new QLineEdit(candidatinterfaceClass);
        lineEdit_provinceC->setObjectName(QString::fromUtf8("lineEdit_provinceC"));
        lineEdit_provinceC->setGeometry(QRect(140, 400, 221, 31));
        pushButton_valideCandidat = new QPushButton(candidatinterfaceClass);
        pushButton_valideCandidat->setObjectName(QString::fromUtf8("pushButton_valideCandidat"));
        pushButton_valideCandidat->setGeometry(QRect(120, 460, 61, 27));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_valideCandidat->setFont(font1);
        comboBox = new QComboBox(candidatinterfaceClass);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(140, 40, 211, 27));
        comboBox->setEditable(true);
        label = new QLabel(candidatinterfaceClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 53, 21));
        pushButton_Annuler = new QPushButton(candidatinterfaceClass);
        pushButton_Annuler->setObjectName(QString::fromUtf8("pushButton_Annuler"));
        pushButton_Annuler->setGeometry(QRect(200, 460, 80, 28));

        retranslateUi(candidatinterfaceClass);
        QObject::connect(pushButton_valideCandidat, SIGNAL(clicked()), candidatinterfaceClass, SLOT(validerCandidat()));
        QObject::connect(pushButton_Annuler, SIGNAL(clicked()), candidatinterfaceClass, SLOT(close()));

        comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(candidatinterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *candidatinterfaceClass)
    {
        candidatinterfaceClass->setWindowTitle(QApplication::translate("candidatinterfaceClass", "candidatinterface", 0, QApplication::UnicodeUTF8));
        label_nomC->setText(QApplication::translate("candidatinterfaceClass", "Nom: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("candidatinterfaceClass", "Ajout d'un Candidat", 0, QApplication::UnicodeUTF8));
        label_prenimC->setText(QApplication::translate("candidatinterfaceClass", "Prenom: ", 0, QApplication::UnicodeUTF8));
        label_dateNaissance->setText(QApplication::translate("candidatinterfaceClass", "Date de naissance :", 0, QApplication::UnicodeUTF8));
        dateEditC->setDisplayFormat(QApplication::translate("candidatinterfaceClass", "dd-MM-yyyy", 0, QApplication::UnicodeUTF8));
        label_nas->setText(QApplication::translate("candidatinterfaceClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"0\" style=\"-qt-table-type: root; margin-top:4px; margin-bottom:4px; margin-left:4px; margin-right:4px;\">\n"
"<tr>\n"
"<td style=\"border: none;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Numero d'assurance</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">social :</p></td></tr></table></body></html>", 0, QApplication::UnicodeUTF8));
        label_nCivic->setText(QApplication::translate("candidatinterfaceClass", "Numero civic :", 0, QApplication::UnicodeUTF8));
        label_rue->setText(QApplication::translate("candidatinterfaceClass", "Nom de rue :", 0, QApplication::UnicodeUTF8));
        label_ville->setText(QApplication::translate("candidatinterfaceClass", "Ville :", 0, QApplication::UnicodeUTF8));
        label_codePostal->setText(QApplication::translate("candidatinterfaceClass", "Code postal :", 0, QApplication::UnicodeUTF8));
        label_province->setText(QApplication::translate("candidatinterfaceClass", "Province :", 0, QApplication::UnicodeUTF8));
        pushButton_valideCandidat->setText(QApplication::translate("candidatinterfaceClass", "Ok", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("candidatinterfaceClass", "Bloc qu\303\251b\303\251cois", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("candidatinterfaceClass", "Conservateur", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("candidatinterfaceClass", "Independant", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("candidatinterfaceClass", "Liberal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("candidatinterfaceClass", "Nouveau parti d\303\251mocratique", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("candidatinterfaceClass", "Parti:", 0, QApplication::UnicodeUTF8));
        pushButton_Annuler->setText(QApplication::translate("candidatinterfaceClass", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class candidatinterfaceClass: public Ui_candidatinterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANDIDATINTERFACE_H
