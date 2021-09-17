#include "sort.h"
#include <cstring>

int myStrcmpForQsort(const void* const str1, const void* const str2) {
    return myStrcmp(*(char**) str1, *(char**) str2);
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

int myReverseStrcmp(const char* firstString, const char* secondString) {
    int index = 0;

    while(firstString[index++] != '\0' && secondString[index++] != '0') {
        ;
    }

    for( ; index >= 0; --index) {
         if(firstString[index] != secondString[index]) {
            return firstString[index] - secondString[index];
        }
    }
}
