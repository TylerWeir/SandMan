#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

int add(int a, int b) { return a + b; }

TEST_CASE("Testing the add function") { CHECK(add(1, 2) == 3); }
