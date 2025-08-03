#include "database.h"
#include <iostream>
#include "storage.h"


void Database::createTable(const std::string& name, const std::vector<std::string>& columns) {
    tables.emplace(name, Table(name, columns));
}

void Database::insert(const std::string& table, const std::vector<std::string>& values) {
    tables.at(table).insert(Record(values));

}

void Database::selectAll(const std::string& table) {
    tables.at(table).selectAll();
}

void Database::selectWhere(const std::string& table, const std::string& column, const std::string& value) {
    tables.at(table).selectWhere(column, value);
}
