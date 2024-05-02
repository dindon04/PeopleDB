#include "dbmanager.h"

DbManager::DbManager(const QString& path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Connection to database failed";
    } else {
        qDebug() << "Connection to database ok";

        if (!createDatabase()) {
            qDebug() << "Failed to create database";
        }
    }
}

bool DbManager::createDatabase() {
    QSqlQuery query(m_db);
    bool success = query.exec("CREATE TABLE IF NOT EXISTS people (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");

    if (!success) {
        qDebug() << "Error creating table:" << query.lastError().text();
    }

    return success;
}

bool DbManager::addPerson(const QString& name) {
    bool success = false;
    QSqlQuery query;

    query.prepare("INSERT INTO people (name) VALUES (:name)");
    query.bindValue(":name", name);

    if(query.exec()) {
        success = true;

    }
    else {
        qDebug() << "addPerson error: " << query.lastError().text();
    }

    return success;

}

bool DbManager::personExists(const QString& name){
    bool found = false;
    QSqlQuery query;
    query.prepare("SELECT name FROM people WHERE name = (:name)");
    query.bindValue(":name", name);
    if (query.exec()){
        if (query.next()) {
            found = true;
        }
    }
    else {
        qDebug() << "personExists error: " << query.lastError().text();
    }
    return found;
}

bool DbManager::removePerson(const QString& name) {
    bool success = false;
    if (personExists(name)) {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM people WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();
        if (!success) {
            qDebug() << "removePerson failed";
        }
    } else {
        qDebug() << "person doesn't exist";
    }
    return success;
}

void DbManager::printAll() const {
    qDebug() << "People in db:";
    QSqlQuery query ("SELECT * FROM people");
    int idName = query.record().indexOf("name");
    while (query.next()) {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}

bool DbManager::removeAll() {
    bool success = false;
    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM PEOPLE");
    if (removeQuery.exec()) {
        success = true;
    } else {
        qDebug() << "remove failed: " << removeQuery.lastError();
    }
    return success;
}

DbManager::~DbManager() {
    if (m_db.isOpen()) {
        m_db.close();
    }
}
