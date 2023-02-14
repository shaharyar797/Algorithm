#include<stdio.h>

struct Job{
	int id;
	int deadline;
	int profit;
};

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int arr[],int n,struct Job job[]){
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
				swap(&arr[i],&arr[j]);
//				temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
				
				swap(&job[i].id,&job[j].id);
//				temp = job[i].id;
//				job[i].id = job[j].id;
//				job[j].id = temp;

				swap(&job[i].deadline,&job[j].deadline);
//				temp = job[i].deadline;
//				job[i].deadline = job[j].deadline;
//				job[j].deadline = temp;
				
				swap(&job[i].profit,&job[j].profit);
//				temp = job[i].profit;
//				job[i].profit = job[j].profit;
//				job[j].profit = temp;
			}
		}while(i<j);
		
		swap(&arr[l],&arr[j]);
//		temp = arr[l];
//		arr[l] = arr[j];
//		arr[j] = temp;
		
		swap(&job[l].id,&job[j].id);
//		temp = job[l].id;
//		job[l].id = job[j].id;
//		job[j].id = temp;
		
		swap(&job[l].deadline,&job[j].deadline);		
//		temp = job[l].deadline;
//		job[l].deadline = job[j].deadline;
//		job[j].deadline = temp;
		
		swap(&job[l].profit,&job[j].profit);	
//		temp = job[l].profit;
//		job[l].profit = job[j].profit;
//		job[j].profit = temp;
		
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

int min(int a,int b){
	return (a<b)?a:b;
}

int main(){
	struct Job job[50];
	int n,i,j;
	int profit[50];
	int totalProfit=0;
	int result[n]; 
    int slot[n],max; 
	printf("Enter the number of job: ");
	scanf("%d",&n);
	printf("Enter the Deadline and Profit: - \n");
	for (i=0;i<n;i++){
		job[i].id = i+1;
		printf("\njob %d: \nDeadline: ",i+1);
		scanf("%d",&job[i].deadline);
		printf("Profit: ");
		scanf("%d",&job[i].profit);
		profit[i] = job[i].profit;
	}
	max = job[0].deadline;
	for(i=1;i<n;i++){
		if(job[i].deadline>max){
			max = job[i].deadline;
		}
	}

	sort(profit,n,job);
	
    for (i = n-1; i >= 0; i--)
        slot[i] = 0;
 	
 	
    for (i = n-1; i >= 0; i--) {
       
        for (j = min(n, job[i].deadline) - 1; j >= 0; j--) {
          
            if (slot[j] == 0) {
                result[j] = job[i].id; 
                slot[j] = 1;
                totalProfit += job[i].profit;
                break;
            }
        }
    }
	
	printf("Job Sequence = ");
    for (i = 0; i < max; i++)
        if (slot[i])
            printf("%d ", result[i]);
	printf("\nTotal Profit = %d",totalProfit);
	return 0;
}
