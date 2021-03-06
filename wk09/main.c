// Tutorial 09
// program to test list.c, list.h
#include<stdio.h>

#include "list.h"

int main(void) {
  // create empty list
  struct node *list1 = NULL;

  // add some nodes
  list1 = add_last(list1, 1);
  list1 = add_last(list1, 2);
  list1 = add_last(list1, 2);
  list1 = add_last(list1, 2);
  list1 = add_last(list1, 2);

  // create empty list
  struct node *list2 = NULL;
  // add some nodes
  list2 = add_last(list2, 3);
  // print to check
  
  print_list(list1);
  print_list(list2);

  // Test copy
  struct node *list3 = copy(list1);
  print_list(list3);
  
  // Test list append
  struct node *list4 = list_append(list1, list2);
  print_list(list4);

  free_list(list1);
  free_list(list2);
  free_list(list3);
  free_list(list4);
  return 0;
}
