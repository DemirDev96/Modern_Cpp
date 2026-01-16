#include <iostream>

// Swap copies only (caller unchanged)
void swapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// Swap through pointers (caller changed)
void swapByPointer(int* x, int* y) {
    if (!x || !y) return;          // safety: avoid dereferencing null
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Swap through references (caller changed)
void swapByReference(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Print the ADDRESS stored in a pointer (or say it's null)
void printPointer(const int* p) {
    if (p) {
        std::cout << "pointer holds address: " << static_cast<const void*>(p) << '\n';
    } else {
        std::cout << "pointer is nullptr\n";
    }
}

// Print the VALUE via reference
void printValue(const int& v) {
    std::cout << "value: " << v << '\n';
}

int main() {
    int a = 50, b = 10;

    swapByValue(a, b);
    std::cout << "After swapByValue:     a=" << a << " b=" << b << '\n';   // 50 10

    swapByPointer(&a, &b);
    std::cout << "After swapByPointer:   a=" << a << " b=" << b << '\n';   // 10 50

    swapByReference(a, b);
    std::cout << "After swapByReference: a=" << a << " b=" << b << '\n';   // 50 10

    printPointer(nullptr);

    int x = 5;
    printValue(x);

    return 0;
}

/*
DIFFERENCES: REFERENCES vs POINTERS

REFERENCES (T&):
- Must be initialized.
- Cannot be null.
- Cannot be reseated (always refers to the same object).
- Used like a normal variable (no * to access).
- Conceptually an alias (another name for the same object).

POINTERS (T*):
- Can be nullptr.
- Can be reassigned to point elsewhere.
- Must be dereferenced (*p) to access the object.
- The pointer variable has its own storage (its own address).

Rule of thumb:
- Use references when a valid object is required.
- Use pointers when “no object” is a valid state (optional) or reseating is needed.
*/
