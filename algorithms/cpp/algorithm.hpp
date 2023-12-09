/**
 * @brief Recursively multiplies a number.
 *
 * This function recursively multiplies the number 'a' by 'b'
 * by summing 'a' to itself 'b' times.
 *
 * @param a the multiplier.
 * @param b the multiplicand.
 * @return the product of a and b.
 */
int recursive_multiplication(const int& a, int b) {
	if (b == 0) {return 0;}
	if (b == 1) {return a;}
	b--; 
	return a + recursive_multiplication(a,b);
}

/**
 * @brief Computes Fibonacci number.
 *
 * This function computes the `nth` term of the Fibonacci sequence
 * using a recursive algorithm.
 *
 * @param n the position of the Fibonacci number to compute.
 * @return the Fibonacci number at position 'n'.
 */
int recursive_fibonacci(int n) {
	if (n <= 1) {return n;}
	return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}
