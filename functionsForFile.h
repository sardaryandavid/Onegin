#ifndef FUNCTIONSFORFILE_H_INCLUDED
#define FUNCTIONSFORFILE_H_INCLUDED

#include <cstdlib>
#include <cstdio>

void scanInputName(char* str);
void scanOutputName(char* resultSortedFileName);
int correctFileName(char* fileName);

void printTextToFile(const char* const* const arrayOfptrOnStrings, const size_t linesNumber, FILE* resultSortedFile);
char* readTextFromFile(FILE* text, char* str, const size_t fileSize);

size_t sizeOfFile(FILE* text);

int symbolAmount(const char* const str, const size_t fileSize, const char symbol);
int strIsGood(const char* str);

void fillArrayOfPtrOnStrings(char** arrayOfptrOnStrings, char* str, const size_t fileSize);

#endif // FUNCTIONSFORFILE_H_INCLUDED
