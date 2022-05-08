//
// Created by zaha on 5/5/22.
//

#include "test_all.h"

void test_all::run_tests() {
    test_domain::run_tests();
    test_repo::run_tests();
    test_service::run_tests();
}
