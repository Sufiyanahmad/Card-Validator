#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to implement Luhn Algorithm
int isValidCard(const char *cardNumber) {
    int length = strlen(cardNumber);
    int sum = 0;
    int isSecond = 0;

    for (int i = length - 1; i >= 0; i--) {
        if (!isdigit(cardNumber[i])) {
            return 0; // Invalid character in input
        }

        int digit = cardNumber[i] - '0';

        if (isSecond) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        isSecond = !isSecond;
    }

    return (sum % 10 == 0);
}

int main() {
    char cardNumber[20];
    
    printf("Hint! Your Card Number is: 4539578763621486\n\n");
    printf("Enter your card number: ");
    scanf("%19s", cardNumber);

    if (isValidCard(cardNumber)) {
        printf("✅ Card Number is VALID.\n");
    } else {
        printf("❌ Card Number is INVALID.\n");
    }

    return 0;
}
