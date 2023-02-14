#include <stdio.h>

int
main ()
{
    int size, a[20], i, item;
    int key_index = -1;
    printf ("\nEnter Size of Array : ");
    scanf ("%d", &size);
    printf ("\nEnter Array Elements:- \n");
    for (i = 0; i < size; i++){
        scanf ("%d", &a[i]);
    }
    printf ("\nEnter the Key Element to be Searched : ");
    scanf ("%d", &item);
    for (i = 0; i <size; i++){
        if (a[i] == item){
            key_index = i;
        }
    }
    if (key_index == -1){
      printf ("\n\t Key Element NOT found");
    }
    else{
      printf ("\n\t Key Element found at %d index.", key_index);
    }
    return 0;
}
