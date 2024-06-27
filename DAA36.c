#include <stdio.h>

void containerLoader(int weights[], int n, int capacity) {
    int currentWeight = 0;
    int i;
    
    printf("Items loaded into the container:\n");
    
    for (i = 0; i < n; i++) {
        if (currentWeight + weights[i] <= capacity) {
            currentWeight += weights[i];
            printf("Item %d with weight %d\n", i + 1, weights[i]);
        }
    }
    
    printf("Total weight loaded: %d\n", currentWeight);
}

int main() {
	
    int weights[] = {10, 20, 30, 40, 50};
    int n = sizeof(weights) / sizeof(weights[0]);
    int capacity = 100;
    
    containerLoader(weights, n, capacity);
    
    return 0;
}