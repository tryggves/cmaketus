//
// Created by tryggve on 3/2/19.
//
//

#include "DataSet.h"
#include <iostream>

// Default constructor inserts so
DataSet::DataSet() {
    int numCharsInDataset;

    // Set the default name of dataset
    dsName = "dataset";
    // Append the suffix to the file name
    persistFileName = dsName+".txt";

    numCharsInDataset = readDataset();
    if (numCharsInDataset < 0) {
        // Either file not exist or fatal error in method
        // Just set the default value
        fprintf(stderr, "Setting default value for dataset.\n");
        dataSetBuffer = "Hello world!";
    }
}

// Constructor with custom specific dataset name
DataSet::DataSet(const std::string datasetName) {
    int numCharsInDataset;

    dsName = datasetName;
    persistFileName = dsName+".txt";

    numCharsInDataset = readDataset();
    if (numCharsInDataset < 0) {
        // Either file not exist or fatal error in method
        // Just set the default value
        fprintf(stderr, "Setting default value for dataset.\n");
        dataSetBuffer = "Hello world!";
    }
}


// Print out the dataset
void DataSet::printDataset() {
    std::cout << "==============================================================" << std::endl
        << "=== This is the content of the data set named: " << getDsName() << std::endl
        << dataSetBuffer << std::endl
        << "==============================================================" << std::endl;
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

// Read dataset from file.
int DataSet::readDataset() {
    // char * cstring = new char [256];        // Assume this is the max length of data set
    char * buffer;                              // Temporary buffer for dataset
    long lSize;                                 // Size of dataset
    int numCharsRead = 0;                       // Number of characters read


    // Open the persist file
    dsFile = fopen(persistFileName.c_str(), "r");

    if (dsFile == nullptr) {
        fprintf(stderr, "Error opening file: %s. Error code is: %i\n", persistFileName.c_str(), errno);
        return -1;
    }

    // Get the file size
    fseek (dsFile, 0, SEEK_END);
    lSize = ftell(dsFile);
    rewind(dsFile);

    // Allocate temporary memory to contain file content - add 1 for the terminating \0 character
    buffer = (char *) malloc(sizeof(char)*(lSize + 1));
    if (buffer == nullptr) {
        fprintf(stderr, "Memory error\n");
        return (-1);
    }

    // Read the dataset from the file
    // Trouble with the reading, suspecting terminating \0 character - try fgets()
    if (fgets(buffer, lSize+1, dsFile) == nullptr) {
        fprintf(stderr, "Reading dataset error!\n");
        return (-1);
    }

    // Create the string member holding the new string from the buffer.
    dataSetBuffer = buffer;

    return numCharsRead;
}

const std::string &DataSet::getDataSetBuffer() const {
    return dataSetBuffer;
}

void DataSet::setDataSetBuffer(const std::string dataSetBuffer) {
    DataSet::dataSetBuffer.clear();
    DataSet::dataSetBuffer = dataSetBuffer;
}

const std::string &DataSet::getDsName() const {
    return dsName;
}
