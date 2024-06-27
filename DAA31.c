#include <stdio.h>

int main() {
    int n, i, min, max;

    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    min = max = arr[0];

    
    for(i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}