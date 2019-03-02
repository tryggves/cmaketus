//
// Created by tryggve on 3/2/19.
//
// Simple file writer class representing a dataset.
// Functionality
//
//

#ifndef CMAKETUT_DATASET_H
#define CMAKETUT_DATASET_H

#include <string>

class DataSet {
private:
    std::string dataSetBuffer;         // Dataset buffer - simple example a string array
    // char dataSetBuffer[256];        // Dataset buffer - simple example a string array

public:
    DataSet();                      // Default constructor
    void printDataset();            // Create a nice output of the dataset.
};


#endif //CMAKETUT_DATASET_H
