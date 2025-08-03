#pragma once
#include "record.h"
#include <string>
#include <vector>

class Table {
public:
    Table(const std::string& name, const std::vector<std::string>& columns);
    void insert(const Record& record);
    void selectAll() const;
    void selectWhere(const std::string& column, const std::string& value) const;
    const std::vector<std::string>& getColumns() const;
    const std::vector<Record>& getRecords() const;
    const std::string& getName() const;

private:
    std::string name;
    std::vector<std::string> columns;
    std::vector<Record> records;

    int getColumnIndex(const std::string& column) const;
};
