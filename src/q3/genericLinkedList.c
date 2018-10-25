#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

genericListElement *createEl(void *info, size_t size, printer print) {
    
    genericListElement* e = malloc(sizeof(genericListElement));
    
    //Error in malloc
    if(e == NULL) {
        return NULL;
    }
    
    void *dataPointer = malloc(size);
    
    //Error in malloc, free up the space
    if(dataPointer == NULL) {
        free(e);
        return NULL;
    }
    
    memmove(dataPointer, info, size);
    
    e->info = dataPointer;
    e->size = size;
    e->print = print;
    e->next = NULL;
    
    return e;
    
}

int length(genericListElement *list) {
    
    genericListElement *currEle = list;
    int i = 0;
    
    while(currEle != NULL) {
        i++;
        currEle = currEle->next;
    }
    
    return printf("# of elements in the list: %d \n", i);
    
}

void push(genericListElement **list, void *info, size_t size, printer print) {
    
    genericListElement *newEle = createEl(info, size, print);
    
    newEle->next = *list;
    
    *list = newEle;
    
}

genericListElement *pop(genericListElement **list) {
    genericListElement *headEle = *list;
    
    if(headEle) {
        *list = headEle->next;
    }
    
    return headEle;
}

void enqueue(genericListElement **list, void *info, size_t size, printer print) {
    genericListElement *newEle = createEl(info, size, print);
    
    newEle->next = *list;
    
    *list = newEle;
}

genericListElement *dequeue(genericListElement *list) {
    genericListElement *temp = list;
    
    while((temp-> next)-> next != NULL) {
        temp = temp->next;
    }
    
    genericListElement *tailEle = temp->next;
    temp->next = NULL;
    
    return tailEle;
    
}

void traverse(genericListElement *start) {
    genericListElement *currEle = start;
    
    while(currEle != NULL) {
        currEle->print(currEle->info);
        currEle = currEle->next;
    }
    
}

genericListElement* insertAfter(genericListElement* e, void *info, size_t size, printer print) {
    
    genericListElement* newEle = createEl(info, size, print);
    
    genericListElement* next = e->next;
    
    newEle->next = next;
    e->next = newEle;
    
    return newEle;
    
}

void deleteAfter(genericListElement* afterEle) {
    genericListElement* deleteEle = afterEle->next;
    genericListElement* newNextEle = deleteEle->next;
    afterEle->next = newNextEle;
    
    free(deleteEle->info);
    free(deleteEle);
}
