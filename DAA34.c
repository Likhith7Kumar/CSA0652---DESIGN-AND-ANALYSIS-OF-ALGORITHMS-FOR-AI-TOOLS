#include <stdio.h>

void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int total, int nodeIndex, int targetSum) {
    if (total == targetSum) {
        printf("Subset found: ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    for (int i = nodeIndex; i < n; i++) {
        if (total + set[i] <= targetSum) {
            subset[subsetSize] = set[i];
            sumOfSubsets(set, subset, n, subsetSize + 1, total + set[i], i + 1, targetSum);
        }
    }
}

int main() {
    int n, targetSum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    int subset[n]; 
    printf("Subsets that sum to %d are:\n", targetSum);
    sumOfSubsets(set, subset, n, 0, 0, 0, targetSum);

    return 0;
}