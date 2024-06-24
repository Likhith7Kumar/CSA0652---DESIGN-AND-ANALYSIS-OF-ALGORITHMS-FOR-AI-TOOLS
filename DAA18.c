#include <stdio.h>
#include <stdbool.h>
void generatePrimes(int n) {
    bool isPrime[n + 1];
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    printf("Prime numbers up to %d are: ", n);
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}
int main() {

    int limit;
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);
    generatePrimes(limit);
    return 0;
}