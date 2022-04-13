#include<stdio.h>


int main(void) {
    int i = 0;
    struct node *head = NULL;
    while (i < 10) {
        // `insert_first` is a function which malloc's a new node, 
        // inserts it at the head of the list, and
        // returns it.
        head = insert_first(i, head);
        i++;
    }
    free(head);
}
