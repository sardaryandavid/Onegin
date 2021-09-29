#include "stack.h"

#include <cstdlib>
#include <cstring>

#include <stdio.h>
#include <assert.h>

enum keyOfMistake {nullStackPtr = -100, nullPtrOnStack, negativeSize, noMistake};

void stackConstructor(struct myStack* Stack) {
    Stack->ptrOnStack = (int*) calloc(Stack->maxSizeOfStack, sizeof(Stack->maxSizeOfStack));
    Stack->sizeOfStack = 0;

    stackAssert(Stack);
}

void stackDestructor(struct MyStack* Stack) {
    free(Stack->ptrOnStack);
}

void stackPush(struct myStack* Stack, const int value) {
    stackAssert(Stack);

    if(Stack->sizeOfStack + 1 > Stack->maxSizeOfStack) {
        printf("It is too big stack\n");
        assert(Stack->sizeOfStack + 1 < Stack->maxSizeOfStack);
    }
}

void stackAssert(struct myStack* Stack) {
    int keyOfMistake = 0;

    if((keyOfMistake = stackIsGood(Stack)) == nullStackPtr   ||
       (keyOfMistake = stackIsGood(Stack)) == nullPtrOnStack ||
       (keyOfMistake = stackIsGood(Stack)) == negativeSize) {
        stackDump(Stack, keyOfMistake);
    }
}

int stackIsGood(const struct myStack* Stack) {
    if(!Stack) {
        return nullStackPtr;
    }

    if(!Stack->ptrOnStack){
        return nullPtrOnStack;
    }

    if(Stack->sizeOfStack < 0) {
        return negativeSize;
    }

    return noMistake;
}

void stackDump (const struct myStack* Stack, int keyOfMistake) {
    switch (keyOfMistake) {
        case nullStackPtr:
            printf("key of mistake: null pointer on struct MyStack\n");
            break;
        case nullPtrOnStack:
            printf("key of mistake: null pointer on stack\n");
            break;
        case negativeSize:
            printf("key of mistake: negative size of stack\n");
            break;
    }

    printf("Pointer on stack = %p\n", Stack->ptrOnStack);
    printf("Stack size = %ld", Stack->sizeOfStack);
    exit(1);
}

void printStack(struct MyStack* Stack) {
    size_t index = 0;

//    while(index++ < Stack->sizeOfStack) {
//        printf("%d ", *((Stack->ptrOnStack) + index));
//    }

    printf("\n");
}

