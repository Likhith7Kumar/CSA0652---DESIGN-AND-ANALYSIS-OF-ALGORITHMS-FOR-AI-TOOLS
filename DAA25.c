#include <stdio.h>
#include <limits.h>

#define N 4


int tsp(int graph[N][N], int mask, int pos, int dp[N][(1<<N)]) {
    if(mask == ((1<<N) - 1)) {
        
        return graph[pos][0];
    }

    if(dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INT_MAX;

    
    for(int city = 0; city < N; city++) {
        if((mask & (1<<city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1<<city), city, dp);
            if(newAns < ans) {
                ans = newAns;
            }
        }
    }

    return dp[pos][mask] = ans;
}

int main() {
    
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    
    int dp[N][(1<<N)];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < (1<<N); j++) {
            dp[i][j] = -1;
        }
    }

    
    printf("The minimum cost is %d\n", tsp(graph, 1, 0, dp));

    return 0;
}