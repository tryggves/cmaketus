//
// Created by tryggve on 11/13/18.
//

#include "Mouse.h"
#include <string>


Mouse::Mouse (const std::string &brand, const std::string &serial) {
    Mouse::brand = brand;
    Mouse::serial = serial;
}


std::string Mouse::getSerial() {
    return std::string(serial);
}

std::string Mouse::getBrand() {
    return std::string(brand);
}

void Mouse::setBrand(const string &brand) {
    Mouse::brand = brand;
}

void Mouse::setSerial(const string &serial) {
    Mouse::serial = serial;
}
