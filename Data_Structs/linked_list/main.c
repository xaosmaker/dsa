
#include "linked_list.h"
#include <stddef.h>
#include <stdio.h>

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
  ll = ll_destroy(ll);
  last = NULL;
  ll = ll_add_head(ll, 3);
  ll = ll_destroy(ll);
  ll = ll_destroy(ll);
  printf("ll len: %d\n", ll_count(ll));

  return 0;
}
