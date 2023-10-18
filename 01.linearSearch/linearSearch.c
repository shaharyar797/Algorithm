#include <stdio.h>

int main () {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the values: ");
    for(int i = 0; i < n; i++) {
    	scanf("%d", &arr[i]);
	}
	
	int key;
	printf("Enter the number to find: ");
    scanf("%d", &key);
    
    for(int i = 0; i < n; i++) {
    	if(arr[i] == key) {
			printf("Number found at index %d", i);
			return 0;
		}
	}
	
	printf("Number not found.");
    return 0;
}
