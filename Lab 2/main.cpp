#include "UI/menu/console.h"
#include "Service/tests/tests.h"

int main() {
    int size = 0, list[100000];

    runTests();
    runMenu(list, size);

    return 0;
}
