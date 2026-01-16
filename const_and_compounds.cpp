#include <iostream>

// Mutates the pointed-to int.
// NOTE: pointer itself can be null, so we guard it.
void printAndSet(int* p) {
    if (!p) {
        std::cout << "printAndSet: nullptr (nothing to print)\n";
        return;
    }

    std::cout << "printAndSet: value = " << *p << '\n';
    *p = 700; // modifies the caller's variable
}

// Read-only reference: can bind to lvalues AND temporaries (like literals).
void printConstRef(const int& v) {
    std::cout << "printConstRef: value = " << v << '\n';
}

int main() {
    int x = 10;

    // const variable: cannot be modified after initialization
    const int CHUNK_SIZE = 512;

    /*
        Pointer-to-const:

        const int* p
        - You may change p to point somewhere else
        - You may NOT modify the int through p
    */
    const int* pChunk = &CHUNK_SIZE;

    // printConstRef can take a literal because it's a const reference
    printConstRef(123);

    // This function modifies x through a non-const pointer
    printAndSet(&x);

    std::cout << "main: x = " << x << '\n';

    // You can read through pointer-to-const
    std::cout << "CHUNK_SIZE via pChunk = " << *pChunk << '\n';

    return 0;
}

/*
IMPORTANT FIX TO YOUR COMMENT:

You wrote:
"when declaring a pointer to a const the ptr must be const"

Correct:
- The *pointee* is const, not the pointer.

const int* p = &CHUNK_SIZE;   // pointer to const int (pointee is const)
int* const p = &x;            // const pointer to int (pointer is const)
const int* const p = &x;      // const pointer to const int

Quick rule:
- "const" binds to what’s immediately to its left (or to the right if nothing on the left).
*/
