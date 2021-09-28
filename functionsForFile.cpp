#include "functionsForFile.h"
#include <assert.h>

void scanInputName(char* str) {
    printf("Please, enter input file name: \n");
    scanf("%s", str);
}

void scanOutputName(char* resultSortedFileName) {
    printf("Please, enter the name of output file: \n");
    scanf("%s", resultSortedFileName);
}

void printTextToFile(const char* const* const arrayOfptrOnStrings, const size_t linesNumber, FILE* resultSortedFile) {
    assert(arrayOfptrOnStrings != nullptr);
    assert(linesNumber >= 0);

    const char* emptyString = "\n";
    for(size_t Index = 0; Index < linesNumber; ++Index) {
        if (*(arrayOfptrOnStrings + Index) != nullptr) {
            printf("%s\n", *(arrayOfptrOnStrings + Index));
            fputs(*(arrayOfptrOnStrings + Index), resultSortedFile);
            fputs(emptyString, resultSortedFile);
        }
    }

    fputs(emptyString, resultSortedFile);
}

char* readTextFromFile(FILE* text, char* str, const size_t fileSize) {
    assert(text != nullptr);
    assert(str != nullptr);

    fread(str, sizeof(*str), fileSize, text);

    return str;
}

size_t sizeOfFile(FILE* text) {
    assert(text != nullptr);

    fseek(text, 0 , SEEK_END);
    size_t fileSize = ftell(text);
    rewind (text);

    return fileSize;
}
