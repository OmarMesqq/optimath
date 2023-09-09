#include <unistd.h> // for sbrk()

// Memory block header
struct Block {
    size_t size;
    struct Block *next;
};

static struct Block *freeList = NULL;

inline void *oalloc(size_t size) {
    struct Block *block;

    // Search free list for a block of sufficient size
    for (block = freeList; block != NULL; block = block->next) {
        if (block->size >= size) {
            return ((char *)block) + sizeof(struct Block);
        }
    }

    // If no block is found, request memory from the OS
    block = (struct Block *)sbrk(size + sizeof(struct Block));
    if (block == (void *)-1) {
        return NULL; // sbrk failed
    }

    block->size = size;

    return ((char *)block) + sizeof(struct Block);
}

inline void ofree(void *ptr) {
    struct Block *block = (struct Block *)((char *)ptr - sizeof(struct Block));
    block->next = freeList;
    freeList = block;
}

int main() {
    int *arr = (int *)oalloc(sizeof(int) * 10);
    if (arr == NULL) {
        return 1;
    }

    arr[0] = 42; // use allocated memory

    ofree(arr);

    return 0;
}

/*
TODO: implement allocation with assembly
*/