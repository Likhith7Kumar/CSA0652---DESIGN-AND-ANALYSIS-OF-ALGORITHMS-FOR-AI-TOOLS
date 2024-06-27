#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

int min(int a, int b) {
    return (a < b) ? a : b;
}

int calculateLowerBound(int costMatrix[N][N], bool assigned[], int row) {
    int bound = 0;
    for (int i = row; i < N; i++) {
        int minCost = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!assigned[j]) {
                minCost = min(minCost, costMatrix[i][j]);
            }
        }
        bound += minCost;
    }
    return bound;
}

void branchAndBoundUtil(int costMatrix[N][N], int row, bool assigned[], int currentAssignment[], int currentCost, int *minCost, int bestAssignment[]) {
    if (row == N) {
        if (currentCost < *minCost) {
            *minCost = currentCost;
            for (int i = 0; i < N; i++) {
                bestAssignment[i] = currentAssignment[i];
            }
        }
        return;
    }

    for (int j = 0; j < N; j++) {
        if (!assigned[j]) {
            assigned[j] = true;
            currentAssignment[row] = j;
            int newCost = currentCost + costMatrix[row][j];
            int bound = newCost + calculateLowerBound(costMatrix, assigned, row + 1);

            if (bound < *minCost) {
                branchAndBoundUtil(costMatrix, row + 1, assigned, currentAssignment, newCost, minCost, bestAssignment);
            }

            assigned[j] = false;
        }
    }
}

void branchAndBound(int costMatrix[N][N]) {
    int minCost = INT_MAX;
    int bestAssignment[N];
    bool assigned[N] = {false};
    int currentAssignment[N];

    branchAndBoundUtil(costMatrix, 0, assigned, currentAssignment, 0, &minCost, bestAssignment);

    printf("The optimal assignment is:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d is assigned to job %d\n", i + 1, bestAssignment[i] + 1);
    }
}

int main() {
    
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    branchAndBound(costMatrix);

    return 0;
}