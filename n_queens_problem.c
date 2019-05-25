#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int n;
int col[25];
int b = 0;

void queens(int i);
int promising(int i);
void print();
int main(){
	int size;
	scanf("%d", &size);
	n = size;
	queens(0);

	return 0;
}
void print(){
	int j;
	for(j = 1; j <= n; j++){
		printf("%d \n", col[j]);
	}		
}
void queens(int i){
	if(b == 0)
	{
		int j;
		if(promising(i) == 1){
			if(i == n){				//다 끝났음
				print();
				b++;
			}
			else {
				for(j = 1; j <= n; j++){
					col[i + 1] = j;
					queens(i+1);
				}
			}
		}
	}
}

int promising(int i){
	int k = 1;
	while(k < i){
		if(col[i] == col[k] || (abs(col[i] - col[k]) == abs(i - k)))
			return FALSE;		
		k++;
	}
	return TRUE;
}