#include "organizersettings.h"
#include "ui_organizersettings.h"

OrganizerSettings::OrganizerSettings(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::OrganizerSettings)
{
    m_ui->setupUi(this);
}

OrganizerSettings::~OrganizerSettings()
{
    delete m_ui;
}

void OrganizerSettings::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void OrganizerSettings::saveFileTypes()
{
}

void OrganizerSettings::saveFileAssociations()
{
}
