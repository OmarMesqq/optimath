#define CONFIG_CATCH_MAIN

#include "include/catch2.cpp"
#include "algoritmos.hpp"

TEST_CASE("Deve fazer multiplicação por soma recursiva") {
	REQUIRE(rec(4,0) == 0);
	REQUIRE(rec(4,1) == 4);
	REQUIRE(rec(4,9) == 36);
}

TEST_CASE("Deve calcular termos da sequência Fibonacci") { 
	REQUIRE(fib(0) == 0);
	REQUIRE(fib(1) == 1);
	REQUIRE(fib(25) == 75025);
}

