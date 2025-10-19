#include "stackArr.h"
#include <limits.h>
#include <stdio.h>

struct Stack *createStack(int size) {

  struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
  if (!s) {
    printf("cannot create stack exiting the program!");
    exit(1);
  }
  s->size = size;
  s->top = -1;
  s->S = (int *)malloc(sizeof(int) * size);

  if (!s->S) {
    printf("cannot initialize the array exiting the program!");
    free(s);
    exit(1);
  }

  return s;
}

bool isEmpty(struct Stack *s) {
  //
  return s->top == -1;
}

bool isFull(struct Stack *s) {
  //
  return s->top == s->size - 1;
}

void push(struct Stack *s, int val) {
  if (!isFull(s)) {
    s->top++;
    s->S[s->top] = val;
  }
}

int peek(struct Stack *s, int index) {
  int pos = s->top - index;
  if (pos >= 0 && pos <= s->top) {
    return s->S[pos];
  }
  return INT_MIN;
}

int peekTop(struct Stack *s) {
  if (s->top != -1) {
    return s->S[s->top];
  }
  return INT_MIN;
}

int pop(struct Stack *s) {
  if (s->top != -1) {
    int top = s->S[s->top];
    s->top--;
    return top;
  }
  return INT_MIN;
}
