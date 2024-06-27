#include <stdio.h>

void printFactors(int n) {
    printf("Factors of %d are:\n", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
	
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printFactors(n);

    return 0;
}