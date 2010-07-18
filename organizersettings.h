#ifndef ORGANIZERSETTINGS_H
#define ORGANIZERSETTINGS_H

#include <QtGui/QDialog>

namespace Ui {
    class OrganizerSettings;
}

class OrganizerSettings : public QDialog {
    Q_OBJECT
public:
    OrganizerSettings(QWidget *parent = 0);
    ~OrganizerSettings();
    void saveFileTypes();
    void saveFileAssociations();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::OrganizerSettings *m_ui;
};

#endif // ORGANIZERSETTINGS_H
