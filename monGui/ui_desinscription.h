/********************************************************************************
** Form generated from reading UI file 'desinscription.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESINSCRIPTION_H
#define UI_DESINSCRIPTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_desinscriptionClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_Nas;
    QPushButton *pushButton_desinscrire;
    QPushButton *pushButton_Annuler;

    void setupUi(QDialog *desinscriptionClass)
    {
        if (desinscriptionClass->objectName().isEmpty())
            desinscriptionClass->setObjectName(QString::fromUtf8("desinscriptionClass"));
        desinscriptionClass->resize(506, 138);
        label = new QLabel(desinscriptionClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 411, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(desinscriptionClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 121, 51));
        lineEdit_Nas = new QLineEdit(desinscriptionClass);
        lineEdit_Nas->setObjectName(QString::fromUtf8("lineEdit_Nas"));
        lineEdit_Nas->setGeometry(QRect(190, 60, 221, 27));
        pushButton_desinscrire = new QPushButton(desinscriptionClass);
        pushButton_desinscrire->setObjectName(QString::fromUtf8("pushButton_desinscrire"));
        pushButton_desinscrire->setGeometry(QRect(180, 100, 80, 28));
        pushButton_Annuler = new QPushButton(desinscriptionClass);
        pushButton_Annuler->setObjectName(QString::fromUtf8("pushButton_Annuler"));
        pushButton_Annuler->setGeometry(QRect(270, 100, 80, 28));

        retranslateUi(desinscriptionClass);
        QObject::connect(pushButton_desinscrire, SIGNAL(clicked()), desinscriptionClass, SLOT(Destruction()));
        QObject::connect(pushButton_Annuler, SIGNAL(clicked()), desinscriptionClass, SLOT(close()));

        QMetaObject::connectSlotsByName(desinscriptionClass);
    } // setupUi

    void retranslateUi(QDialog *desinscriptionClass)
    {
        desinscriptionClass->setWindowTitle(QApplication::translate("desinscriptionClass", "desinscription", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("desinscriptionClass", "D\303\251sinscription d'une personne ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("desinscriptionClass", "Entrez le num\303\251ro\n"
"d'assurance sociale:", 0, QApplication::UnicodeUTF8));
        pushButton_desinscrire->setText(QApplication::translate("desinscriptionClass", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_Annuler->setText(QApplication::translate("desinscriptionClass", "Annuler", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class desinscriptionClass: public Ui_desinscriptionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESINSCRIPTION_H
