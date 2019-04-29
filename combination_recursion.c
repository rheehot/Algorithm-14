#include <stdio.h>
int combination(int n, int k);

int main(){
	int n, k;

	puts("input n amd k");
	scanf("%d %d", &n, &k);
	printf("%dC%d = %d\n", n, k, combination(n, k));
	return 0;
}

int combination(int n, int k)
{
	if(n == k || k == 0)
		return 1;
	return (combination(n-1, k-1) + combination(n-1, k));
}