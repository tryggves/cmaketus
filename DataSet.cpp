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

// Persist the dataset to file
int DataSet::saveDataset() {
    int numCharsWritten = 0;        // Number of characters written

    // Open the persist file for write and reset the file pointer discarding existing content
    // The w+ mode opens for write/update creating the file if it does not exist.
    dsFile = fopen(persistFileName.c_str(), "w+");

    if (dsFile == nullptr) {
        fprintf(stderr, "Error opening file: %s. Error code is: %i\n", persistFileName.c_str(), errno);
        return errno;
    }

    // Write dataset to file
    numCharsWritten = fprintf(dsFile, "%s", dataSetBuffer.c_str());

    if (numCharsWritten < 0) {
        fprintf(stderr, "Error writing dataset. Error code is: %i\n", ferror(dsFile));
    }

    // Close the file
    fclose(dsFile);

    return numCharsWritten;

}