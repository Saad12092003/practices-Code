

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int num)
 {
    if (num < 2)
        return 0;
    for (int i = 2; i * i <= num; i++)
        {
        if (num % i == 0)
         return 0;
    }
    return 1;
}
void findPrimes()
 {
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        if (isPrime(i))
            {
            printf("%d ", i);
        }
    }
    printf("\n");
}
void sortArray() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int array[n];
    printf("Random array: ");
    for (int i = 0; i < n; i++)
        {
        array[i] = rand() % 101;
        printf("%d ", array[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (array[j] > array[j + 1])
             {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void analyzeString()
{
    char str[100];
    printf("Enter a string: ");
    getchar();
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    int freq[256] = {0};
    for (int i = 0; str[i] != '\0'; i++)
        {
        freq[(unsigned char)str[i]]++;
    }

    printf("Unique characters: ");
    for (int i = 0; i < 256; i++) {
        if (freq[i] == 1) {
            printf("%c ", i);
        }
    }
    printf("\nDuplicate characters: ");
    for (int i = 0; i < 256; i++)
        {
        if (freq[i] > 1)
        {
            printf("%c ", i);
        }
    }
    printf("\nCharacter frequencies:\n");
    for (int i = 0; i < 256; i++)
     {
        if (freq[i] > 0) {
            printf("%c: %d\n", i, freq[i]);
        }
    }
}
void menu() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Find Prime Numbers in a Range\n");
        printf("2. Sort an Array of Random Numbers\n");
        printf("3. Analyze a String\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findPrimes();
                break;
            case 2:
                sortArray();
                break;
            case 3:
                analyzeString();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}
int main()
 {
    menu();
    return 0;
}