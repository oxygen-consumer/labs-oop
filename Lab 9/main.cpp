#include "Tests/test_all.h"
#include "Presentation/user_interface.h"

int main() {
    test_all::run_tests();

    user_interface::run();

    return 0;
}
