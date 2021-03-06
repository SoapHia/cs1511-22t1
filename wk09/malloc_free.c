// Tutorial 09
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

int main(void) {
    // revision on malloc: memory allocation

    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = 1;
    new_node->next = NULL;

    // What does free do?
    // frees malloc'ed memory
    
    // What is the input to free and how does it help it do what it needs to do?
    free(new_node);

    // What is a use after free error? Give an example.
    //printf("%d\n", new_node->data);

    // Why are these one of the worst causes of bugs in C programs?
    
    // What is a memory leak? What does dcc --leak-check do?
}
