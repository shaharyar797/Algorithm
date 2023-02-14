#include<stdio.h>

int partition(int arr[],int l,int h){
	int i,j,pivot,temp;
	pivot = arr[l];
	i=l+1;
	j=h;
	do{
		while(arr[i]<=pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}while(i<j);
	temp = arr[l];
	arr[l] = arr[j];
	arr[j] = temp;
	return j;
}

void quickSort(int arr[],int l,int h){
	int pi;		//partitionIndex
	if(l<h){
		pi = partition(arr,l,h);
		quickSort(arr,l,pi-1);
		quickSort(arr,pi+1,h);
	}
}

int main(){
	int size,arr[50],i;
	printf("Enter the Size of Array : ");
	scanf("%d",&size);
	printf("\nEnter the elements of Array: \n");
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	quickSort(arr,0,size-1);
	printf("\nSorted Array : ");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
