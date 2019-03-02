//
// Created by tryggve on 3/2/19.
//

#include "DataSet.h"
#include <iostream>

// Default constructor inserts so
DataSet::DataSet() {
    dataSetBuffer = "Hello world!";
}


// Print out the dataset
void DataSet::printDataset() {
    std::cout << "This is the content of the data set: " << std::endl
        << dataSetBuffer << std::endl;
}