#include <iostream>

int addUp(int x, int y) {
    return x + y;
}

int main() {
    /*
        auto: type is deduced from the initializer.

        Good for:
        - avoiding repetition (especially long types)
        - keeping code resilient to refactors
        - making intent clearer when the type is obvious from the RHS
    */

    auto i = 10;          // int
    auto j = 5;           // int
    auto sum = i + j;     // int

    auto result = addUp(i, j); // int

    /*
        static: storage duration is the entire program lifetime.
        'y' is initialized once and keeps its value between calls (if this were in a function called multiple times).
        Note: "static auto" still deduces the type from the initializer.
    */
    static auto y = 2;    // static int

    /*
        const affects auto deduction:

        - auto drops top-level const (when copying a value)
        - auto& preserves constness (when binding a reference)
    */
    const int x = 10;

    auto var = x;         // int  (top-level const is dropped because this is a copy)
    const auto cvar = x;  // const int (you explicitly keep it const)

    auto& refToX = x;     // const int& (reference keeps constness of x)
    // auto& ref2 = 10;    // ERROR: non-const lvalue ref can't bind to rvalue (literal)
    const auto& ok = 10;  // const int& (OK: const ref can bind to a temporary)

    /*
        Braced initialization with auto:

        - auto list = {1,2,3}; deduces std::initializer_list<int>
        - This is a common "why is it not a vector?" beginner surprise.
    */
    auto list = {1, 2, 3, 4, 5}; // std::initializer_list<int>

    // Print to make the program "do something"
    std::cout << "sum=" << sum
              << " result=" << result
              << " y=" << y
              << " var=" << var
              << " x=" << x
              << " *list.begin()=" << *list.begin()
              << '\n';

    return 0;
}
