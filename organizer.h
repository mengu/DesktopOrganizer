/*****************************************************************************
* This file is part of DesktopOrganizer.
*
* DesktopOrganizer is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* DesktopOrganizer is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with DesktopOrganizer.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

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
#include <QtGui/QDialogButtonBox>
#include <QtCore/QProcess>
#include <QXmlStreamReader>

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
    void startSearch(QTreeWidgetItem* clickedItem, int column);
    void openFileOrDirectory(QTreeWidgetItem* clickedFileItem, int column);
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
    void showSettingsDialog();

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
