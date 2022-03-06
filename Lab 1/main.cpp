#include <iostream>
#include "Problem/palindrom.h"
#include "Tests/test_palindrom.h"

int main() {
    test_palindrom();

    unsigned long long n;

    n = readN();
    std::cout << "Palindromul numarului introdus este: " << palindrom(n);

    return 0;
}
