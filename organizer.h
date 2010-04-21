#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <QtGui/QMainWindow>
#include <QtGui/QTreeWidget>
#include <QtGui/QTreeWidgetItem>
#include <QtGui/QTreeWidgetItemIterator>
#include <QtGui/QListWidget>
#include <QtGui/QListWidgetItem>
#include <QtCore/QDir>
#include <QtCore/QFileInfo>
#include <QtCore/QFileInfoList>
#include <QtGui/QFileDialog>
#include <QtGui/QMenu>
#include <QtGui/QMessageBox>
#include <QtCore/QProcess>

namespace Ui
{
    class Organizer;
}

class Organizer : public QMainWindow
{
    Q_OBJECT

public:
    Organizer(QWidget *parent = 0);
    ~Organizer();

public slots:
    void addNewKeyword();
    void startSearch(QTreeWidgetItem* clickedItem, int isDoubleClick);
    void openFileOrDirectory(QTreeWidgetItem* clickedFileItem, int isDoubleClick);
    void showKeywordsTreeMenu(QPoint menuPoint);
    void showFilesTreeMenu(QPoint menuPoint);
    void deleteKeyword();
    void openSelectedFile();
    void moveSelectedFile();
    void deleteSelectedFile();
    void newKeyword();
    void showFileDialog(bool checked);
    void editKeyword(QTreeWidgetItem* selectedItem, int column);
    void keywordEdited(QTreeWidgetItem* selectedItem, int column);

private:
    Ui::Organizer *ui;
    void searchPath(QString path, QStringList selectedFileTypes);
    void getAllKeywords();
    void removeCurrentFiles();
    void addNewFileToFilesTree(QFileInfo fileInfo);
    QList<QString> keywords;
    QHash<QString,QString> filetypes;
};

#endif // ORGANIZER_H
