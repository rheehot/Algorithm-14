#include <stdio.h>
int fibonacci(int n);

int main()
{
	int n;

	puts("put number");
	scanf("%d", &n);
	printf("fibonacci number is : %d\n", fibonacci(n));
	return 0;
}

int fibonacci(int n)
{
	if (n <= 1)
		return n;
	return (fibonacci(n-1) + fibonacci(n-2));
}