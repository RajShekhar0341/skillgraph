#include <stdio.h>

int main() {
    int rows = 5;
    
    // Upper cone (pointing up)
    for (int i = 1; i <= rows; i++) {
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Lower cone (pointing down)
    for (int i = rows - 1; i >= 1; i--) {
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}