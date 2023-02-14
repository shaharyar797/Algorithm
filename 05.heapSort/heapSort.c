#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int arr[], int N)
{	int i;
	for (i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void heapify(int arr[], int N,int i)
{	
	int root = i-1;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int max = root;
	
	
	if (left < N && arr[left] > arr[root]){	
		max = left;
	}
	
	if (right < N && arr[right] > arr[root]){
		if(arr[right]>arr[max]) max = right;
	}
	if(max != root){
		swap(&arr[max],&arr[root]);
		heapify(arr,N,max+1);
	}
	if(root>0){
		heapify(arr,N,root);
	}
}

void heapSort(int arr[], int N)
{	
	int temp;
	heapify(arr, N, N);
	
	while(N>1){	
		temp = arr[0];
		arr[0] = arr[N-1];
		arr[N-1] = temp;
		N-=1;
		heapify(arr, N, N);
	}
}



int main()
{
	int arr[50],N,i;
	printf("Enter the Size of Array: ");
	scanf("%d",&N);
	printf("\nEnter the element of Array: ");
	for(i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	heapSort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);
	return 0;
}

