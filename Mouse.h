//
// Created by tryggve on 11/13/18.
//

#ifndef CMAKETUT_MOUSE_H
#define CMAKETUT_MOUSE_H

// Standard template library string handling
#include <string>

using namespace std;

class Mouse {

public:
    // Constructor - notice parameter names dont have to be specified in the declaration
    Mouse (const string&, const string&);

    void setBrand(const string &brand);

    void setSerial(const string &serial);

private:
    string serial;
    string brand;

public:
    std::string getBrand();
    std::string getSerial();
};


#endif //CMAKETUT_MOUSE_H
