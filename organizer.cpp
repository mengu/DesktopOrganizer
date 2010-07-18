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
#include "organizer.h"
#include "ui_organizer.h"
#include "organizersettings.h"

Organizer::Organizer(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Organizer)
{
    this->filetypes["pdf"] = "evince";
    this->filetypes["chm"] = "chmsee";
    this->filetypes["ogg"] = "totem";
    this->filetypes["ogv"] = "totem";
    this->filetypes["mpg"] = "totem";
    this->filetypes["mp4"] = "totem";
    this->filetypes["mov"] = "totem";
    this->filetypes["avi"] = "totem";
    this->filetypes["rar"] = "file-roller";
    this->filetypes["zip"] = "file-roller";
    this->filetypes["tar"] = "file-roller";
    this->filetypes["tar.gz"] = "file-roller";
    this->filetypes["doc"] = "ooffice -writer";
    this->filetypes["odt"] = "ooffice -writer";
    this->filetypes["txt"] = "gedit";
    ui->setupUi(this);
    QString userEnvVar = getenv("USER");
    ui->pathEdit->setText("/home/"+userEnvVar);
    ui->fileTypesTree->setColumnHidden(1, true);

    /* read settings.xml */


    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(showSettingsDialog()));
}

/**
 * Shows directory selecting dialog.
 *
 * @param    bool    Checked.
 *
 */
void Organizer::showFileDialog(bool checked)
{
    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    QString userEnvVar = getenv("USER");
    fileDialog.setDirectory("/home/"+userEnvVar);
    fileDialog.setFileMode(QFileDialog::Directory);
    QDir selectedDir;
    if (fileDialog.exec())
    {
        selectedDir = fileDialog.directory();
        qDebug("Selected %s", qPrintable(selectedDir.dirName()));
        ui->pathEdit->setText(selectedDir.absolutePath());
    }
}

/**
 * Adds a new keyword from keyword edit widget. Emitted when a user types
 * a keyword to keyword edit widget and press enter key.
 *
 */
void Organizer::addNewKeyword()
{
    QTreeWidgetItem* newKeyword = new QTreeWidgetItem(ui->keywordsTree);
    ui->keywordsTree->topLevelItem(0)->addChild(newKeyword);
    newKeyword->setFlags(newKeyword->flags() | Qt::ItemIsEditable);
    newKeyword->setText(0, ui->keywordsEdit->text());
    ui->keywordsEdit->setText("");
}
/**
 * Starts file searching. Emitted when user double clicks on an item
 * in the fileTypes tree widget.
 *
 * @param    QTreeWidgetItem*    Item that has been clicked.
 * @param    int                 Column of the clicked item.
 *
 */
void Organizer::startSearch(QTreeWidgetItem* clickedItem, int column)
{
    if (ui->pathEdit->text().size() == 0)
    {
        ui->pathEdit->setText("Enter your path");
    }
    else
    {
        ui->fileListTree->clear();
        this->keywords.clear();
        this->getAllKeywords();
        QStringList selectedFileTypes = clickedItem->text(1).split(", ", QString::SkipEmptyParts);
        this->searchPath(ui->pathEdit->text(), selectedFileTypes);
    }
}

/**
 * Searches the given path with the given file types.
 * Called from Organizer::startSearch method.
 *
 * @param    QString        Path to start search.
 * @param    QStringList    File types for filtering.
 *
 */
void Organizer::searchPath(QString path, QStringList selectedFileTypes)
{
    QDir dir(path);
    if (dir.exists())
    {
        dir.setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
        dir.setSorting(QDir::DirsFirst);
        dir.setNameFilters(selectedFileTypes);

        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            if (fileInfo.isFile() && !fileInfo.isDir())
            {
                if (this->keywords.length() > 0)
                {
                    for (int i = 0; i < this->keywords.length(); i++)
                    {
                        if (fileInfo.fileName().toLower().indexOf(this->keywords[i].toLower()) != -1)
                        {
                            this->addNewFileToFilesTree(fileInfo);
                        }
                    }
                }
                else
                {
                    this->addNewFileToFilesTree(fileInfo);
                }
            }
            if (fileInfo.isDir())
            {
                this->searchPath(fileInfo.absoluteFilePath(), selectedFileTypes);
            }
        }
    }
}

/**
 * Adds a new file to the filesTree tree widget.
 * Called from Organizer::searchPath method.
 *
 * @param    QFileInfo    File info.
 *
 */
void Organizer::addNewFileToFilesTree(QFileInfo fileInfo)
{
    QTreeWidgetItem *newFileItem = new QTreeWidgetItem(ui->fileListTree);
    newFileItem->setText(0, fileInfo.fileName());
    newFileItem->setText(1, fileInfo.absoluteFilePath());
    int topLevelItemCount = ui->fileListTree->topLevelItemCount() == 0 ? 0 : ui->fileListTree->topLevelItemCount() + 1;
    ui->fileListTree->insertTopLevelItem(topLevelItemCount, newFileItem);
}

/**
 * Opens a file or directory. (Opening directories is not implemented yet.)
 * Emitted when the user double clicks on a file on the fileListTree tree widget.
 *
 * @param    QTreeWidgetItem*     Item that has been clicked.
 * @param    int                  Column of the clicked item.
 */
void Organizer::openFileOrDirectory(QTreeWidgetItem* clickedFileItem, int column)
{
    QFileInfo fileInfo(clickedFileItem->text(1));
    QString fileSuffix = fileInfo.completeSuffix();
    if (fileSuffix.count(".") > 1)
    {
        fileSuffix = fileInfo.suffix();
    }
    if (this->filetypes.contains(fileSuffix))
    {
        QStringList execArgs;
        execArgs << fileInfo.absoluteFilePath();
        QProcess::execute(this->filetypes.value(fileSuffix), execArgs);
        qDebug("%s %s", qPrintable(this->filetypes.value(fileSuffix)), qPrintable(fileInfo.absoluteFilePath()));
    }
}

/**
 * Displays a custom context menu for the keywords tree.
 * Emitted when custom context menu requested.
 *
 * @param    QPoint    Point of the menu.
 *
 */
void Organizer::showKeywordsTreeMenu(QPoint menuPoint)
{
    QMenu keywordsMenu(ui->keywordsTree);
    QAction* newKeywordAction = keywordsMenu.addAction("Add New");
    QAction* deleteAction = keywordsMenu.addAction("Delete");
    connect(newKeywordAction, SIGNAL(triggered()), this, SLOT(newKeyword()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteKeyword()));
    keywordsMenu.exec(QCursor::pos());
}

/**
 * Adds a new keyword to keywordsTree tree widget.
 * Emitted when user clicks "Add New" context menu item.
 *
 */
void Organizer::newKeyword()
{
    QTreeWidgetItem* newKeywordItem = new QTreeWidgetItem(ui->keywordsTree);
    newKeywordItem->setText(0, "edit me");
    int topLevelItemCount = ui->keywordsTree->topLevelItemCount() == 0 ? 0 : ui->keywordsTree->topLevelItemCount() + 1;
    ui->keywordsTree->insertTopLevelItem(topLevelItemCount, newKeywordItem);
    newKeywordItem->setFlags(newKeywordItem->flags() | Qt::ItemIsEditable);
}

/**
 * Displays a custom context menu for the file list tree.
 * Emitted when custom context menu requested.
 *
 * @param    QPoint    Menu point.
 *
 */
void Organizer::showFilesTreeMenu(QPoint menuPoint)
{
    QMenu filesTreeMenu(ui->fileListTree);
    QAction* openAction = filesTreeMenu.addAction("Open File");
    QAction* moveAction = filesTreeMenu.addAction("Move File");
    QAction* deleteAction = filesTreeMenu.addAction("Delete File");
    connect(openAction, SIGNAL(triggered()), this, SLOT(openSelectedFile()));
    connect(moveAction, SIGNAL(triggered()), this, SLOT(moveSelectedFile()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteSelectedFile()));
    filesTreeMenu.exec(QCursor::pos());
}

/**
 * Opens the selected file from the files tree.
 * Emitted when user clicks context menu item "Open File".
 *
 */
void Organizer::openSelectedFile()
{
    for (int i = 0; i < ui->fileListTree->selectedItems().length(); i++)
    {
        QTreeWidgetItem* selectedFileItem = ui->fileListTree->selectedItems().at(i);
        QFileInfo fileInfo(selectedFileItem->text(1));
        QString fileSuffix = fileInfo.completeSuffix();
        if (fileSuffix.count(".") > 1)
        {
            fileSuffix = fileInfo.suffix();
        }
        if (this->filetypes.contains(fileSuffix))
        {
            QStringList execArgs;
            execArgs << fileInfo.absoluteFilePath();
            QProcess::execute(this->filetypes.value(fileSuffix), execArgs);
            qDebug("%s %s", qPrintable(this->filetypes.value(fileSuffix)), qPrintable(fileInfo.absoluteFilePath()));
        }
    }
}

/**
 * Displays a file dialog for choosing the target directory for moving files
 * and moves the selected files.
 * Emitted when user clicks context menu item "Move File".
 *
 */
void Organizer::moveSelectedFile()
{
    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setFileMode(QFileDialog::Directory);
    QDir selectedDir;
    if (fileDialog.exec())
    {
        selectedDir = fileDialog.directory();
        for (int i = 0; i < ui->fileListTree->selectedItems().length(); i++)
        {
            QTreeWidgetItem* selectedFileItem = ui->fileListTree->selectedItems().at(i);
            QFileInfo fileInfo(selectedFileItem->text(1));
            qDebug("%s", qPrintable(selectedDir.dirName()));
            selectedDir.rename(fileInfo.absoluteFilePath(), selectedDir.absolutePath()+"/"+fileInfo.fileName());
        }
    }
}

/**
 * Deletes the selected file from both file system and the files tree.
 * Emitted when user clicks context menu item "Delete File".
 *
 */
void Organizer::deleteSelectedFile()
{
    QTreeWidgetItem* selectedFileItem = ui->fileListTree->selectedItems()[0];
    QMessageBox alertBox;
    alertBox.setText("Delete File "+selectedFileItem->text(0));
    alertBox.setInformativeText("Are you sure you want to delete " + selectedFileItem->text(0) + "?");
    alertBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    alertBox.setDefaultButton(QMessageBox::No);
    int result = alertBox.exec();
    if (result == QMessageBox::Yes)
    {
        QDir dir;
        dir.remove(selectedFileItem->text(1));
        delete selectedFileItem;
    }
    else
    {
        alertBox.close();
    }
}

/**
* Makes a keyword tree item editable.
* Emitted when the user double clicks on a keyword.
*
* @param    QTreeWidgetItem*    Keyword that has been clicked.
* @param    int                 Column of the keyword.
*
*/
void Organizer::editKeyword(QTreeWidgetItem* selectedItem, int column)
{
    ui->keywordsTree->editItem(selectedItem, column);
}

/**
 * Resets the keywords property of Organizer class and retrieves new keywords.
 * Emitted when a user edits a keyword from the keywords tree.
 *
 * @param    QTreeWidgetItem*    Edited keyword.
 * @param    int                 Keyword column.
 *
 */
void Organizer::keywordEdited(QTreeWidgetItem* selectedItem, int column)
{
    this->getAllKeywords();
}

/**
 * Deletes a keyword.
 * Emitted when the user clicks keywords tree context menu item "Delete".
 *
 */
void Organizer::deleteKeyword()
{
    QTreeWidgetItem* selectedKeyword = ui->keywordsTree->selectedItems()[0];
    ui->keywordsTree->takeTopLevelItem(ui->keywordsTree->indexOfTopLevelItem(selectedKeyword));
    this->keywords.removeOne(selectedKeyword->text(0));
    delete selectedKeyword;
}

/**
 * Retrieves all keywords from the keywords tree and adds them to
 * keywords property of the class.
 *
 */
void Organizer::getAllKeywords()
{
    this->keywords.clear();
    QTreeWidgetItemIterator it(ui->keywordsTree);
    while (*it)
    {
        this->keywords.append((*it)->text(0));
        ++it;
    }
}

void Organizer::showSettingsDialog()
{
    OrganizerSettings settings;
    int result = settings.exec();
    if (result == 1)
    {

    }
}

Organizer::~Organizer()
{
    delete ui;
}
