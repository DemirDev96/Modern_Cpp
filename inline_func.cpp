#include <iostream>

/*
    inline FUNCTION

    - Suggests to the compiler that the function body may be expanded
      directly at the call site.
    - Primarily used today to allow multiple definitions across
      translation units (ODR rule), not for performance.
*/

inline int square(int x) {
    return x * x;
}

int main() {
    int value = 5;

    // IMPORTANT:
    // value + 5 is evaluated FIRST, then passed to square.
    int result = square(value + 5);

    std::cout << result << '\n'; // prints 100

    return 0;
}
