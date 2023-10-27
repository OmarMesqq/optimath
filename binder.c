#include <stdio.h>
#include "custom_vector.h"

extern OptiVector* create_vector();
extern void push_back(OptiVector*, int);
extern int at(OptiVector*, size_t);
extern void swap_elements(OptiVector*, size_t, size_t);
extern void delete_vector(OptiVector*);

int main() {
    OptiVector* vec = create_vector();
    push_back(vec, 1);
    push_back(vec, 2);
    push_back(vec, 3);
    
    printf("Element at index 1: %d\n", at(vec, 1));
    
    swap_elements(vec, 0, 1);
    printf("Element at index 0 after swap: %d\n", at(vec, 0));
    
    delete_vector(vec);
    return 0;
}
