#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct LinkedList{
  struct Node *head;
  int len;
} ll_t;

ll_t *CreateLL();
void AddNode(ll_t *ll, int n);
void DeleteAllNodes(ll_t *ll);
void AppendLL(ll_t *ll, ll_t *second);

void DisplayNodes(ll_t *ll);
int CountNodes(ll_t *ll);
int SumNodes(ll_t *ll);
int MaxNode(ll_t *ll);
int MinNode(ll_t *ll);
struct Node *Search(ll_t *ll, int key);
struct Node *iSearch(ll_t *ll, int key);
void reverseLLSlidingPointers(ll_t *ll);


void insertNode(ll_t *ll, int index, int val);
void insertSorted(ll_t *ll, int val);
void DeleteNode(ll_t *ll, int val);
bool isSortedLL(ll_t *ll);
void DeleteDublicates(ll_t *ll);
void MergeLL(ll_t *ll,ll_t *second); //TODO:need implementation;


#endif // !LinkedList_h
