// entry point
//repl shell
#include "database.h"
#include <iostream>
#include <sstream>

int main() {
    Database db;
    

    std::string line;
    std::cout << "MiniDB > ";
    while (std::getline(std::cin, line)) {
        std::istringstream ss(line);
        std::string command;
        ss >> command;

        if (command == "CREATE") {
            std::string tableName;
            ss >> tableName;
            std::vector<std::string> columns;
            std::string col;
            while (ss >> col) columns.push_back(col);
            db.createTable(tableName, columns);
        } else if (command == "INSERT") {
            std::string tableName;
            ss >> tableName;
            std::vector<std::string> values;
            std::string val;
            while (ss >> val) values.push_back(val);
            db.insert(tableName, values);
        } else if (command == "SELECT") {
            std::string tableName;
            ss >> tableName;
            std::string where;
            ss >> where;
            if (where == "WHERE") {
                std::string column, value;
                ss >> column >> value;
                db.selectWhere(tableName, column, value);
            } else {
                db.selectAll(tableName);
            }
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command\n";
        }

        std::cout << "MiniDB > ";
    }

    return 0;
}
