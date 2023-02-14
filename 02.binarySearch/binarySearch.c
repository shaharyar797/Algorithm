#include <stdio.h>

int main (){
    int size, a[20], i, item,key_index;
    int first,last,mid;
    printf ("\nEnter Size of Array : ");
    scanf ("%d", &size);
    printf ("\nEnter Array Elements:- \n");
    for (i = 0; i < size; i++){
        scanf ("%d", &a[i]);
    }
    printf ("\nEnter the Key Element to be Searched : ");
    scanf ("%d", &item);
    first = 0;
    last = size - 1;
    for (i = 0; i <size; i++){
        mid = (first + last)/2;
        if(item == a[mid]){
            key_index=mid;
            break;
        }
        else if(item < a[mid]){
            last = mid - 1;
        }
        else if(item > a[mid]){
            first = mid + 1;
        }
    }
    if (first > last){
      printf ("\n\t Key Element NOT found");
    }
    else{
      printf ("\n\t Key Element found at %d index.", key_index);
    }
    return 0;
}
