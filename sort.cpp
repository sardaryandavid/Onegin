#include "sort.h"
#include <cstring>
#include <assert.h>

int myStrcmpForQsort(const void* const str1, const void* const str2) {
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    return myStrcmp(*(char**) str1, *(char**) str2);
}

int myStrcmp(const char* firstString, const char* secondString) {
    assert(firstString != nullptr);
    assert(secondString != nullptr);

    int index = 0;

    while(firstString[index] != '\0' && secondString[index] != '\0') {
         if(firstString[index] != secondString[index]) {
            return firstString[index] - secondString[index];
        }

        ++index;
    }

    return strlen(firstString) - strlen(secondString);
}

int myReverseStrcmp(const char* firstString, const char* secondString) {
    int index = 0;

    while(firstString[index++] != '\0' && secondString[index++] != '0') {
        /* empty body */
    }

    for( ; index >= 0; --index) {
         if(firstString[index] != secondString[index]) {
            return firstString[index] - secondString[index];
        }
    }
}

int symbolAmount(const char* const str, const size_t fileSize, const char symbol) {
    assert(str != nullptr);

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
