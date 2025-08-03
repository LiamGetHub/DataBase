#include "storage.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void saveTableToDisk(const Table& table) {
    std::string dir = "data";
    fs::create_directory(dir);  // Create directory if it doesn't exist

    std::string filePath = dir + "/" + table.getName() + ".db";
    std::ofstream out(filePath);
    if (!out.is_open()) {
        std::cerr << "Failed to open file for writing: " << filePath << "\n";
        return;
    }

    // Write column headers
    const auto& columns = table.getColumns();
    for (size_t i = 0; i < columns.size(); ++i) {
        out << columns[i];
        if (i < columns.size() - 1)
            out << ",";
    }
    out << "\n";

    // Write records
    const auto& records = table.getRecords();
    for (const auto& record : records) {
        for (size_t i = 0; i < columns.size(); ++i) {
            out << record.getValue(i);
            if (i < columns.size() - 1)
                out << ",";
        }
        out << "\n";
    }
}

Table loadTableFromDisk(const std::string& tableName) {
    std::string filePath = "data/" + tableName + ".db";
    std::ifstream in(filePath);
    if (!in.is_open()) {
        throw std::runtime_error("Could not open table file: " + filePath);
    }

    std::string line;
    std::vector<std::string> columns;

    // First line: column headers
    if (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string col;
        while (std::getline(ss, col, ',')) {
            columns.push_back(col);
        }
    }

    Table table(tableName, columns);

    // Remaining lines: records
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string val;
        std::vector<std::string> values;
        while (std::getline(ss, val, ',')) {
            values.push_back(val);
        }
        table.insert(Record(values));
    }

    return table;
}
