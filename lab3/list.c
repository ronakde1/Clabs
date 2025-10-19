#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
  int total = 0;
  while (list){
    total += list -> head;
    list = list -> tail;
  }
  return total;
}

void iterate(int (*f)(int), List *list) {
  while (list){
    list -> head = f(list -> head);
    list = list -> tail;
  }
  /* TODO */
}

void print_list(List *list) { 
  while (list){
    printf("%d ",list -> head);
    list = list -> tail;
  }
  printf("\n");
  /* TODO */
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) { 
  if (list1 == NULL) {return list2;}
  if (list2 == NULL) {return list1;}
  if (list1 -> head < list2-> head){
    return cons(list1-> head, merge(list1->tail, list2));
  } else{
    return cons(list2-> head, merge(list1, list2->tail));
  }
}

void split(List *list, List **list1, List **list2) { 
  int flag = 0;
  *list1 = NULL;
  *list2 = NULL;
  while (list){
    if (flag){
      *list1 = cons(list-> head, *list1);
    }else{
      *list2 = cons(list-> head, *list2);
    }
    flag = !flag;
    list = list-> tail;
  }
  /* TODO */
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *list_mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = list_mergesort(list1);
    list2 = list_mergesort(list2);
    return merge(list1, list2);
  }
}
