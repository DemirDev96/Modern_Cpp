#include <iostream>

int main() {

    /*
        ============================
        C++ DYNAMIC MEMORY (new/delete)
        ============================

        new:
        - Allocates memory on the heap
        - Constructs the object
        - Returns a pointer of the correct type
    */

    int* p = new int(6);      // allocate + initialize an int with value 6
    std::cout << *p << '\n';  // use the allocated object

    /*
        delete:
        - Destroys the object
        - Deallocates the memory
        - The pointer itself is NOT changed automatically
    */
    delete p;

    /*
        After delete:
        - p becomes a DANGLING POINTER
        - Dereferencing p now is UNDEFINED BEHAVIOR
        - Best practice: immediately reset it to nullptr
    */
    p = nullptr;              // safe, explicit "points to nothing"

    return 0;
}

/*
============================================================
C++ DYNAMIC MEMORY SUMMARY
============================================================

Syntax:
-------
T* ptr = new T(args);   // allocate + construct
delete ptr;             // destroy + deallocate

Rules:
------
- Every `new` must be paired with exactly ONE `delete`
- Every `new[]` must be paired with `delete[]`
- Never mix new with free
- Never mix malloc with delete
*/

/*
============================================================
malloc / calloc / realloc  (C STYLE)
============================================================

malloc:
- Is a FUNCTION (from <stdlib.h>)
- Requires size in bytes
- Allocates raw, UNINITIALIZED memory
- Does NOT call constructors
- Returns void* (implicit conversion only in C)
- Returns NULL on failure

calloc:
- Allocates memory for N elements of size S
- Memory is ZERO-initialized
- Also does NOT call constructors

realloc:
- Resizes previously allocated memory
- May move the allocation
*/

/*
============================================================
new / delete (C++ STYLE)
============================================================

new:
- Is an OPERATOR
- Size inferred from the type
- Can initialize memory
- Calls constructors
- Returns the correct pointer type
- Can be overloaded (custom allocators)
- Throws std::bad_alloc on failure (unless using nothrow)

delete:
- Calls destructors
- Releases memory
*/

/*
============================================================
WHY new IS SUPERIOR TO malloc IN C++
============================================================

- new understands TYPES
- new constructs OBJECTS
- delete runs DESTRUCTORS
- new integrates with RAII
- malloc/free work on raw memory only

IMPORTANT:
----------
In modern C++, you should RARELY use `new` directly.

Prefer:
--------
- std::vector
- std::unique_ptr
- std::shared_ptr

These eliminate entire classes of memory bugs.
*/

/*
ONE-SENTENCE TAKEAWAY:
---------------------
malloc allocates memory.
new constructs objects.

C++ is about OBJECT LIFETIMES, not raw memory.
*/
