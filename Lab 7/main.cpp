#include "Tests/tests.h"
#include "UI/menu.h"

int main() {
    tests t;
    t.run_tests();
    menu console;
    console.start();
    return 0;
}
