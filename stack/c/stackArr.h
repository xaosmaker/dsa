
#ifndef STACK_ARR_H
#define STACK_ARR_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct Stack {
  int top;
  int *S;
  int size;
};


struct Stack *createStack(int size);
bool isEmpty(struct Stack *s);
bool isFull(struct Stack *s);
void push(struct Stack *s, int val);
int peek(struct Stack *s, int index);
int peekTop(struct Stack *s);

int pop(struct Stack *s);

#endif // STACK_ARR_H
