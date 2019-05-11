#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char file_name[100];	//input file name
	FILE *fp;				//open file's file pointer
	char buffer[20];			//after read one line file, store here
	char* result;
	int lamp_num, my_position, i, count = 0;				//number of d
	int* d;		//position of street lamp
	int* W;		//Power Consumption of street lamp

	puts("input file name?");
	scanf("%s", file_name);
	strcat(file_name, ".txt");
	fp = fopen(file_name, "r");		//open file

	fgets(buffer, 20, fp);				//read file and store it in buffer
	lamp_num = atoi(buffer);
	printf("%d\n", lamp_num);				//print

	fgets(buffer, 20, fp);				//read file and store it in buffer
	my_position = atoi(buffer);
	printf("%d\n", my_position);				//print

	d = (int *)malloc(sizeof(int) * lamp_num);
	W = (int *)malloc(sizeof(int) * lamp_num);

	for(i = 0; i < lamp_num; i++)
	{
		if(fgets(buffer, sizeof(buffer), fp) == '\0') break;		//파일에서 한 줄 읽어옴

		result = strtok(buffer, " ");
		while(result != NULL)
		{
			if(count == 0){
				d[i] = atoi(result);
				count++;
				printf("%d\n", d[i]);
			}
			else {
				W[i] = atoi(result);
				count = 0;
				printf("%d \n", W[i]);
			}
			result = strtok(NULL, " ");
		}
	}
	printf("\n d: ");
	for(i = 0; i < lamp_num; i++)
		printf("%d ", d[i]);
	printf("\n W: ");
	for(i = 0; i < lamp_num; i++)
		printf("%d ", W[i]);

	fclose(fp);

	return 0;
}
