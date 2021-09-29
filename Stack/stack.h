#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <cstdlib>

struct myStack {
  int* ptrOnStack = nullptr;
  size_t sizeOfStack = -1;

  const size_t maxSizeOfStack;
};

void stackConstructor(struct myStack* Stack);
void stackDestructor(struct MyStack* Stack);

void stackAssert(struct myStack* Stack);
int stackIsGood(const struct myStack* Stack);
void stackDump (const struct myStack* Stack, int keyOfMistake);

void stackPush(struct myStack* Stack, const int value);

#endif // STACK_H_INCLUDED
