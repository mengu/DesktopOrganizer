/********************************************************************************
** Form generated from reading ui file 'organizersettings.ui'
**
** Created: Thu Apr 22 04:43:31 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ORGANIZERSETTINGS_H
#define UI_ORGANIZERSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrganizerSettings
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTreeWidget *treeWidget;
    QWidget *tab_2;
    QTreeWidget *treeWidget_2;

    void setupUi(QDialog *OrganizerSettings)
    {
        if (OrganizerSettings->objectName().isEmpty())
            OrganizerSettings->setObjectName(QString::fromUtf8("OrganizerSettings"));
        OrganizerSettings->setWindowModality(Qt::WindowModal);
        OrganizerSettings->resize(573, 300);
        buttonBox = new QDialogButtonBox(OrganizerSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(220, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(OrganizerSettings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 571, 241));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        treeWidget = new QTreeWidget(tab);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(0, 0, 561, 201));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        treeWidget_2 = new QTreeWidget(tab_2);
        treeWidget_2->setObjectName(QString::fromUtf8("treeWidget_2"));
        treeWidget_2->setGeometry(QRect(0, 0, 571, 211));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(OrganizerSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), OrganizerSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OrganizerSettings, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OrganizerSettings);
    } // setupUi

    void retranslateUi(QDialog *OrganizerSettings)
    {
        OrganizerSettings->setWindowTitle(QApplication::translate("OrganizerSettings", "Dialog", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("OrganizerSettings", "Extension", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("OrganizerSettings", "File Type", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("OrganizerSettings", "*.pdf, *.chm", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("OrganizerSettings", "Books", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(1, QApplication::translate("OrganizerSettings", "*.ogv, *.mpg, *.mov, *.mp4, *.avi", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("OrganizerSettings", "Videos", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(1, QApplication::translate("OrganizerSettings", "*.txt, *.odt, *.doc", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem3->setText(0, QApplication::translate("OrganizerSettings", "Documents", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(1, QApplication::translate("OrganizerSettings", "*.zip, *.rar, *.tar, *.tar.gz", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(0, QApplication::translate("OrganizerSettings", "Archives", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("OrganizerSettings", "File Types", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget_2->headerItem();
        ___qtreewidgetitem5->setText(1, QApplication::translate("OrganizerSettings", "Application", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem5->setText(0, QApplication::translate("OrganizerSettings", "File Extension", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("OrganizerSettings", "File Associations", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(OrganizerSettings);
    } // retranslateUi

};

namespace Ui {
    class OrganizerSettings: public Ui_OrganizerSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZERSETTINGS_H
