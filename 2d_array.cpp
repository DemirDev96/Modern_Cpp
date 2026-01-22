#include <iostream>

void twoD() {
    // Allocate two 1D arrays (each holds 3 ints)
    // These live on the HEAP
    int* p1 = new int[3];
    int* p2 = new int[3];

    // Initialize the arrays
    for (int i = 0; i < 3; ++i) {
        p1[i] = i;        // 0 1 2
        p2[i] = i + 10;   // 10 11 12
    }

    // Allocate an array of pointers (2 rows)
    // This is NOT a 2D array — it's an array of int*
    int** pdata = new int*[2];

    // Each pointer points to a row
    pdata[0] = p1;
    pdata[1] = p2;

    // Access like a 2D array
    pdata[0][1] = 42; // modifies p1[1]

    // Print values
    for (int row = 0; row < 2; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << pdata[row][col] << ' ';
        }
        std::cout << '\n';
    }

    // ---- MEMORY CLEANUP ----
    // Order matters conceptually (children first)

    delete[] p1;     // frees first row
    delete[] p2;     // frees second row
    delete[] pdata;  // frees array of pointers itself
}
