/********************************************************************************
** Form generated from reading ui file 'organizer.ui'
**
** Created: Wed Apr 21 07:35:16 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ORGANIZER_H
#define UI_ORGANIZER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Organizer
{
public:
    QAction *actionClose;
    QAction *actionAbout;
    QWidget *centralWidget;
    QTreeWidget *fileTypesTree;
    QLineEdit *pathEdit;
    QLineEdit *keywordsEdit;
    QTreeWidget *keywordsTree;
    QTreeWidget *fileListTree;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Organizer)
    {
        if (Organizer->objectName().isEmpty())
            Organizer->setObjectName(QString::fromUtf8("Organizer"));
        Organizer->resize(1186, 954);
        actionClose = new QAction(Organizer);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionAbout = new QAction(Organizer);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Organizer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        fileTypesTree = new QTreeWidget(centralWidget);
        new QTreeWidgetItem(fileTypesTree);
        new QTreeWidgetItem(fileTypesTree);
        new QTreeWidgetItem(fileTypesTree);
        new QTreeWidgetItem(fileTypesTree);
        fileTypesTree->setObjectName(QString::fromUtf8("fileTypesTree"));
        fileTypesTree->setGeometry(QRect(0, 60, 211, 311));
        pathEdit = new QLineEdit(centralWidget);
        pathEdit->setObjectName(QString::fromUtf8("pathEdit"));
        pathEdit->setGeometry(QRect(0, 30, 211, 26));
        keywordsEdit = new QLineEdit(centralWidget);
        keywordsEdit->setObjectName(QString::fromUtf8("keywordsEdit"));
        keywordsEdit->setGeometry(QRect(0, 380, 211, 26));
        keywordsTree = new QTreeWidget(centralWidget);
        keywordsTree->setObjectName(QString::fromUtf8("keywordsTree"));
        keywordsTree->setGeometry(QRect(0, 410, 211, 471));
        keywordsTree->setContextMenuPolicy(Qt::CustomContextMenu);
        keywordsTree->setEditTriggers(QAbstractItemView::EditKeyPressed);
        fileListTree = new QTreeWidget(centralWidget);
        fileListTree->setObjectName(QString::fromUtf8("fileListTree"));
        fileListTree->setGeometry(QRect(220, 0, 961, 861));
        fileListTree->setContextMenuPolicy(Qt::CustomContextMenu);
        fileListTree->header()->setProperty("showSortIndicator", QVariant(true));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 211, 27));
        Organizer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Organizer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1186, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Organizer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Organizer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Organizer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Organizer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Organizer->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuHelp->addAction(actionAbout);

        retranslateUi(Organizer);
        QObject::connect(keywordsEdit, SIGNAL(returnPressed()), Organizer, SLOT(addNewKeyword()));
        QObject::connect(fileTypesTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), Organizer, SLOT(startSearch(QTreeWidgetItem*,int)));
        QObject::connect(fileListTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), Organizer, SLOT(openFileOrDirectory(QTreeWidgetItem*,int)));
        QObject::connect(keywordsTree, SIGNAL(customContextMenuRequested(QPoint)), Organizer, SLOT(showKeywordsTreeMenu(QPoint)));
        QObject::connect(actionClose, SIGNAL(triggered()), Organizer, SLOT(close()));
        QObject::connect(fileListTree, SIGNAL(customContextMenuRequested(QPoint)), Organizer, SLOT(showFilesTreeMenu(QPoint)));
        QObject::connect(pushButton, SIGNAL(clicked(bool)), Organizer, SLOT(showFileDialog(bool)));

        QMetaObject::connectSlotsByName(Organizer);
    } // setupUi

    void retranslateUi(QMainWindow *Organizer)
    {
        Organizer->setWindowTitle(QApplication::translate("Organizer", "Organizer", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("Organizer", "Close", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("Organizer", "About", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = fileTypesTree->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("Organizer", "File Extensions", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("Organizer", "File Types", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = fileTypesTree->isSortingEnabled();
        fileTypesTree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = fileTypesTree->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("Organizer", "*.pdf, *.chm", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("Organizer", "Books", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = fileTypesTree->topLevelItem(1);
        ___qtreewidgetitem2->setText(1, QApplication::translate("Organizer", "*.ogg, *.mpg, *.mp4, *.mov, *.avi", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("Organizer", "Videos", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = fileTypesTree->topLevelItem(2);
        ___qtreewidgetitem3->setText(1, QApplication::translate("Organizer", "*.doc, *.odt, *.txt", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem3->setText(0, QApplication::translate("Organizer", "Documents", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = fileTypesTree->topLevelItem(3);
        ___qtreewidgetitem4->setText(1, QApplication::translate("Organizer", "*.rar, *.zip, *.tar, *.tar.gz", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(0, QApplication::translate("Organizer", "Archives", 0, QApplication::UnicodeUTF8));
        fileTypesTree->setSortingEnabled(__sortingEnabled);

        QTreeWidgetItem *___qtreewidgetitem5 = keywordsTree->headerItem();
        ___qtreewidgetitem5->setText(0, QApplication::translate("Organizer", "Keywords", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = fileListTree->headerItem();
        ___qtreewidgetitem6->setText(1, QApplication::translate("Organizer", "File Path", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem6->setText(0, QApplication::translate("Organizer", "File Name", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Organizer", "Select A Directory", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("Organizer", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("Organizer", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Organizer: public Ui_Organizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORGANIZER_H
