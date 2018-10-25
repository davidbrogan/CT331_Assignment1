#include <stdio.h>

int main(int arg, char* argc[]){
    
    int a;
    int *b;
    long c;
    double *d;
    char **e;
    
    int sizea = sizeof(a);
    int sizeb = sizeof(b);
    int sizec = sizeof(c);
    int sized = sizeof(d);
    int sizee = sizeof(e);
    
    printf("Size of int: %lu \nSize of int*: %lu\nSize of long: %lu\nSize of dounble*: %lu\nSize of char**: %lu\n", sizeof(a),sizeof(b),sizeof(c),sizeof(d),sizeof(e));
    return 0;
}
