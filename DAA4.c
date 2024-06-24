#include <stdio.h>
int main() 
{

    int arr[] = {12, 34, 54, 2, 99, 73, 45, 67};  
    int size = sizeof(arr) / sizeof(arr[0]);

    int largest = arr[0];  
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    printf("The largest number in the array is: %d\n", largest);
    return 0;
}