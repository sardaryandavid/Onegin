#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <cstddef>

struct myString {
    char* ptrOnStr;
    size_t sizeOfStr;
};

int myStrcmpForQsort(const void* str1, const void* str2);
int myStrcmp(const char* firstString, const char* secondString);

int myReverseStrcmp(char* firstString, char* secondString);
int myReverseStrcmpForQsort(const void* firstString, const void* secondString);

void fillArrayOfPtrOnStrings(char** arrayOfptrOnStrings, char* str, const size_t fileSize);
void fillArrayOfPtrOnMyStr(struct myString* arrayOfPtrOnMyStr, char** arrayOfptrOnStrings, size_t nLines);

int symbolAmount(char* str, const size_t fileSize, const char symbol);
int isGoodSymbol(const char symbol);

#endif // SORT_H_INCLUDED
