#include <stdio.h>
void hanoi(int A, int B, int C, int n);
void print_tower(int A, int B, int C, int n);

int main(){
	int n;
	puts("hight of hanoi");
	scanf("%d", &n);
	hanoi(0, 1, 2, n);
}

void hanoi(int A, int B, int C, int n)
{
		hanoi(A, C, B, n-1);
		print_tower(A, B, C, n);
		hanoi(B, A, C, n-1);
}

void print_tower(int A, int B, int C, int n)
{
	
}