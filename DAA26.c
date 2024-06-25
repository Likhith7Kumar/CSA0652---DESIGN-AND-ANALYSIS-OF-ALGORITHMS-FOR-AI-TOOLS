#include <stdio.h>

void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        
        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        
        printf("\n");
    }
}

int main() {
    int n = 4;  
    printPattern(n);
    return 0;
}