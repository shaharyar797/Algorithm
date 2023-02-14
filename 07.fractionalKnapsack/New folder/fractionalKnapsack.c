#include<stdio.h>

struct Item{
	int weight;
	int value;
	float ratio;
};

void sort(int arr[],int n,struct Item item[]){
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
				
				temp = item[i].value;
				item[i].value = item[j].value;
				item[j].value = temp;
				
				temp = item[i].weight;
				item[i].weight = item[j].weight;
				item[j].weight = temp;
				
				temp = item[i].ratio;
				item[i].ratio = item[j].ratio;
				item[j].ratio = temp;
			}
		}while(i<j);
		temp = arr[l];
		arr[l] = arr[j];
		arr[j] = temp;
		
		temp = item[l].value;
		item[l].value = item[j].value;
		item[j].value = temp;
		
		temp = item[l].weight;
		item[l].weight = item[j].weight;
		item[j].weight = temp;
		
		temp = item[l].ratio;
		item[l].ratio = item[j].ratio;
		item[j].ratio = temp;
		
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
	quickSort(arr,0,n-1);
}

int main(){
	struct Item item[50];
	int n,i,capacity,result;
	float ratio[50];
	int answer=0;
	printf("Enter the number of item: ");
	scanf("%d",&n);
	printf("Enter the weight and value: - \n");
	for (i=0;i<n;i++){
		printf("\nItem %d: \nWeight: ",i);
		scanf("%d",&item[i].weight);
		printf("Value: ");
		scanf("%d",&item[i].value);
		item[i].ratio = (float)item[i].value / (float)item[i].weight;
		ratio[i] = item[i].ratio;
	}
	printf("\nEnter the capacity of Knapsack: ");
	scanf("%d",&capacity);
	sort(ratio,n,item);
	for (i=0;i<n;i++){
		printf("w=%d\tv=%d\tr=%f\n",item[i].weight,item[i].value,item[i].ratio);
	}
	for(i=n-1;i>=0;i--){
		printf("w=%d\tv=%d\tr=%f\n",item[i].weight,item[i].value,item[i].ratio);
	}
	
	for(i=n-1;i>=0;i--){
		if(capacity == 0) break;
		else if(item[i].weight <= capacity){
			answer += item[i].value;
			printf("\nanswer = %d\t",answer);
			capacity -= item[i].weight;
			printf("left capacity : %d",capacity);
		}
		else{
			answer += item[i].value * ((float)capacity / (float)item[i].weight);
			capacity = 0;//item[i].weight * ((float)capacity / (float)item[i].weight);
		}
	}
	printf("\nMaximum Value of the Knapsack: %d",answer);
	return 0;
}
