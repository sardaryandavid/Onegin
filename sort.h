#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <cstddef>

int myStrcmpForQsort(const void* str1, const void* str2);
int myStrcmp(const char* firstString, const char* secondString);
int myReverseStrcmp(const char* firstString, const char* secondString);

void fillArrayOfPtrOnStrings(char** arrayOfptrOnStrings, char* str, const size_t fileSize);

int symbolAmount(const char* const str, const size_t fileSize, const char symbol);

#endif // SORT_H_INCLUDED
