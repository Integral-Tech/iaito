#ifndef SAVEPROJECTDIALOG_H
#define SAVEPROJECTDIALOG_H

#include <QAbstractButton>
#include <QDialog>

#include <memory>

namespace Ui {
class SaveProjectDialog;
}

class SaveProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveProjectDialog(bool quit, QWidget *parent = nullptr);
    ~SaveProjectDialog();

    virtual void accept() override;

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
    void on_selectProjectsDirButton_clicked();

private:
    std::unique_ptr<Ui::SaveProjectDialog> ui;
};

#endif // SAVEPROJECTDIALOG_H
