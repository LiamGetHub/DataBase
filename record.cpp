#include "record.h"
#include <iostream>

Record::Record(const std::vector<std::string>& values) : values(values) {}

std::string Record::getValue(int index) const {
    return values.at(index);
}

void Record::print() const {
    for (const auto& val : values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
