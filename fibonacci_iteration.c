#include <stdio.h>
int fibonacci(int n);

int main()
{
	int n;

	puts("input number");
	scanf("%d", &n);

	printf("fibonacci number is : %d\n", fibonacci(n));
	return 0;
}

int fibonacci(int n)	//fibonacci function
{
	int F[n + 1], i;
	F[0] = 0; F[1] = 1;

	for(i = 2; i <= n; i++)
		F[i] = F[i-1] + F[i-2];

	return (F[n]);
}