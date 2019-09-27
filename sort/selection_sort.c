void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int * list, int n){
    int i, j;
    int min;
    
    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(list[min] > list[j]){
                min = j;
            }
        }
        swap(&list[min], &list[i]);
    }
}