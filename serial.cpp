#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

#define KERNEL_SIZE 3
#define ROW_SIZE 253
#define COLUMN_SIZE 320


int main(int argc, char *argv[]) {
    // Check if there are 3 arguments for input image file, kernel file, and the output file
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <input_image_file> <kernel_file> <output_image_file>" << endl;
        exit(EXIT_FAILURE);
    }
    
    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        cout << "Can't open image file ...." << endl;
        exit(EXIT_FAILURE);
    }
    
    FILE* kernelFile = fopen(argv[2], "r");
    if (kernelFile == NULL) {
        cout << "Can't open kernel file ...." << endl;
        exit(EXIT_FAILURE);
    }

    FILE* outputFile = fopen(argv[3], "w");
    if (outputFile == NULL) {
        cout << "Can't open output file ...." << endl;
        exit(EXIT_FAILURE);
    }
    
    int kernal[KERNEL_SIZE][KERNEL_SIZE];
    int myImage[ROW_SIZE][COLUMN_SIZE];
    int resultImage[ROW_SIZE - KERNEL_SIZE + 1][COLUMN_SIZE - KERNEL_SIZE + 1];

    // Read and print kernel
    cout << "Kernel:" << endl;
    for (int i = 0; i < KERNEL_SIZE; i++) {
        for (int j = 0; j < KERNEL_SIZE; j++) {
             fscanf(kernelFile, "%d", &kernal[i][j]);
             cout << kernal[i][j] << " ";
           }
           cout << endl;
       }
    cout << endl;
    
    //Read my Image
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COLUMN_SIZE; j++) {
             fscanf(inputFile, "%d", &myImage[i][j]);
            // cout << myImage[i][j] << " ";
           }
          // cout << endl;
       }
       
    clock_t start_time = clock(); // Record the start time of the function filterImage
    int sum;

    for (int i = 0; i < (ROW_SIZE - KERNEL_SIZE + 1); i++) {
        for (int j = 0; j < (COLUMN_SIZE - KERNEL_SIZE + 1); j++) {
            sum = 0;
            for (int m = 0; m < KERNEL_SIZE; m++) {
                for (int n = 0; n < KERNEL_SIZE; n++) {
                    sum += myImage[i + m][j + n] * kernal[m][n];
                }
            }
            resultImage[i][j] = sum;
        }
    }
	
	clock_t end_time = clock();  // Record the end time of the function filterImage
	
	//Time taken for execution time 
	double execution_time = ((double) (end_time - start_time) / (double) CLOCKS_PER_SEC) * 10;
	cout << "Execution time in seconds: " << execution_time << endl;  
	
	//Write result to the output file
	for (int i = 0; i < ROW_SIZE - KERNEL_SIZE + 1; i++) {
	   for (int j = 0; j < COLUMN_SIZE - KERNEL_SIZE + 1; j++) {
		       // Write to the text file
	           fprintf(outputFile, "%d ", resultImage[i][j]);
	    }
		    fprintf(outputFile, "\n");
	}
		
    fclose(outputFile);
    

    return 0;
}

