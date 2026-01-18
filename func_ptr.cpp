#include <cstdlib>   // std::atexit
#include <iostream>

// Print `count` copies of `ch`, then a newline.
void printChars(int count, char ch) {
    for (int i = 0; i < count; ++i) {
        std::cout << ch;
    }
    std::cout << '\n';
}

// Called automatically when the program exits normally (via return from main or std::exit).
void onExit() {
    std::cout << "Terminated..\n";
}

int main() {
    // Normal call
    printChars(5, 'D');

    /*
        FUNCTION POINTERS

        Type: void (*)(int, char)
        Meaning: pointer to a function taking (int, char) and returning void.

        You usually don't need '&' when taking a function pointer:
        - printChars and &printChars are equivalent here.
    */
    using PrintFn = void (*)(int, char);
    PrintFn pfn = printChars;

    // Calling through a function pointer (both forms are valid)
    (*pfn)(7, 'C');
    pfn(5, 'D');

    /*
        std::atexit

        - Registers a function to be called at normal program termination.
        - The function must be: void func()
        - Runs when main returns or when std::exit(...) is called.
        - NOT guaranteed to run on abnormal termination (e.g., std::abort, crash, kill -9).
    */
    std::atexit(onExit);

    return 0;
}
