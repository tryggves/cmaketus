//
// Created by Tryggve Sørensen on 2019-03-13.
//

// Demo making another executable and add it to the CMakeLists.txt file

#include <iostream>
#include "DataSet.h"

using namespace std;

int main(int argc, char **argv) {
    cout << "Hello world" << endl;

    // Construct a dataset
    DataSet myDataset = DataSet();
    myDataset.printDataset();
    myDataset.setDataSetBuffer("Here is the new dataset.");
    myDataset.saveDataset();

    exit(0);
}