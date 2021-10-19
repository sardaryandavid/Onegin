#include "sort.h"
#include <cstring>
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

const int DIFF = 'a' - 'A';

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
        while(!isGoodSymbol(*firstString) && *firstString != '\0') {
            firstString++;
        }

        while(!isGoodSymbol(*secondString) && *secondString != '\0') {
            secondString++;
        }

        if (tolower(*firstString) != tolower(*secondString)) {   // TODO
            return tolower(*firstString) - tolower(*secondString);
        }

        ++firstString;
        ++secondString;
    }

    return strlen(firstString) - strlen(secondString);
}

int myReverseStrcmp(char* firstString, char* secondString)
{

    int lenOfFirstString = strlen(firstString);
    int lenOfSecondString = strlen(secondString);

    char* str1 = firstString + lenOfFirstString - 1;
    char* str2 = secondString + lenOfSecondString - 1;

    while(str1 != firstString && str2 != secondString) {
        while(!isGoodSymbol(*str1) && *str1 != ' ' && str1 > firstString) {
            --str1;
        }

        while(!isGoodSymbol(*str2) && *str2 != ' ' &&str2 > secondString) {
            --str2;
        }

        if (tolower(*str1) != tolower(*str2)) {
            return tolower(*str1) - tolower(*str2);
        }

        --str1;
        --str2;
    }


    return lenOfFirstString - lenOfSecondString;
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
        if (str[j] == '\n') {
            str[j] = '\0';
            arrayOfptrOnStrings[currentLine] = str + j + 1;
            ++currentLine;
        }
    }

}

void fillArrayOfPtrOnMyStr(struct myString* arrayOfPtrOnMyStr, char** arrayOfPtrOnStrings, size_t nLines) {
     for(int index = 0; index < nLines - 1; ++index) {
        arrayOfPtrOnMyStr[index].ptrOnStr = *(arrayOfPtrOnStrings + index);
        arrayOfPtrOnMyStr[index].sizeOfStr = strlen(*(arrayOfPtrOnStrings + index));
    }

}

int isGoodSymbol(const char symbol) {
    return (('A' <= symbol && symbol  <= 'Z') || ('a' <= symbol && symbol <= 'z'));
}
