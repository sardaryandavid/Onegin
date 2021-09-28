#include "sort.h"
#include <cstring>
#include <assert.h>
#include <stdio.h>

int myStrcmpForQsort(const void* const str1, const void* const str2) {
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    return myStrcmp(*(char**) str1, *(char**) str2);
}

int myReverseStrcmpForQsort(const void* const str1, const void* const str2) {
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    return myReverseStrcmp(*(char**) str1, *(char**) str2);
}

int myStrcmp(const char* firstString, const char* secondString) {
    while(*firstString != '\0' && *secondString != '\0') {
        while(!isGoodSymbol(*firstString)) {
            firstString++;
        }

        while(!isGoodSymbol(*secondString)) {
            secondString++;
        }

        if(*firstString != *secondString) {
            return *firstString - *secondString;
        }

        ++firstString;
        ++secondString;
    }

    return strlen(firstString) - strlen(secondString);
}

int myReverseStrcmp(char* firstString, char* secondString)
{

    int sizeOfFirstString = strlen(firstString);
    int sizeOfSecondString = strlen(secondString);

    char* str1 = firstString + sizeOfFirstString;
    char* str2 = secondString + sizeOfSecondString;

    while(str1 != firstString && str2 != secondString) {

        while(!isGoodSymbol(*firstString) && ((str1 - 1) - firstString) >= 0) {
            --str1;
        }

        while(!isGoodSymbol(*secondString) && ((str2 - 1) - secondString) >= 0) {
            --str2;
        }

        if(*str1 != *str2) {
            return *str1 - *str2;
        }

        --str1;
        --str2;
    }


    return sizeOfFirstString - sizeOfSecondString;
}


int symbolAmount(char* str, const size_t fileSize, const char symbol) {
    assert(str != nullptr);

    int nSymbols = 0;

    for(size_t i = 0; i < fileSize; ++i) {
        if(*str++ == symbol) {
            ++nSymbols;
        }
    }

    return nSymbols;
}

void fillArrayOfPtrOnStrings(char** arrayOfptrOnStrings, char* str, const size_t fileSize) {
    arrayOfptrOnStrings[0] = str;

    int currentLine = 1;

    for(size_t j = 0; j < fileSize; ++j) {
        if(str[j] == '\n') {
            str[j] = '\0';
            arrayOfptrOnStrings[currentLine] = str + j + 1;
            ++currentLine;
        }
    }

}

int isGoodSymbol(char symbol) {
    return (('A' <= symbol && symbol  <= 'Z') || ('a' <= symbol && symbol <= 'z'));
}
