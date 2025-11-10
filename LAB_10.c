//Write a C program (name it "filecopy. c")  that copies the contents of one file to a destination file. 
// This program will read data from one file and copy them to another. 
// The first input that the program will need is the names of the two files: input file ("input.txt") and output file ("output.txt"). 
// Once the two file names have been obtained, the program must open the input file and create and open the output file.
#include <stdio.h>
#include <stdlib.h>

int main() {
    char inputFileName[100], outputFileName[100];
    FILE *inputFile, *outputFile;
    int ch;

    // Get the names of the two files
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open the input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file for writing (creates the file if it doesn't exist)
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening/creating output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Copy contents from input to output file character by character
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }

    printf("File copied successfully.\n");

    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
