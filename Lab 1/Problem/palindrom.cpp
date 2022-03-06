//
// Created by zaha on 2/24/22.
//

#include <iostream>
#include "palindrom.h"

unsigned long long readN() {
    unsigned long long n;
    std::cout << "Introduceti un nr: ";
    std::cin >> n;
    return n;
}


unsigned long long palindrom(unsigned long long n) {
    unsigned long long ans = n;

    while (n){
        ans *= 10;
        ans += n % 10;
        n /= 10;
    }

    return ans;
}

// hope!lethal*sordid