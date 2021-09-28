#include <cstdio>

#include <cstring>
#include <cstdlib>
#include "sort.h"
#include "functionsForFile.h"

#include <assert.h>

#define TESTS

void launchProgram();

struct myString {
    char* str = nullptr;
    int lengthOfStr = 0;
};


struct textFile {
    FILE* text = nullptr;
    size_t fileSize = 0;
    size_t nLines = 0;
};

int main()
{
    #ifndef TESTS
        launchAllUnitTests();
    #else
        launchProgram();
    #endif // TESTS

    return 0;
}

void launchProgram() {
    char* fileName = (char*) calloc(FILENAME_MAX, sizeof(*fileName));
    scanInputName(fileName);
    FILE* text = fopen(fileName, "r");

    char* resultSortedFileName = (char*) calloc(FILENAME_MAX, sizeof(*fileName));
    scanOutputName(resultSortedFileName);
    FILE* resultSortedFile = fopen(resultSortedFileName, "w");

    size_t fileSize = sizeOfFile(text);
    char* str = (char*) calloc(fileSize, sizeof(*str));
    readTextFromFile(text, str, fileSize);


    size_t nLines = symbolAmount(str, fileSize, '\n');
    char** arrayOfptrOnStrings = (char**) calloc (nLines, sizeof(*arrayOfptrOnStrings));
    fillArrayOfPtrOnStrings(arrayOfptrOnStrings, str, fileSize);

    printTextToFile(arrayOfptrOnStrings, nLines, resultSortedFile);
    qsort(arrayOfptrOnStrings, nLines, sizeof(*arrayOfptrOnStrings), myReverseStrcmpForQsort);
    printf("\n");
    printTextToFile(arrayOfptrOnStrings, nLines, resultSortedFile);

    free(arrayOfptrOnStrings);
    free(str);
    free(fileName);
    free(resultSortedFileName);

    fclose(text);
}
