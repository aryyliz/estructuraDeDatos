#include <iostream>

int main() {
    int f = 5;
    int g = 7;
    int *ptr = &g;

    *ptr = f;
    (*ptr)++;

    std::cout << *ptr << " " << f << " " << g << std::endl;
}

