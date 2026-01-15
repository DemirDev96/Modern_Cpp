#include <iostream>

int main() {
    std::cout << "=== Pointers & References: Quick Lab ===\n\n";

    int x = 10;

    // &x = "address-of x" (where x lives in memory)
    std::cout << "x value:      " << x << '\n';
    std::cout << "&x address:   " << static_cast<const void*>(&x) << "\n\n";

    // ptr holds the address of x (same numeric address as &x)
    int* ptr = &x;

    std::cout << "ptr value:    " << static_cast<const void*>(ptr) << "  (address stored in ptr)\n";
    std::cout << "&ptr address: " << static_cast<const void*>(&ptr) << "  (where the pointer variable lives)\n\n";

    if (ptr == &x) {
        std::cout << "ptr == &x ✅  (ptr points to x)\n\n";
    }

    // *ptr = "dereference" (access the object being pointed to)
    std::cout << "*ptr value:   " << *ptr << "  (same as x)\n";

    // Writing through the pointer modifies x
    *ptr = 5;

    std::cout << "After *ptr = 5:\n";
    std::cout << "x value:      " << x << '\n';
    std::cout << "*ptr value:   " << *ptr << "\n\n";

    // Copy the pointed-to value into a new variable (this is a COPY, not "shared")
    int y = *ptr;
    std::cout << "y value (copy of *ptr): " << y << "\n\n";

    // nullptr (C++11): a dedicated "no object" pointer value
    int* maybe = nullptr;

    std::cout << "maybe pointer: " << static_cast<const void*>(maybe) << "  (nullptr)\n";

    // Never dereference nullptr. That's undefined behavior.
    if (maybe != nullptr) {
        std::cout << "*maybe: " << *maybe << '\n';
    } else {
        std::cout << "Not dereferencing 'maybe' because it's nullptr.\n";
    }

    // void* is for "typeless address storage" (e.g., low-level APIs).
    // You can store addresses in it, compare it, pass it around...
    // But you cannot dereference void* directly.
    void* raw = &x;
    std::cout << "\nraw (void*) points to: " << raw << " (address of x)\n";

    // If you KNOW the real type, cast back before dereferencing:
    std::cout << "*static_cast<int*>(raw): " << *static_cast<int*>(raw) << '\n';

    return 0;
}
