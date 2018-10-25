#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
 
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");
    
    //test length
    printf("Length: %d\n", length(l));
    printf("\n");
    
    //test push
    printf("Testing Push\n");
    push(&l, "new element(0)", 13);
    traverse(l);
    printf("Length: %d\n", length(l));
    printf("\n");
    
    //test pop
    printf("Testing Pop\n");
    pop(&l);
    traverse(l);
    printf("Length: %d\n", length(l));
    printf("\n");
    
    //test enqueue
    printf("Testing enqueue\n");
    enqueue(&l, "new Element (0)", 13);
    traverse(l);
    printf("Length: %d\n", length(l));
    printf("\n");
    
    //test dequeue
    printf("Testing dequeue\n");
    dequeue(l);
    traverse(l);
    printf("Length %d\n", length(l));
    printf("\n");
    
    // Test delete after
    deleteAfter(l);
    traverse(l);
    printf("\n");

    

  printf("\nTests complete.\n");
}
