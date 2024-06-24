#include <stdio.h>
struct Item {
    int value;
    int weight;
};
void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;
            if (r1 < r2) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
double knapsack(struct Item arr[], int n, int W) {
    sortItems(arr, n);
    int curWeight = 0;  
    double finalValue = 0.0;  
    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {

    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    struct Item arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    double maxValue = knapsack(arr, n, W);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}