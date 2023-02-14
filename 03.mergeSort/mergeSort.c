#include <stdio.h>

void merge(int arr[],int mid,int l,int h){
	int i,j,k;
	int b[50];
	i=l;
	j=mid + 1;
	k=l;
	
	while(i<=mid && j<=h){
		if(arr[i]<arr[j]){
			b[k]=arr[i];
			i++;
			k++;
		}
		else{
			b[k]=arr[j];
			j++;
			k++;
		}
	}
	while(i<=mid){
		b[k]=arr[i];
		i++;
		k++;
	}
	while(j<=h){
		b[k]=arr[j];
		j++;
		k++;
	}
	for(i=0;i<=h;i++){
        arr[i]=b[i];
    }
}

int mergeSort(int arr[],int l,int h){
	int mid;
	if(l<h){
		mid = (l+h)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,h);
		merge(arr,mid,l,h);
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
	mergeSort(arr,0,size-1);
	printf("\nSorted Array : ");
	for(i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
