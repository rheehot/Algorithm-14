#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* open_file();
int** make_array(int size);
void PrintMap(int** map, int size);
void min_mult(int n,int* d,int** M,int** p);
void search_min(int i, int j, int* d, int **M, int ** p);
void print_order(int** p, int i, int j, FILE* fp);

int main() {
	int i, size, array_size;
	int* d, *p_size;
	int ** M, **p;
	FILE *fp = fopen("output.txt", "w");;

	p_size = (int*)malloc(sizeof(int));
	d = open_file(p_size);

	size = *p_size;
	array_size = size - 1;

	M = make_array(size);
	p = make_array(size);

	for(i = 0; i < size; i++)
		M[i][i] = 0;

	min_mult(size, d, M, p);

	print_order(p, 1, size - 1, fp);
	fclose(fp);
	return 0;
}

void print_order(int** p, int i, int j, FILE *fp){
	int k = p[i][j];
	if(i == j)
		fprintf(fp, "%d ", i);
	else {
		fprintf(fp, "(");
		print_order(p, i, k, fp);
		print_order(p, k+1, j, fp);
		fprintf(fp, ")");
		}
}

void min_mult(int n,int* d,int** M,int** p)
{
	int i, j, diagonal;
	for(diagonal = 1; diagonal < n - 1 ; diagonal++)
	{
		for(i = 1; i < n - diagonal; i++)
		{
			j = i + diagonal;
			search_min(i, j, d, M, p);
		}
	}
}
void search_min(int i, int j, int* d, int **M, int ** p)
{
	int min_M, min_p, k, tmp;
	k = i;

	min_M = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
	min_p = k;
	for(k = i + 1; k <= j-1; k++)
	{
		tmp = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
		if(tmp < min_M){
			min_M = tmp;
			min_p = k;
		}
	}
	M[i][j] = min_M;
	p[i][j] = min_p;
}

int ** make_array(int size)
{
	int ** arr;
	int i, j;

	arr = (int **)malloc(sizeof(int*) * size);

	for(i = 0; i < size; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * size);
	}

	for (i = 0; i < size; i++)				//initialize array
	{
		for (j = 0; j < size; j++)
		{
			arr[i][j] = -1;
		}
	}
	return arr;
}


int* open_file(int * p_size)
{
	char file_name[100];	//input file name
	FILE *fp;				//open file's file pointer
	char buffer;			//after read one line file, store here
	int size, i;				//number of d
	int* d;

	puts("input file name?");
	scanf("%s", file_name);
	strcat(file_name, ".txt");
	fp = fopen(file_name, "r");		//open file

	buffer = fgetc(fp);				//read file and store it in buffer
	fgetc(fp);						//for deleting \n

	size = buffer - '0';
	*p_size = size;

	d = (int *)malloc(sizeof(int) * size);

	for(i = 0; i < size; i++)
	{
		buffer = fgetc(fp);
		fgetc(fp);
		if(buffer < 0) break;

		d[i] = buffer - '0';
	}

	fclose(fp);

	return d;
}
