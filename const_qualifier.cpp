#include <iostream>

int main() {
    /*
        BAD PRACTICE: "Magic numbers"

        - Hard-coded values like 3.14 appear multiple times.
        - Easy to mistype or change in one place but not another.
        - No meaning is attached to the number.
        - Leads to subtle bugs during maintenance.
    */

    float radius = 0.0f;
    std::cin >> radius;

    /*
        GOOD PRACTICE: Use const for named values

        - Gives the value a clear semantic meaning.
        - Guarantees it cannot be modified.
        - Checked by the compiler.
        - Scoped and type-safe.
    */
    const float PI = 3.14159f;

    float area = PI * radius * radius;
    float circumference = 2.0f * PI * radius;

    std::cout << "Area: " << area << '\n';
    std::cout << "Circumference: " << circumference << '\n';

    return 0;
}

/*
WHY const IS BETTER THAN C MACROS (#define)

C MACROS:
---------
#define PI 3.14

- No type checking (pure text substitution).
- No scope (visible everywhere after definition).
- Can cause unexpected bugs in expressions.
- Harder to debug (errors point to expanded code).
- Can break code silently.

Example problem:
#define PI 3.14
float x = PI * PI;   // expands blindly, no type safety

const VARIABLES:
----------------
const float PI = 3.14159f;

- Type-safe (compiler enforces correct usage).
- Respects scope (block, function, namespace).
- Can be debugged (has a real symbol).
- Compiler can still optimize it fully.
- Prevents accidental modification.

MODERN C++ RULE:
----------------
- Prefer const variables over #define for values.
- Use #define only for conditional compilation or platform switches.

In short:
---------
#define  = preprocessor trick (C-style, unsafe)
const   = real C++ object (safe, readable, debuggable)
*/
