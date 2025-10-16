

#include "linkedList.h"
int main(void) {
  //
  //
  printf("\n\n");
  ll_t *ll = CreateLL();
  printf("count list nodes should be %d, %d\n", ll->len, CountNodes(ll));
  DisplayNodesRec(ll->head);
  DisplayNodes(ll);
  AddNode(ll, 1);
  AddNode(ll, 2);
  AddNode(ll, 3);
  AddNode(ll, -25);
  AddNode(ll, 22);
  DisplayNodesRec(ll->head);
  DisplayNodes(ll);
  printf("count nodes should be %d, %d\n", ll->len, CountNodes(ll));
  printf("count list nodes recurcive should be %d, %d\n", ll->len,
         rCountNodes(ll->head));
  printf("sum nodes should be: %d\n", SumNodes(ll));
  printf("sum nodes recursively should be: %d\n", rSumNodes(ll->head));
  printf("max node should be: %d\n", MaxNode(ll));
  printf("recursive max node should be: %d\n", rMaxNode(ll->head));
  printf("min node should be: %d\n", MinNode(ll));
  printf("recursive min node should be: %d\n", rMinNode(ll->head));

  printf("\n\n");
  DeleteAllNodes(ll);
  free(ll);
  return 0;
}
