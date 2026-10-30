
#include "linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //
  struct ll_node *ll = NULL;
  struct ll_node *last = NULL;
  ll = ll_add_head(ll, 1);
  ll = ll_add_head(ll, 2);
  ll = ll_add_head(ll, 3);

  last = ll_add_tail(ll, 0);

  printf("%d\n", ll->data);
  printf("%d\n", ll->next->data);
  printf("%d\n", ll->next->next->data);
  printf("%d\n", ll->next->next->next->data);
  printf("%d\n\n", ll->next->next->next->next->data);
  ll_display(ll);
  printf("\n%d\n", last->data);
  printf("%d\n", last->prev->data);
  printf("%d\n", last->prev->prev->data);
  printf("%d\n", last->prev->prev->prev->data);
  printf("%d\n", last->prev->prev->prev->prev->data);
  printf("ll len: %d\n", ll_count(ll));
  printf("found 3 is: %d\n", ll_find(ll, 3)->data);
  printf("found not exist is: %p\n", (void *)ll_find(ll, 5));
  printf("peek head %d\n", ll_peek_head(ll)->data);
  printf("peek tail %d\n", ll_peek_tail(ll)->data);
  ll_insert(ll, 5, 1);
  ll_insert(ll, -1, 5);
  last = NULL;
  ll_display(ll);
  last = ll_pop_tail(ll);
  ll_display(ll);
  printf("last: %d\n", last->data);
  last = ll_destroy(last);
  ll_display(ll);
  printf("reverse\n");
  ll_display(ll);
  ll = ll_destroy(ll);
  last = NULL;
  ll = ll_add_head(ll, 3);
  ll = ll_destroy(ll);
  ll = ll_destroy(ll);
  printf("ll len: %d\n", ll_count(ll));

  return 0;
}
