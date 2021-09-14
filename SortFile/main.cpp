#include <iostream>
#include <cstdio>
#include <cstring>

#include <cstdlib>

#include <assert.h>

#define TESTS

void printText(char** const arrayOfptrOnStrings, const size_t linesNumber);
char* readText(FILE* text, char* str, const size_t fileSize);

int sizeOfFile(FILE* text);
int linesNumber(const char* const str, const size_t fileSize);

void fillArray(char** arrayOfptrOnStrings, char* str, const size_t fileSize);

int myStrcmp(const void* str1, const void* str2);

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
    FILE* text = fopen("text.txt" , "r");

    size_t fileSize = sizeOfFile(text);
    char* str = (char*) calloc(fileSize, sizeof(*str));
    readText(text, str, fileSize);

    size_t nLines = linesNumber(str, fileSize);
    char** arrayOfptrOnStrings = (char**) calloc (nLines, sizeof(*arrayOfptrOnStrings));
    fillArray(arrayOfptrOnStrings, str, fileSize);

    printText(arrayOfptrOnStrings, nLines); //!
    qsort(arrayOfptrOnStrings, nLines, sizeof(*arrayOfptrOnStrings), myStrcmp);
    printf("\n\n\n");
    printText(arrayOfptrOnStrings, nLines);

    free(arrayOfptrOnStrings);
    free(str);
    fclose(text);
}

void printText(char** const arrayOfptrOnStrings, const size_t linesNumber) {
    for(int testIndex = 0; testIndex < linesNumber; ++testIndex) {
        if (arrayOfptrOnStrings[testIndex] != nullptr) {
            printf("%s\n", arrayOfptrOnStrings[testIndex]);
        }
    }
}

char* readText(FILE* text, char* str, const size_t fileSize) {
     if(text == NULL) {
        printf("Error, can`t find the file");
        exit(0);
    }

    if (str == NULL) {
        printf("Error. This text is too big");
        exit(1);
    }

    fread(str, sizeof(*str), fileSize, text);

    return str;
}

int sizeOfFile(FILE* text) {
    fseek(text, 0 , SEEK_END);
    long long fileSize = ftell(text);
    rewind (text);

    return fileSize;
}

int linesNumber(const char* const str, const size_t fileSize) {
    int linesNumber = 0;

    for(int i = 0; i < fileSize; ++i) {
        if(str[i] == '\n') {
            ++linesNumber;
        }
    }

    return linesNumber;
}


void fillArray(char** arrayOfptrOnStrings, char* str, const size_t fileSize) {
    arrayOfptrOnStrings[0] = str;

    int currentLine = 1;

    for(int j = 0; j < fileSize; ++j) {
        if(str[j] == '\n') {
            str[j] = '\0';
            if(str + j + 1 != nullptr) {
                arrayOfptrOnStrings[currentLine] = str + j + 1;
            }
            ++currentLine;
        }
    }

}

int myStrcmp(const void* const str1, const void* const str2) {
    return strcmp(*(char**) str1, *(char**) str2);
}
