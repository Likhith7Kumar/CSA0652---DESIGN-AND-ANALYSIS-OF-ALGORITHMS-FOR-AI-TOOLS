#include <stdio.h>
#include <math.h>

int countDigits(int n) {
    if (n == 0)
        return 0;
    return 1 + countDigits(n / 10);
}

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

int isArmstrongRecursive(int n, int digits) {
    if (n == 0)
        return 0;
    int digit = n % 10;
    return power(digit, digits) + isArmstrongRecursive(n / 10, digits);
}

int isArmstrong(int n) {
    int digits = countDigits(n);
    return n == isArmstrongRecursive(n, digits);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isArmstrong(n))
        printf("%d is an Armstrong number.\n", n);
    else
        printf("%d is not an Armstrong number.\n", n);

    return 0;
}
