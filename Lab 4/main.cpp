#include "Tests/tests.h"
#include "Domain/complex_num.h"
#include "UI/console.h"
#include "Repository/repository_in_memory.h"

int main() {
    run_tests();

    numbers repo;

    run_menu(repo);

    return 0;
}