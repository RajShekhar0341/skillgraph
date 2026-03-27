#include <stdio.h>

int main() {
    char gender, marital_status;
    int age;

    scanf(" %c %d %c", &gender, &age, &marital_status);

    // Convert to uppercase if lowercase
    if (gender >= 'a' && gender <= 'z') {
        gender = gender - 32;
    }
    if (marital_status >= 'a' && marital_status <= 'z') {
        marital_status = marital_status - 32;
    }

    if (marital_status == 'Y') {
        if ((gender == 'M' && age > 30) || (gender == 'F' && age > 25)) {
            printf("1");
        } else {
            printf("-1");
        }
    } else {
        printf("-1");
    }

    return 0;
}