#include <iostream>
#include <cstdio>
#include <cstring>

#include <cstdlib>

#include <assert.h>

#define TESTS

void printText(char** arrayOfptrOnStrings, const int linesNumber);
char* readText(FILE* text);

int sizeOfFile(FILE* text);
int linesNumber(char* str, const size_t fileSize);

void fillArray(char** arrayOfptrOnStrings, char* str, const size_t fileSize);
void sortArray(char** arrayOfptrOnStrings, const int nLines);

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

    char* str = readText(text);

    int nLines = linesNumber(str, fileSize);

    char** arrayOfptrOnStrings = (char**) calloc (nLines, sizeof(char *));

    fillArray(arrayOfptrOnStrings, str, fileSize);

    printText(arrayOfptrOnStrings, nLines);

    //sortArray(arrayOfptrOnStrings, nLines);
    qsort(arrayOfptrOnStrings, fileSize, sizeof(char*), myStrcmp);

    printf("\n\n\n");
    printText(arrayOfptrOnStrings, nLines);
}

void printText(char** arrayOfptrOnStrings, int linesNumber) {
    for(int testIndex = 0; testIndex < linesNumber; ++testIndex) {
        if (arrayOfptrOnStrings[testIndex] != nullptr) {
            printf("%s\n", arrayOfptrOnStrings[testIndex]);
        }
    }
}

char* readText(FILE* text) {

     if(text == NULL) {
        printf("Error, can`t find the file");
        exit(0);
    }

    size_t fileSize = sizeOfFile(text);

    char* str = (char*) calloc(fileSize, sizeof(char));

    if (str == NULL) {
        printf("Error. This text is too big");
        exit(1);
    }

    fread(str, sizeof(char), fileSize, text);

    return str;
}

int sizeOfFile(FILE* text) {
    fseek(text, 0 , SEEK_END);
    long long fileSize = ftell(text);
    rewind (text);

    return fileSize;
}

int linesNumber(char* str, size_t fileSize) {
    int linesNumber = 0;
    for(int i = 0; i < fileSize; ++i) {
        if(str[i] == '\n') {
            ++linesNumber;
        }
    }

    return linesNumber;
}

void fillArray(char** arrayOfptrOnStrings, char* str, size_t fileSize) {
    arrayOfptrOnStrings[0] = str;

    int currentLine = 1;

    for(int j = 0; j < fileSize; ++j) {
        if(str[j] == '\n') {
            ++currentLine;
            str[j] = '\0';
            if(str + j + 1 != nullptr) {
                arrayOfptrOnStrings[currentLine] = str + j + 1;
            }
        }
    }

}

void sortArray(char** arrayOfptrOnStrings, int nLines) {
    for(int firstIndex = nLines - 1; firstIndex > 0; --firstIndex)
        for(int secondIndex = 0; secondIndex < firstIndex; ++secondIndex) {
            if(arrayOfptrOnStrings[secondIndex] != nullptr && arrayOfptrOnStrings[firstIndex] != nullptr  && arrayOfptrOnStrings[secondIndex+1] != nullptr) {
                if (strcmp(arrayOfptrOnStrings[secondIndex], arrayOfptrOnStrings[secondIndex + 1]) > 0) {
                    char* tmp = arrayOfptrOnStrings[secondIndex];
                    arrayOfptrOnStrings[secondIndex] = arrayOfptrOnStrings[secondIndex + 1];
                    arrayOfptrOnStrings[secondIndex + 1] = tmp;
                }
            }
        }
}

int myStrcmp(const void* str1, const void* str2) {
    strcmp((char*)str1, (char*)str2);
    return 1;
}
