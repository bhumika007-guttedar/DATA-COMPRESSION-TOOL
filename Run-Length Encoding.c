#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

// Function to compress a string using RLE
void compressRLE(char *input) {
    int i, count;
    char current;

    printf("\nCompressed Output:\n");
    for (i = 0; input[i] != '\0'; i++) {
        current = input[i];
        count = 1;

        while (input[i] == input[i+1]) {
            count++;
            i++;
        }

        printf("%d%c", count, current);
    }
    printf("\n");
}

// Function to decompress an RLE compressed string
void decompressRLE(char *input) {
    int i = 0, count;

    printf("\nDecompressed Output:\n");
    while (input[i] != '\0') {
        count = 0;

        // Read count number
        while (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0');
            i++;
        }

        // Print character 'count' times
        for (int j = 0; j < count; j++) {
            printf("%c", input[i]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    char input[MAX];
    int choice;

    while (1) {
        printf("\n--- Data Compression Tool (RLE) ---\n");
        printf("1. Compress Text\n");
        printf("2. Decompress Text\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear newline character

        switch (choice) {
            case 1:
                printf("Enter the text to compress: ");
                fgets(input, MAX, stdin);
                input[strcspn(input, "\n")] = '\0'; // remove newline
                compressRLE(input);
                break;

            case 2:
                printf("Enter the text to decompress (e.g., 4A3B): ");
                fgets(input, MAX, stdin);
                input[strcspn(input, "\n")] = '\0'; // remove newline
                decompressRLE(input);
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}