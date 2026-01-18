#include <iostream>

/*
============================================================
FUNCTION OVERLOADING (CORE CONCEPT)
============================================================

Function overloading allows multiple functions to share
the SAME NAME as long as their PARAMETER TYPES differ.

- Resolution happens at COMPILE TIME
- The compiler picks the BEST MATCH based on argument types
- Return type alone is NOT enough to overload

This is called:
    "compile-time polymorphism"
*/

/*----------------------------------------------------------
1) BASIC OVERLOADING: int vs double
----------------------------------------------------------*/

// Overload for int
int add(int a, int b) {
    std::cout << "[int overload] result = " << (a + b) << '\n';
    return a + b;
}

// Overload for double
double add(double a, double b) {
    std::cout << "[double overload] result = " << (a + b) << '\n';
    return a + b;
}

/*----------------------------------------------------------
2) POINTER OVERLOADING
----------------------------------------------------------*/

// Value overload
void print(int x) {
    std::cout << "[value overload] x = " << x << '\n';
}

// Pointer overload
void print(const int* p) {
    if (p) {
        std::cout << "[pointer overload] *p = " << *p << '\n';
    } else {
        std::cout << "[pointer overload] nullptr\n";
    }
}

/*----------------------------------------------------------
3) CONST REFERENCE OVERLOADING
----------------------------------------------------------*/

// Non-const reference overload
void show(int& x) {
    std::cout << "[non-const ref overload]\n";
}

// Const reference overload
void show(const int& x) {
    std::cout << "[const ref overload]\n";
}

/*----------------------------------------------------------
4) POINTER + CONST OVERLOADING
----------------------------------------------------------*/

// Pointer to non-const
void inspect(int* p) {
    std::cout << "[modifiable pointer]\n";
}

// Pointer to const
void inspect(const int* p) {
    std::cout << "[read-only pointer]\n";
}

/*----------------------------------------------------------
MAIN
----------------------------------------------------------*/

int main() {
    std::cout << "=== BASIC OVERLOADING ===\n";
    add(3, 5);            // int overload
    add(3.5, 5.7);        // double overload

    std::cout << "\n=== POINTER OVERLOADING ===\n";
    int x = 42;
    print(x);             // value overload
    print(&x);            // pointer overload
    print(nullptr);       // pointer overload

    std::cout << "\n=== CONST REFERENCE OVERLOADING ===\n";
    int a = 10;
    const int b = 20;

    show(a);              // non-const preferred
    show(b);              // const required
    show(30);             // const (temporary)

    std::cout << "\n=== POINTER + CONST OVERLOADING ===\n";
    inspect(&a);          // non-const pointer preferred
    inspect(&b);          // const pointer required

    return 0;
}

/*
============================================================
OVERLOADING RULES (MEMORIZE THESE)
============================================================

1) Overloads must differ by PARAMETER TYPES
2) Return type alone is NOT sufficient
3) Exact matches are preferred
4) Non-const is preferred over const if both are viable
5) const references can bind to temporaries
6) Pointers and values are different types

In short:
---------
The compiler chooses the "most specific and safest match"
at compile time.

============================================================
COMMON INTERVIEW TRAPS
============================================================

❌ Overloading only by return type
❌ Expecting runtime dispatch (this is NOT virtual)
❌ Forgetting const correctness
❌ Creating ambiguous overloads

============================================================
ONE-SENTENCE TAKEAWAY
============================================================

Function overloading lets you express ONE CONCEPT with
multiple type-specific implementations, resolved at
compile time.
============================================================
*/
