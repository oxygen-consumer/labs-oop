#include "Tests/tests.h"
#include "Domain/complex_num.h"
#include "UI/console.h"

int main() {
    run_tests();

    auto *list = new complex_num[100];
    int size = 0;

    run_menu(list, size);

    delete[] list;
    return 0;
}