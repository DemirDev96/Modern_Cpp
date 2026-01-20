#include <stdio.h>
#include <stdlib.h>

int main(void) {

    /*
        ============================
        C-STYLE MEMORY ALLOCATION
        ============================

        malloc:
        - Allocates RAW memory
        - Memory is UNINITIALIZED (contains garbage)
        - Takes ONE argument: total number of bytes
        - Returns void* (implicitly convertible in C)
    */
    int *pointer = malloc(sizeof(int));   // allocate memory for 1 int
    if (!pointer) return 1;               // always check allocation success

    *pointer = 5;                          // safe: memory is allocated
    printf("malloc value: %d\n", *pointer);

    free(pointer);                         // releases the allocated memory
    pointer = NULL;                        // defensive: avoid dangling pointer

    /*
        free(NULL) is SAFE in both C and C++.
        It does nothing, but calling it is unnecessary.
    */
    free(pointer);                         // does nothing


    /*
        ============================
        calloc vs malloc
        ============================

        calloc:
        - Allocates memory for N elements of size S
        - Memory is ZERO-INITIALIZED
        - Takes TWO arguments: (count, size)
    */
    int *pointer2 = calloc(1, sizeof(int)); // allocate & zero 1 int
    if (!pointer2) return 1;

    /*
        At this point:
        *pointer2 == 0 (guaranteed by calloc)
    */
    *pointer2 = 5;                          // overwrite zero with 5
    printf("calloc value: %d\n", *pointer2);

    free(pointer2);                         // release memory
    pointer2 = NULL;                       // prevent dangling pointer
    free(pointer2);                         // safe but unnecessary


    /*
        ============================
        IMPORTANT C vs C++ NOTE
        ============================

        This code is VALID C.

        In C++:
        - malloc/calloc do NOT call constructors
        - free does NOT call destructors
        - Using them with C++ objects causes undefined behavior

        C++ prefers:
        - new / delete
        - std::vector
        - std::unique_ptr
        - RAII (automatic resource management)
    */

    return 0;
}
