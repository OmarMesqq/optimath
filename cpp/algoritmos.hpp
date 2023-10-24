int rec(const int& a, int b) {
	if (b == 0) {return 0;}
	if (b == 1) {return a;}
	b--; 
	return a + rec(a,b);
}

int fib(int n) {
	if (n <= 1) {return n;}
	return fib(n-1) + fib(n-2);
}

