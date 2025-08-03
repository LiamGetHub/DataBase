#include "table.h"
#include <iostream>

Table::Table(const std::string& name, const std::vector<std::string>& columns)
    : name(name), columns(columns) {}

void Table::insert(const Record& record) {
    records.push_back(record);
}

void Table::selectAll() const {
    for (const auto& record : records) {
        record.print();
    }
}

void Table::selectWhere(const std::string& column, const std::string& value) const {
    int index = getColumnIndex(column);
    for (const auto& record : records) {
        if (record.getValue(index) == value) {
            record.print();
        }
    }
}

int Table::getColumnIndex(const std::string& column) const {
    for (size_t i = 0; i < columns.size(); ++i) {
        if (columns[i] == column) return i;
    }
    throw std::runtime_error("Column not found: " + column);
}
