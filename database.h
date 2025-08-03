//core db logic
#pragma once
#include "table.h"
#include <map>
#include <string>

class Database {
public:
    void createTable(const std::string& name, const std::vector<std::string>& columns);
    void insert(const std::string& table, const std::vector<std::string>& values);
    void selectAll(const std::string& table);
    void selectWhere(const std::string& table, const std::string& column, const std::string& value);
private:
    std::map<std::string, Table> tables;
};
