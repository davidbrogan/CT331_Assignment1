#include <stdio.h>
#include "genericLinkedList.h"

    
void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

void printDouble(void * data)
{
	printf("%f\n", *(double*)data);
}

void printInt(void* data) {
	printf("%d\n", *(int*)data);
}

void printStr(void* data) {
	printf("%s\n", (char*)data);
}


void runTests(){
    printf("Tests running...\n");
    
    char c = 'C';
    
    genericListElement *ele = createEl(&c, sizeof(char), &printChar);
    
    traverse(ele);
    
    length(ele);
    
    char word[] = "David";
    genericListElement *ele2 = insertAfter(ele, &word, sizeof(word), &printStr);
    
    traverse(ele);
    
    length(ele);
    
    int a = 19;
    insertAfter(ele2, &a, sizeof(a), &printInt);
    
    traverse(ele);
    length(ele);
    
    double b = 32.45;
    insertAfter(ele2, &b, sizeof(b), &printDouble);
    
    traverse(ele);
    length(ele);
    
    printf("\n\nTests complete.\n");

}
