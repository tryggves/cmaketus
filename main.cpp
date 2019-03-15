#include <iostream>
#include <typeinfo>
#include <ctime>
#include "TutorialConfig.h"

#include "Mouse.h"      // Class Mouse
#include "DataSet.h"    // DataSet (container for data)

// Example template function
template <typename K, typename V>
void map(K key, V value) {
    std::cout << "Hello from map function" << std::endl;
    std::cout << "Parameter type: " << typeid(key).name() << std::endl;
}


// Utility function for getting date and time
// Parameters:
//      in: None
//      out: string         The Data and time formatted as a string object

string dateTime() {
    // These are used for getting the time and date
    time_t  rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    return string(asctime(timeinfo));
}

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;

    // Create a DataSet instance.
    DataSet myDataSet = DataSet();


    Mouse mouse ("Logitec", "123456789");
    std::cout << "My mose is: " << mouse.getBrand() << " with serial number " << mouse.getSerial() << std::endl;
    mouse.setBrand("Microsoft");
    std::cout << "New mouse is: " << mouse.getBrand() << " with serial number " << mouse.getSerial() << std::endl;

    std::cout << "Tutorial program Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;

    /*
    if (argc < 2) {
        std::cout << "Tutorial program Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " <number>" << std::endl;

        return 1;
    }
    // */

    //////////////////////////////////////////////////////////////////////////////////////////////
    // Git training.
    // This is a modification done to master branch which is to be merged into the string-exp
    // branch.
    // This change was made after creating the string-exp branch, causing the master branch
    // to advance separate from string-exp branch.
    //////////////////////////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////
    // Make hotfix to master branch.
    //////////////////////////////////////////////////////////////////////////////////////////////

    map<double,double>(10.0, 10.0);
    map<int, int>(10, 10);


    myDataSet.printDataset();

    std::cout << "Set new dataset value..." << std::endl;



    myDataSet.setDataSetBuffer ("Hello world!");



    std::cout << "Save dataset to persistent storage...";
    int numChars = myDataSet.saveDataset();
    if (numChars < 0) {
        cerr << "Save dataset failed!" << std::endl;
    } else {
        std::cout << "Save dataset success." << std::endl;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////
    // Continue to develop on the master branch adding new features.
    /////////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////////
    // Continue even more to develop on the master branch adding new features.
    /////////////////////////////////////////////////////////////////////////////////////////////

    return 0;
}