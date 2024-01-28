#define CONFIG_CATCH_MAIN

#include <catch2/catch_test_macros.hpp>
#include "algorithm.hpp"

TEST_CASE("") {
	REQUIRE(recursive_multiplication(4,0) == 0);

}
