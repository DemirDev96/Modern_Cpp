#include <iostream>

/*
    NAMESPACES

    - Group related functions, variables, and types.
    - Prevent name collisions.
    - Make intent explicit at the call site.
*/

namespace avg {
    float calculate(float x, float y) {
        return (x + y) / 2.0f;
    }
}

namespace basic {
    float calculate(float x, float y) {
        return x + y;
    }
}

int main() {
    float a = 3.7f;
    float b = 8.2f;

    float average = avg::calculate(a, b);
    float sum     = basic::calculate(20.2f, 25.32f);

    std::cout << "Average: " << average << '\n';
    std::cout << "Sum:     " << sum << '\n';

    return 0;
}
