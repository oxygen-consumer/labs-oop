//
// Created by zaha on 5/5/22.
//

#include "test_repo.h"

void test_repo::run_tests() {
    test_repo_in_memory::run_tests();
    test_repo_in_file::run_tests();
}
