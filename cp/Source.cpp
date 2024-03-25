#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main() {
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    try {
        // Create a connection
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");

        // Connect to the database
        con->setSchema("your_database_name");

        // Execute a query
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM your_table");

        // Process the result
        while (res->next()) {
            cout << "ID: " << res->getInt("id") << ", Name: " << res->getString("name") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
