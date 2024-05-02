#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DbManager {
public:
    DbManager(const QString& path);
    bool addPerson(const QString& name);
    bool personExists(const QString& name);
    bool removePerson(const QString& name);
    void printAll() const;
    bool removeAll();
    ~DbManager();

private:
    QSqlDatabase m_db;
    bool createDatabase();
};

#endif // DBMANAGER_H
