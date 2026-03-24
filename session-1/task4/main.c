
#include <stdio.h>
#include <stdlib.h>

#include "node_structures.h"
#include "node.h"
#include "queue_structures.h"
#include "queue.h"

int main( void ) {

    // create an empty queue
    Queue *queue = createQueue();
    
    Data d1 = { .value = 10 };   
    Data d2 = { .value = 20 };
    Data d3 = { .value = 30 };
    
    join(queue, &d1);
    join(queue, &d2);
    join(queue, &d3);
    
    // test join 
    // - use traverseI() to display the nodes
    // - which pointer do you pass to traverseI(): front or back?
    traverseI(queue->front);
    
    // test leave 
    // - take care to free detached memory
    leave(queue);
    leave(queue);

    traverseI(queue->front);
    // free queue memory
    freeNodes( queue->front );
    // free queue
    free(queue);

    return 0;
}
