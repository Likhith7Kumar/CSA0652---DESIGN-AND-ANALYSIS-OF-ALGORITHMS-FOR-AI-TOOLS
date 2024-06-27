#include <stdio.h>

int main() {
	
    int n, i, pos, num;
    
    
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    
    int list[n + 1];

    
    printf("Enter the elements of the list:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    
    printf("Enter the position where you want to insert the new number: ");
    scanf("%d", &pos);

   
    if (pos < 0 || pos > n) {
        printf("Invalid position! Please enter position between 0 and %d\n", n);
        return 1;
    }

    
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);

    for (i = n; i >= pos; i--) {
        list[i + 1] = list[i];
    }

    
    list[pos] = num;

    
    n++;

    
    printf("Updated list:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}