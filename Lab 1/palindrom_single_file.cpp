//
// Created by zaha on 2/24/22.
//

#include <iostream>
#include <cassert>
#define ull unsigned long long


ull palindrom(ull n) {
    ull ans = n;

    while (n){
        ans *= 10;
        ans += n % 10;
        n /= 10;
    }

    return ans;
}


void test_palindrom() {
    assert(palindrom(1234) == 12344321);
    assert(palindrom(1) == 11);
    assert(palindrom(0) == 0);
    assert(palindrom(10) == 1001);
}


int main() {
    test_palindrom();

    ull n;

    std::cout << "Introduceți un nr: ";
    std::cin >> n;
    std::cout << "Palindromul numarului introdus este: " << palindrom(n);

    return 0;
}