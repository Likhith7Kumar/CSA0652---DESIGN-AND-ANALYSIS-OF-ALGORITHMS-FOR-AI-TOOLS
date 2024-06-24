#include <stdio.h>
int string_length(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }   
    return length;
}
int main() {
    char str[] = "Hello, world!";
    int length = string_length(str);
    printf("Length of the string: %d\n", length);
    return 0;
}