#pragma once
#include <vector>
#include <string>

class Record {
public:
    Record(const std::vector<std::string>& values);
    std::string getValue(int index) const;
    void print() const;
private:
    std::vector<std::string> values;
};
