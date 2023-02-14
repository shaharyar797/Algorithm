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
	printf("\nroot = %d\tarr[root] = %d",root,arr[root]);
	
	printf("\nis left(%d) < N(%d) && arr[left] > arr[root]?",left,N,arr[left],arr[root]);
	if (left < N && arr[left] > arr[root]){	
		max = left;
		printf("\nmax = %d", arr[max]);
	}
	else{
		printf("NO");
	}
	printf("\nis right(%d) < N(%d) && arr[right] > arr[root]?",right,N,arr[right],arr[root]);
	if (right < N && arr[right] > arr[root]){
		if(arr[right]>arr[max]) max = right;
		printf("\nmax = %d", arr[max]);
	}
	else{
		printf("NO");
	}
	if(max != root){
		swap(&arr[max],&arr[root]);
		heapify(arr,N,max+1);
	}
	printf("\nCurrent Array : ");
	printArray(arr, N);
	printf("\n");
	if(root>0){
		heapify(arr,N,root);
	}
}

//void heapSort(int arr[], int N)
//{	
//	int temp;
//	heapify(arr, N, N);
//	
//	while(N>1){	
//		temp = arr[0];
//		arr[0] = arr[N-1];
//		arr[N-1] = temp;
//		N-=1;
//		heapify(arr, N, N);
//	}
//}



int main()
{
	int arr[] = { 10,14,19,26,31,42,27,44,35,33 };
	int N = sizeof(arr) / sizeof(arr[0]);
	heapify(arr, N,N);
	printf("Sorted array is\n");
	printArray(arr, N);
	return 0;
}

