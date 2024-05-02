## Visual Class

The `Visual` class is responsible for creating and managing the user interface. It contains controls for adding, deleting, displaying all records, and checking the existence of a person in the database.

## DbManager Class

The `DbManager` class provides interaction with the SQLite database. It provides methods for creating a database, adding, deleting, and checking the existence of records, as well as for displaying all records in the console.

### Functions

- `DbManager()`: The class constructor, initializes the connection to the database and creates a table if it does not exist.
- `createDatabase()`: Creates a "people" table in the database if it does not exist.
- `addPerson()`: Adds a new record to the database with the specified name.
- `personExists()`: Checks whether a record with the specified name exists in the database.
- `removePerson()`: Deletes a record from the database by the specified name.
- `printAll()`: Displays all records from the database in the console.
- `removeAll()`: Deletes all records from the database.
- `~DbManager()`: The class destructor, closes the connection to the database when the object is destroyed.
