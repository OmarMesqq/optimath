#include <stdio.h>

// Declare the extern functions
extern CustomVector* create_vector();
extern void push_back(CustomVector*, int);
extern int at(CustomVector*, size_t);
extern void swap_elements(CustomVector*, size_t, size_t);
extern void delete_vector(CustomVector*);

int main() {
    CustomVector* vec = create_vector();
    push_back(vec, 1);
    push_back(vec, 2);
    push_back(vec, 3);
    
    printf("Element at index 1: %d\n", at(vec, 1));
    
    swap_elements(vec, 0, 1);
    printf("Element at index 0 after swap: %d\n", at(vec, 0));
    
    delete_vector(vec);
    return 0;
}

