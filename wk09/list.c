// Program to do various linked list exercises
// Written by <your-name> (zID) on <date>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


struct node *create_new_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    return new;
}

/*
Q10.
When tackling a linked list exercise, it's a good idea to consider the following questions:

- What cases do I need to consider? Some of the common cases to consider are:
    Number of nodes (ie empty list, list with one node, list with many nodes)
    Location in the list (ie, at the start/middle/end of the list)
- Do I need to iterate through a linked list?
    What loop condition(s) should I use?
    How many iterators do I need?
- Do I need to malloc/free memory? - create (malloc), delete (free)
*/

// struct node {
//     int          data;
//     struct node *next;
// };

/** PRESCRIBED FUNCTIONS **/

struct node *add_last(struct node *head, int data) {
    // create the node
    struct node *new_node = create_new_node(data);

    // check if list is empty
    if (head == NULL) {
        return new_node;
    }

    // make a pointer to the head
    struct node *curr = head;

    // loop through list until we reach the last node
    while (curr->next != NULL) {
      curr = curr->next;
    }

    // curr should now be the last node in the list
    curr->next = new_node;

    // return og head
    return head;
}

struct node *delete_last(struct node *head) {
    return NULL;
}

// Implement a function copy which returns a copy of a linked list.
// list1: 1->2->X
// copy_list1: 1->2->X
struct node *copy(struct node *list) {
    // List is empty: return an empty list
    if (list == NULL) {
        return NULL;
    }
    
    // List contains 1 or more nodes
    struct node *old_curr = list;
    struct node *new_curr = NULL;
    struct node *new_prev = NULL;
    
    
    struct node *new_head = create_new_node(old_curr->data);
    new_prev = new_head;
    old_curr = old_curr->next; // 2
    
    while (old_curr != NULL) {
        new_curr = create_new_node(old_curr->data); // create the node for 2
        new_prev->next = new_curr; // connect new 1 to new 2
        
        new_prev = new_curr; // move pointer from 1->2
        old_curr = old_curr->next;
    }
    

    return new_head;
}

// Implement a function list_append which creates a new list by appending the second list to the first.
// list1: 1->2->X
// list2: 3->X
// list3: 1->2->3->X
struct node *list_append(struct node *first_list, struct node *second_list) {
    struct node *copy_first = copy(first_list); // NULL
    struct node *copy_second = copy(second_list);
    
    if (copy_first == NULL) {
        // the first list is empty!
        return copy_second;
    }
    
    // Get a pointer to the last node in first list
    struct node *curr = copy_first;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    // Join last node in first to first node in second list
    curr->next = copy_second; 

    return copy_first;
}

int identical(struct node *first_list, struct node *second_list) {
    // TODO
    return 5841;
}

struct node *set_intersection(struct node *first_list, struct node *second_list) {
    // TODO
    return NULL;
}

void print_list(struct node *head) {
  struct node *curr = head;

  while (curr != NULL) {
    printf("%d -> ", curr->data);
    curr = curr->next;
  }
  printf("X\n");
}


void free_list(struct node *head) {
  struct node *curr = head;
  struct node *prev = NULL;

  // free the previous node as we loop through the list
  while (curr != NULL) {
    if (prev != NULL) {
      free(prev);
    }
    prev = curr;
    curr = curr->next;
  }

  // free the last node.
  if (prev != NULL) {
    free(prev);
  }

}
