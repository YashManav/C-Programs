#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f (int arr[],int n)
{
   arr[1] = 43;
}
void main(){
    int arr[] = {1,2,3,4,5};
    f(arr,5);
    printf("%d",arr[1]);
}