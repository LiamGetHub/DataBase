// file i/o
#pragma once

#include "table.h"
#include <string>

// Saves a table to "data/<table_name>.db"
void saveTableToDisk(const Table& table);

// Loads a table from "data/<table_name>.db"
Table loadTableFromDisk(const std::string& tableName);
