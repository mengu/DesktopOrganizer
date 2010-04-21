#include "organizer.h"
#include "ui_organizer.h"

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
    ui->pathEdit->setText("/home/mengu/Desktop");
    ui->fileTypesTree->setColumnHidden(1, true);
}

void Organizer::showFileDialog(bool checked)
{
    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory("/home/mengu/Desktop");
    fileDialog.setFileMode(QFileDialog::Directory);
    QDir selectedDir;
    if (fileDialog.exec())
    {
        selectedDir = fileDialog.directory();
        qDebug("Selected %s", qPrintable(selectedDir.dirName()));
        ui->pathEdit->setText(selectedDir.absolutePath());
    }
}

void Organizer::addNewKeyword()
{
    QTreeWidgetItem* newKeyword = new QTreeWidgetItem(ui->keywordsTree);
    ui->keywordsTree->topLevelItem(0)->addChild(newKeyword);
    newKeyword->setFlags(newKeyword->flags() | Qt::ItemIsEditable);
    newKeyword->setText(0, ui->keywordsEdit->text());
    ui->keywordsEdit->setText("");
}

void Organizer::startSearch(QTreeWidgetItem* clickedItem, int isDoubleClick)
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

void Organizer::removeCurrentFiles()
{
    for (int i = 0; i <= ui->fileListTree->topLevelItemCount(); i++)
    {
        ui->fileListTree->takeTopLevelItem(i);
        QTreeWidgetItem *widgetItem = ui->fileListTree->topLevelItem(i);
        for (int j = 0; j <= widgetItem->childCount(); j++)
        {
            QTreeWidgetItem *childWidget = widgetItem->child(j);
            widgetItem->removeChild(childWidget);
        }
    }
}

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

void Organizer::addNewFileToFilesTree(QFileInfo fileInfo)
{
    QTreeWidgetItem *newFileItem = new QTreeWidgetItem(ui->fileListTree);
    newFileItem->setText(0, fileInfo.fileName());
    newFileItem->setText(1, fileInfo.absoluteFilePath());
    int topLevelItemCount = ui->fileListTree->topLevelItemCount() == 0 ? 0 : ui->fileListTree->topLevelItemCount() + 1;
    ui->fileListTree->insertTopLevelItem(topLevelItemCount, newFileItem);
}

void Organizer::openFileOrDirectory(QTreeWidgetItem* clickedFileItem, int isDoubleClick)
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

void Organizer::showKeywordsTreeMenu(QPoint menuPoint)
{
    QMenu keywordsMenu(ui->keywordsTree);
    QAction* newKeywordAction = keywordsMenu.addAction("Add New");
    QAction* deleteAction = keywordsMenu.addAction("Delete");
    connect(newKeywordAction, SIGNAL(triggered()), this, SLOT(newKeyword()));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteKeyword()));
    keywordsMenu.exec(QCursor::pos());
}

void Organizer::newKeyword()
{
    QTreeWidgetItem* newKeywordItem = new QTreeWidgetItem(ui->keywordsTree);
    newKeywordItem->setText(0, "edit me");
    int topLevelItemCount = ui->keywordsTree->topLevelItemCount() == 0 ? 0 : ui->keywordsTree->topLevelItemCount() + 1;
    ui->keywordsTree->insertTopLevelItem(topLevelItemCount, newKeywordItem);
    newKeywordItem->setFlags(newKeywordItem->flags() | Qt::ItemIsEditable);
    //ui->keywordsTree->editItem(newKeywordItem, 0);
}

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

void Organizer::moveSelectedFile()
{
    for (int i = 0; i < ui->fileListTree->selectedItems().length(); i++)
    {
        QTreeWidgetItem* selectedFileItem = ui->fileListTree->selectedItems().at(i);
        QFileInfo fileInfo(selectedFileItem->text(1));
        QFileDialog fileDialog(this);
        fileDialog.setFileMode(QFileDialog::AnyFile);
        fileDialog.setDirectory(fileInfo.absoluteDir());
        fileDialog.setFileMode(QFileDialog::Directory);
        QDir selectedDir;
        if (fileDialog.exec())
        {
            selectedDir = fileDialog.directory();
            qDebug("%s", qPrintable(selectedDir.dirName()));
            selectedDir.rename(fileInfo.absoluteFilePath(), selectedDir.absolutePath()+"/"+fileInfo.fileName());
        }
    }
}

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

void Organizer::editKeyword(QTreeWidgetItem* selectedItem, int column)
{
    ui->keywordsTree->editItem(selectedItem, column);
}

void Organizer::deleteKeyword()
{
    QTreeWidgetItem* selectedKeyword = ui->keywordsTree->selectedItems()[0];
    ui->keywordsTree->takeTopLevelItem(ui->keywordsTree->indexOfTopLevelItem(selectedKeyword));
    this->keywords.removeOne(selectedKeyword->text(0));
    delete selectedKeyword;
}

void Organizer::getAllKeywords()
{
    QTreeWidgetItemIterator it(ui->keywordsTree);
    while (*it)
    {
        this->keywords.append((*it)->text(0));
        ++it;
    }
}

Organizer::~Organizer()
{
    delete ui;
}
