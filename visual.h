#ifndef VISUAL_H
#define VISUAL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDialog>
#include <QTextEdit>
#include <QStringList>
#include <QSqlQuery>
#include <QLabel>
#include <QDir>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "dbmanager.h"

class Visual : public QWidget {
    Q_OBJECT
public:
    explicit Visual(QWidget *parent = nullptr);

private slots:
    void addPerson();
    void removePerson();
    void printAll();
    void removeAll();
    void checkPersonExists();

private:
    QVBoxLayout *layout;
    QLabel *lineUp;
    QLineEdit *line;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *printButton;
    QPushButton *removeAllButton;
    QPushButton *checkExistsButton;

    DbManager *dbManager;

    void tableView();
    void ssignals();
};

#endif // VISUAL_H
