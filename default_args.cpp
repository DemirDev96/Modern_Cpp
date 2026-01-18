#include <iostream>

/*
    DEFAULT ARGUMENTS

    - Default values are used when the caller omits arguments.
    - They are bound at COMPILE TIME.
    - Defaults must be visible at the CALL SITE.
*/

// Declare the function WITH default arguments
void createWindow(
    const char* title,
    int x = 1024,
    int y = 1024,
    int width = 2000,
    int height = 2000
);

// Define the function WITHOUT repeating defaults
void createWindow(const char* title, int x, int y, int width, int height) {
    std::cout << "Title:  " << title << '\n';
    std::cout << "X:      " << x << '\n';
    std::cout << "Y:      " << y << '\n';
    std::cout << "Width:  " << width << '\n';
    std::cout << "Height: " << height << '\n';
}

int main() {
    createWindow("RuneLite");               // uses all defaults
    createWindow("RuneLite", 50, 50);       // overrides x and y
    createWindow("RuneLite", 0, 0, 800, 600); // overrides all

    return 0;
}
