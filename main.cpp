#include <iostream>
#include <typeinfo>
#include "TutorialConfig.h"

#include "Mouse.h"      // Class Mouse

// Example template function
template <typename K, typename V>
void map(K key, V value) {
    std::cout << "Hello from map function" << std::endl;
    std::cout << "Parameter type: " << typeid(key).name() << std::endl;
}

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;

    Mouse mouse ("Logitec", "123456789");
    std::cout << "My mose is: " << mouse.getBrand() << " with serial number " << mouse.getSerial() << std::endl;
    mouse.setBrand("Microsoft");
    std::cout << "New mouse is: " << mouse.getBrand() << " with serial number " << mouse.getSerial() << std::endl;

    if (argc < 2) {
        std::cout << "Tutorial program Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " <number>" << std::endl;

        return 1;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////
    // Git training.
    // This is a modification done to master branch which is to be merged into the string-exp
    // branch.
    //////////////////////////////////////////////////////////////////////////////////////////////

    map<double,double>(10.0, 10.0);
    map<int, int>(10, 10);

    return 0;
}