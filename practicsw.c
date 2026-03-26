#include <stdio.h>

int main() {
    int age;
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    if (age <= 0) {
        printf("-1\n");
    } else if (age >= 18) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}