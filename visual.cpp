#include "visual.h"

Visual::Visual(QWidget *parent) : QWidget(parent) {
    tableView();
    ssignals();

    QString pathToDatabase = "/home/student-3/SQLite/project/people.db";
    dbManager = new DbManager(pathToDatabase);

    setFixedSize(500, 300);
}

void Visual::addPerson() {
    QString name = line->text();
    if (!name.isEmpty()) {
        if (dbManager->addPerson(name)) {
            QMessageBox::information(this, "Success", "Person added successfully.");
            line->clear();
        } else {
            QMessageBox::warning(this, "Error", "Failed to add person.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a name.");
    }
}

void Visual::removePerson() {
    QString name = line->text();
    if (!name.isEmpty()) {
        if (dbManager->removePerson(name)) {
            QMessageBox::information(this, "Success", "Person removed successfully.");
            line->clear();
        } else {
            QMessageBox::warning(this, "Error", "Failed to remove person.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a name.");
    }
}

void Visual::printAll() {
    QDialog *printAllDialog = new QDialog(this);
    QVBoxLayout *layout = new QVBoxLayout(printAllDialog);

    QStringList records;
    QSqlQuery query("SELECT * FROM people");
    while (query.next()) {
        QString name = query.value("name").toString();
        records.append(name);
    }

    QString allRecordsText = "People in list: \n";
    for (const QString& record : records) {
        allRecordsText += record + "\n";
    }

    QTextEdit *textEdit = new QTextEdit(printAllDialog);
    textEdit->setPlainText(allRecordsText);
    textEdit->setReadOnly(true);

    layout->addWidget(textEdit);

    QFont font;
    font.setPointSize(12);
    textEdit->setFont(font);

    printAllDialog->setWindowTitle("Database");
    printAllDialog->resize(400, 400);

    printAllDialog->exec();
}

void Visual::removeAll() {
    if (dbManager->removeAll()) {
        QMessageBox::information(this, "Success", "All records removed successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Failed to remove all records.");
    }
}

void Visual::checkPersonExists() {
    QString name = line->text();
    if (!name.isEmpty()) {
        if (dbManager->personExists(name)) {
            QMessageBox::information(this, "Result", "Person exists.");
        } else {
            QMessageBox::information(this, "Result", "Person does not exist.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a name.");
    }
}

void Visual::tableView() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->setSpacing(10);

    setStyleSheet("background-color: #87CEEB");

    lineUp = new QLabel("Name:  ", this);
    lineUp->setStyleSheet("QLabel { font-size: 16px; color: blue; }");

    line = new QLineEdit(this);
    line->setStyleSheet("QLineEdit { width: 200px; height: 40px; color: blue; background-color: #ADD8E6; border-radius: 20px;}");
    addButton = new QPushButton("Add", this);
    addButton->setStyleSheet("QPushButton { min-width: 150px; height: 50px; background-color: #ADD8E6; color: blue; border-radius: 25px; }");

    removeButton = new QPushButton("Remove", this);
    removeButton->setStyleSheet("QPushButton { min-width: 150px; height: 50px; background-color: #ADD8E6; color: blue; border-radius: 25px; }");

    printButton = new QPushButton("Print All", this);
    printButton->setStyleSheet("QPushButton { min-width: 150px; height: 50px; background-color: #ADD8E6; color: blue; border-radius: 25px;}");

    topLayout->addWidget(lineUp);
    topLayout->addWidget(line);

    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(addButton);
    buttonsLayout->addWidget(removeButton);
    buttonsLayout->addWidget(printButton);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(buttonsLayout);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->setSpacing(10);

    removeAllButton = new QPushButton("Remove All", this);
    removeAllButton->setStyleSheet("QPushButton { min-width: 150px; height: 50px; background-color: #ADD8E6; color: blue; border-radius: 25px; }");

    checkExistsButton = new QPushButton("Person Exists", this);
    checkExistsButton->setStyleSheet("QPushButton { min-width: 150px; height: 50px; background-color: #ADD8E6; color: blue; border-radius: 25px;}");

    bottomLayout->addWidget(removeAllButton);
    bottomLayout->addWidget(checkExistsButton);

    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
}

void Visual::ssignals() {
    connect(addButton, &QPushButton::clicked, this, &Visual::addPerson);
    connect(removeButton, &QPushButton::clicked, this, &Visual::removePerson);
    connect(printButton, &QPushButton::clicked, this, &Visual::printAll);
    connect(removeAllButton, &QPushButton::clicked, this, &Visual::removeAll);
    connect(checkExistsButton, &QPushButton::clicked, this, &Visual::checkPersonExists);
}
