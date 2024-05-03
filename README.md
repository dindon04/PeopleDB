## Visual Class

The `Visual` class is responsible for creating and managing the user interface. It contains controls for adding, deleting, displaying all records, and checking the existence of a person in the database.

## DbManager Class

The `DbManager` class provides interaction with the SQLite database. It provides methods for creating a database, adding, deleting, and checking the existence of records, as well as for displaying all records in the console.

## Features

- **Create Database**: The `DbManager` constructor takes a path to the SQLite database file. If the database does not exist, it will be created.
- **Create Table**: The `createDatabase` method creates a table named `people` with columns `id` and `name`. The `id` is an auto-incrementing integer and `name` is a text field.

- **DbManager(const QString& path)**: This is the constructor of the class that takes a path to the SQLite database file as an argument. If the database does not exist, it will be created. If the database fails to open, an error message is output.
- **createDatabase()**: This method creates a table named `people` if it does not already exist. The table has two columns: `id` and `name`. `id` is an auto-incrementing integer and `name` is a text field.
- **addPerson(const QString& name)**: This method adds a new record to the `people` table. It takes the name of a person as an argument and inserts it into the table. If the operation fails, an error message is output.
- **personExists(const QString& name)**: This method checks whether a person with the given name exists in the `people` table. If the person exists, the method returns `true`, otherwise it returns `false`.
- **removePerson(const QString& name)**: This method removes a person from the `people` table by their name. If the person does not exist, an error message is output. If the operation fails, an error message is output.
- **printAll() const**: This method prints all the records in the `people` table to the console.
- **removeAll()**: This method removes all records from the `people` table. If the operation fails, an error message is output.
- **~DbManager()**: This is the destructor of the class. It closes the database connection if it is open.

## Usage

Add a Person: Enter a name in the text field and click the “Add” button. A success message will be displayed if the person is added successfully, otherwise - error message.

Remove a Person: Enter a name in the text field and click the “Remove” button. A success message will be displayed if the person is removed successfully, otherwise - error message.

Print All People: Click the “Print All” button to display a dialog with all the people in the database.

Remove All People: Click the “Remove All” button to remove all people from the database. A success message will be displayed if all records are removed successfully, otherwise - error message.

Check if a Person Exists: Enter a name in the text field and call the checkPersonExists method. If the name field is not empty, it will check if the person exists in the database and display a message accordingly.
