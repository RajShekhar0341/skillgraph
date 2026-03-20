#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        } else if ((c >= 'a' && c <= 'z')) {
            consonants++;
        }
    }
    
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    
    return 0;
}
