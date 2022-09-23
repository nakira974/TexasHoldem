//
// Created by maxim on 22/09/2022.
//

#include "gtest/gtest.h"


void test_gtest();

int main(){
    test_gtest();
    return 0;
}

void test_gtest(){
    ASSERT_TRUE(isdigit(6.0));
}