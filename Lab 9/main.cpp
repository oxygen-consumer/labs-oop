#include "Tests/test_all.h"
#include "Presentation/user_interface.h"
#include "Repository/repo_interface.h"
#include "Repository/repo_in_file.h"

int main() {
    test_all::run_tests();

    repo_in_file<product> prepo("products.txt");
    repo_in_file<banknote> brepo("banknotes.txt");
    repo_interface<product> &products_repo = prepo;
    repo_interface<banknote> &banknotes_repo = brepo;

    vending_machine_service serv(products_repo, banknotes_repo);

    user_interface ui(serv);

    ui.run();

    return 0;
}
