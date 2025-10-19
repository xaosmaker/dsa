

#include "linkedList.h"
#include "linkedListsRecursive.h"
int main(void) {
  //
  //
  printf("\n\n");
  ll_t *ll = CreateLL();
  printf("count list nodes should be %d, %d\n", ll->len, CountNodes(ll));
  reverseLLRec(ll);
  DisplayNodesRec(ll->head);
  DisplayNodes(ll);
  insertNode(ll, -1, 1);
  reverseLLRec(ll);
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
  struct Node *p = Search(ll, 3);
  if (p) {
    printf("search address: %p, val: %d\n", p, p->data);
  }

  p = Search(ll, 125);
  if (p) {
    printf("search address: %p, val: %d\n", p, p->data);
  } else {
    printf("search address: %p\n", p);
  }

  p = rSearch(ll->head, 22);
  if (p) {
    printf("search address: %p, val: %d\n", p, p->data);
  } else {
    printf("search address: %p\n", p);
  }
  p = rSearch(ll->head, 125);
  if (p) {
    printf("search address: %p, val: %d\n", p, p->data);
  } else {
    printf("search address: %p\n", p);
  }

  p = iSearch(ll, 22);

  if (p) {
    printf("search address: %p, val: %d\n", p, p->data);
  } else {
    printf("search address: %p\n", p);
  }
  DisplayNodes(ll);

  p = irSearch(ll, 22);

  if (p) {
    printf("irSearch address: %p, val: %d\n", p, p->data);
  } else {
    printf("irSearch address: %p\n", p);
  }
  DisplayNodes(ll);

  p = irSearch(ll, -25);
  if (p) {
    printf("search address: %p, val: %d\n", p, p->data);
  } else {
    printf("search address: %p\n", p);
  }
  DisplayNodes(ll);

  p = irSearch(ll, -21);
  if (p) {
    printf("search address: %p, val: %d\n", p, p->data);
  } else {
    printf("search address: %p\n", p);
  }
  DisplayNodes(ll);

  insertNode(ll, 25, 14);
  DisplayNodes(ll);
  insertNode(ll, 0, 24);
  DisplayNodes(ll);
  insertNode(ll, 4, 34);
  DisplayNodes(ll);

  DeleteAllNodes(ll);

  DisplayNodes(ll);
  insertSorted(ll, 10);
  DisplayNodes(ll);
  insertSorted(ll, 4);
  DisplayNodes(ll);
  insertSorted(ll, 3);
  DisplayNodes(ll);

  //
  insertSorted(ll, 6);
  DisplayNodes(ll);
  //
  insertSorted(ll, 8);
  insertSorted(ll, 8);
  DisplayNodes(ll);

  insertSorted(ll, 13);
  insertSorted(ll, 0);
  insertSorted(ll, -1);
  insertSorted(ll, 5);

  insertSorted(ll, 12);
  insertSorted(ll, 9);
  DisplayNodes(ll);

  insertSorted(ll, 7);

  insertSorted(ll, 11);
  insertSorted(ll, 1);
  insertSorted(ll, 2);
  insertSorted(ll, 125);

  DeleteNode(ll, -1);
  DeleteNode(ll, 8);
  DeleteNode(ll, 125);
  DeleteNode(ll, 202);
  insertSorted(ll, 8);
  insertSorted(ll, 8);
  insertSorted(ll, 8);
  insertSorted(ll, 8);
  insertSorted(ll, 13);
  insertSorted(ll, 13);

  printf("is sorted ll: %s\n", isSortedLL(ll) ? "true" : "false");
  DisplayNodes(ll);
  DeleteDublicates(ll);

  insertSorted(ll, 0);
  insertSorted(ll, 0);
  insertSorted(ll, 0);

  DeleteDublicates(ll);
  DisplayNodes(ll);
  reverseLLSlidingPointers(ll);
  DisplayNodes(ll);
  reverseLLRec(ll);
  DisplayNodes(ll);
  ll_t *second = CreateLL();
  AddNode(second, 100);
  AddNode(second, 101);
  AddNode(second, 102);
  DisplayNodes(second);
  AppendLL(ll, second);
  DisplayNodes(ll);

  // //
  // printf("\n\n");
  //
  DeleteAllNodes(second);
  free(second);
  DeleteAllNodes(ll);
  free(ll);
  return 0;
}
