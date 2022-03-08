#include "Service/tests/tests.h"
#include "UI/menu/console.h"

int main() {
    int size = 0;
    int *list = new int[100000];

    runTests();
    runMenu(list, size);

    delete[] list;
    return 0;
}
