void insertion_sort(int n, int data[]){
	for(int i = 1; i < n; i++){
		int tmp = data[i];
		int j = i - 1;
		while(j >= 0 && data[j] > data[i]){
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = tmp;
	}
}