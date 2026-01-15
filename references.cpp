#include <iostream>

int main() {
    std::cout << "=== References: Learning Lab ===\n\n";

    /*
        RULES OF REFERENCES (int&):

        - A reference MUST be initialized when declared.
        - The initializer is called the *referent*.
        - A reference is permanently bound to its referent.
        - A reference cannot be reseated (cannot refer to another object).
        - A reference is NOT a new object; it is an alias (another name).
    */

    int x = 10;

    // ref is an alias for x
    int& ref = x;

    std::cout << "x value:    " << x << '\n';
    std::cout << "ref value:  " << ref << "\n\n";

    // &ref and &x are the SAME address
    if (&ref == &x) {
        std::cout << "&ref == &x  ✅  (same memory location)\n";
        std::cout << "Address:    " << static_cast<const void*>(&x) << "\n\n";
    }

    // Modifying through the reference modifies x
    ref = 6;
    std::cout << "After ref = 6:\n";
    std::cout << "x:   " << x << '\n';
    std::cout << "ref: " << ref << "\n\n";

    // Modifying x also modifies ref
    x = 15;
    std::cout << "After x = 15:\n";
    std::cout << "x:   " << x << '\n';
    std::cout << "ref: " << ref << "\n\n";

    int y = 20;

    /*
        IMPORTANT:
        ref = y DOES NOT rebind the reference.

        This means:
        - ref is STILL bound to x
        - The VALUE of y is COPIED into x
    */
    ref = y;

    std::cout << "After ref = y:\n";
    std::cout << "x:   " << x << "  (x gets y's value)\n";
    std::cout << "ref: " << ref << '\n';
    std::cout << "y:   " << y  << "  (y unchanged)\n\n";

    /*
        Memory truth:
        - ref and x always refer to the same memory
        - ref never refers to y
    */

    /************************************************************
     * DIFFERENCES BETWEEN POINTERS AND REFERENCES
     ************************************************************

        POINTERS:
        ---------
        - Can be null (nullptr)
        - Can be reassigned to point elsewhere
        - Require explicit dereferencing (*ptr)
        - Are objects that store addresses
        - Have their own memory location
        - Can point to nothing (dangerous if misused)

        REFERENCES:
        -----------
        - Must be initialized immediately
        - Cannot be null
        - Cannot be reseated
        - No dereferencing syntax (used like normal variables)
        - Not separate objects (aliases)
        - Safer and clearer for function parameters

        RULE OF THUMB:
        --------------
        - Use references when "this should always refer to a valid object"
        - Use pointers when "this might be optional or change ownership"
    ************************************************************/

    return 0;
}
