#include "Tests/test_all.h"
#include "Presentation/user_interface.h"
#include "Repository/repo_interface.h"
#include "Repository/repo_in_file.h"

int main() {
    test_all::run_tests();
    repo_in_file<product> prod_repo("products.txt");
    repo_interface<product> &prod_repo_ref = prod_repo;

    user_interface::run();

    return 0;
}
