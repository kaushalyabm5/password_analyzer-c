#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int score = 0;

    printf("===================================\n");
    printf("          C PASSWORD STRENFTH ANALYZER          \n");
    printf("===================================\n");
    printf("Enter a password to test: ");

    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    password[strcspn(password, "\n")] = '\0';
    int length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isupper((unsigned char)password[i])) {
            hasUpper = 1;
        } else if (islower((unsigned char)password[i])) {
            hasLower = 1;
        } else if (isdigit((unsigned char)password[i])) {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
    }

    if (length >= 8) score++;
    if (length >= 12) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    printf("\n--- Analyse Report --\n");
    printf("Length          : %d characters\n", length);
    printf("Uppercase (A-Z) : %s\n", hasUpper ? "Yes" : "No");
    printf("Lowercase (a-z) : %s\n", hasLower ? "Yes" : "No");
    printf("Numbers (0-9)   : %s\n", hasDigit ? "Yes" : "No");
    printf("Special Chars   : %s\n", hasSpecial ? "Yes" : "No");

    printf("\nStrength Rating   : ");
    if (score <= 2) {
        printf("WEAK (Easily cracked)\n");
    } else if (score <= 4) {
        printf("MODERATE (Add more variety or length)\n");
    } else {
        printf("STRONG (Good security)\n");
    }
    printf("========================================\n");

    return 0;
}