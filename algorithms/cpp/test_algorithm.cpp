#define CONFIG_CATCH_MAIN

#include <catch2/catch_test_macros.hpp>
#include "algorithm.hpp"

TEST_CASE("Deve fazer multiplicação por soma recursiva") {
	REQUIRE(recursive_multiplication(4,0) == 0);
	REQUIRE(recursive_multiplication(4,1) == 4);
	REQUIRE(recursive_multiplication(4,9) == 36);
}

TEST_CASE("Deve calcular termos da sequência Fibonacci") { 
	REQUIRE(recursive_fibonacci(0) == 0);
	REQUIRE(recursive_fibonacci(1) == 1);
	REQUIRE(recursive_fibonacci(25) == 75025);
}

