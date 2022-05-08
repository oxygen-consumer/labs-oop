#include "Tests/test_all.h"
#include "Presentation/user_interface.h"
#include "Repository/repo_interface.h"
#include "Repository/repo_in_file.h"

int main() {
    test_all::run_tests();

    repo_interface<product> *products_repo = new repo_in_file<product>(
            "products.txt");
    repo_interface<banknote> *banknotes_repo = new repo_in_file<banknote>(
            "banknotes.txt");

    vending_machine_service serv(products_repo, banknotes_repo);

    user_interface ui(serv);

    ui.run();

    return 0;
}
