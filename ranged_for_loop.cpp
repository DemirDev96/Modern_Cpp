#include <iostream>

int main() {
    // Plain C-style array
    int arr[] {1,2,3,4,5,6,7,8,9};

    /*
        Range-based for:
        - Iterates over elements directly (no index needed).
        - Safer: no off-by-one, no manual increment, no end-condition mistakes.
        - Use `const auto&` when you only want to read elements and avoid copies.
          (For int it doesn't matter much, but for big types it does.)
    */
    for (const auto& x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    /*
        Range-based for over an initializer_list:
        - `{1,2,3,...}` creates a temporary std::initializer_list<int>.
        - `auto x` copies each element (fine for int).
        - If elements were big objects, you'd prefer `const auto& x`.
    */
    for (auto x : {1,2,3,4,5,6}) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}
