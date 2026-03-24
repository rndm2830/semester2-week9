
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"

int main( void ) {

    // create some nodes
    Node *first = createNode(createData(1));
    Node *second = createNode(createData(2));
    Node *third = createNode(createData(3));

    // link the nodes
    first->next = second;
    second->next = third;
    
    printf("Original list:\n");
    traverseI( first );

    // Add some nodes
    Node *new_first = createNode(createData(0));
    new_first->next = first;
    first = new_first;

    printf("\nAfter adding node at start:\n");
    traverseI( first );
    
    Node *current = first;
    while (current != NULL && current->data->value != 2) {
        current = current->next;
    }

    Node *last = first;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = createNode(createData(100));
    
    // print the data by following links
    traverseI( first );

    // free all node memory (using traversal)
    freeNodes( first );

    return 0;
}
