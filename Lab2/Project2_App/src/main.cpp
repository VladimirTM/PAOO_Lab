#include <iostream>
#include "MathUtils.h"

int main() {
    MathUtils math;

    std::cout << "5 + 3 = " << math.add(5, 3) << std::endl;
    std::cout << "5 - 3 = " << math.subtract(5, 3) << std::endl;

    return 0;
}
