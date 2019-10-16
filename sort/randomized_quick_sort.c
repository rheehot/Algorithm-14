#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int list[], int low, int high);
void swap(int* a, int*b);
int partition(int list[], int low, int high);
int rand_partition(int list[], int low, int high);

int main()
{
    int list[] = {15, 22, 13, 27, 12, 10, 20, 25};
    int i;
    quick_sort(list, 0, 7);
    for(i = 0; i < 8; i++)
        printf("%d ", list[i]);
    return 0;
}

int rand_partition(int list[], int low, int high){
    int i;
    srand(time(NULL));
    i = low + rand() % (high - low);
    swap(&list[low], &list[i]);
    return partition(list, low, high);
}

void quick_sort(int list[], int low, int high){
    if (high > low){
        int pivotpoint = rand_partition(list, low, high);
        quick_sort(list, low, pivotpoint - 1);
        quick_sort(list, pivotpoint + 1, high);
    }  
}

int partition(int list[], int low, int high){
    int i, j = low;
    int pivotitem = list[low];

    for (i = low + 1; i <= high; i++){
        if (list[i] < pivotitem) {
            j++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[low], &list[j]);
    return j;
}

void swap(int* a, int*b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}