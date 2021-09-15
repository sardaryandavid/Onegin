#include <iostream>
#include <cstdio>
#include <cstring>

#include <cstdlib>

#include <assert.h>

#define TESTS

const int MAXNAMEOFFILE = 15;

void scanfFileName(char* str);
void scanfSortFileName(char* resultSortedFileName);
void printTextFromFile(const char* const* const arrayOfptrOnStrings, const size_t linesNumber, FILE* resultSortedFile);
char* readTextFromFile(FILE* text, char* str, const size_t fileSize);

size_t sizeOfFile(FILE* text);
int symbolAmount(const char* const str, const size_t fileSize, const char symbol);

void fillArrayOfPtrOnStrings(char** arrayOfptrOnStrings, char* str, const size_t fileSize);

int myStrcmpForQsort(const void* str1, const void* str2);
int myStrcmp(const char* firstString, const char* secondString);

void launchProgram();

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
    char* fileName = (char*) calloc(MAXNAMEOFFILE, sizeof(*fileName));
    scanfFileName(fileName);

    FILE* text = fopen(fileName, "r");

    char* resultSortedFileName = (char*) calloc(MAXNAMEOFFILE, sizeof(*fileName));
    scanfSortFileName(resultSortedFileName);

    FILE* resultSortedFile = fopen(resultSortedFileName, "w");

    size_t fileSize = sizeOfFile(text);
    char* str = (char*) calloc(fileSize, sizeof(*str));
    readTextFromFile(text, str, fileSize);

    size_t nLines = symbolAmount(str, fileSize, '\n');
    char** arrayOfptrOnStrings = (char**) calloc (nLines, sizeof(*arrayOfptrOnStrings));
    fillArrayOfPtrOnStrings(arrayOfptrOnStrings, str, fileSize);

    printTextFromFile(arrayOfptrOnStrings, nLines, resultSortedFile); //!
    qsort(arrayOfptrOnStrings, nLines, sizeof(*arrayOfptrOnStrings), myStrcmpForQsort);
    printf("\n\n\n");
    printTextFromFile(arrayOfptrOnStrings, nLines, resultSortedFile);

    free(arrayOfptrOnStrings);
    free(str);
    free(fileName);
    fclose(text);
}

void printTextFromFile(const char* const* const arrayOfptrOnStrings, const size_t linesNumber, FILE* resultSortedFile) {
    assert(arrayOfptrOnStrings != nullptr);
    assert(linesNumber >= 0);

    const char* emptyString = "\n";
    for(int testIndex = 0; testIndex < linesNumber; ++testIndex) {
        if (arrayOfptrOnStrings[testIndex] != nullptr) {
            fputs(arrayOfptrOnStrings[testIndex], resultSortedFile);
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
    fseek(text, 0 , SEEK_END);
    size_t fileSize = ftell(text);
    rewind (text);

    return fileSize;
}

int symbolAmount(const char* const str, const size_t fileSize, const char symbol) {
    int nSymbols = 0;

    for(int i = 0; i < fileSize; ++i) {
        if(str[i] == symbol) {
            ++nSymbols;
        }
    }

    return nSymbols;
}


void fillArrayOfPtrOnStrings(char** arrayOfptrOnStrings, char* str, const size_t fileSize) {
    arrayOfptrOnStrings[0] = str;

    int currentLine = 1;

    for(int j = 0; j < fileSize; ++j) {
        if(str[j] == '\n') {
            str[j] = '\0';
            arrayOfptrOnStrings[currentLine] = str + j + 1;
            ++currentLine;
        }
    }

}

int myStrcmpForQsort(const void* const str1, const void* const str2) {
    return myStrcmp(*(char**) str1, *(char**) str2);
}

void scanfFileName(char* str) {
    printf("Please, enter file name: \n");
    scanf("%s", str);
}

int myStrcmp(const char* firstString, const char* secondString) {
    int index = 0;

    while(firstString[index] != '\0' && secondString[index] != '\0') {
         if(firstString[index] != secondString[index]) {
            return firstString[index] - secondString[index];
        }

        ++index;
    }

    return strlen(firstString) - strlen(secondString);
}

void scanfSortFileName(char* resultSortedFileName) {
    printf("Please, enter the name ot output file: \n");
    scanf("%s", resultSortedFileName);
}
