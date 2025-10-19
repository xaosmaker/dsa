
#include "stackArr.h"
#include <stdio.h>

int main(void) {

  struct Stack *s = createStack(3);
  printf("is stackEmpty %s\n", isEmpty(s) ? "true" : "false");
  printf("is stack full %s\n", isFull(s) ? "true" : "false");
  push(s, 10);
  push(s, 11);
  push(s, 13);
  push(s, 14);
  push(s, 15);
  printf("peek top %d\n", peekTop(s));
  printf("peek %d\n", peek(s, 0));
  printf("peek %d\n", peek(s, 1));
  printf("peek %d\n", peek(s, 2));
  printf("peek %d\n", peek(s, 5));

  printf("is stackEmpty %s\n", isEmpty(s) ? "true" : "false");
  printf("is stack full %s\n", isFull(s) ? "true" : "false");

  printf("%d\n", pop(s));
  printf("%d\n", pop(s));
  printf("%d\n", pop(s));
  printf("%d\n", pop(s));

  printf("peek %d\n", peekTop(s));
  printf("peek %d\n", peek(s, 0));
  free(s->S);
  free(s);
  return 0;
}
