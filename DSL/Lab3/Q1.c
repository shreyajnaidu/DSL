#include <stdio.h>
int strLength(char str[]) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
void strConcat(char str1[], char str2[]) {
    int len1 = strLength(str1);
    int i = 0;
    while (str2[i] != '\0') {
        str1[len1 + i] = str2[i];
        i++;
    }
    str1[len1 + i] = '\0';
}
int strCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (str1[i] - str2[i]);
}
void insertSubstring(char mainStr[], char subStr[], int pos) {
    int lenMain = strLength(mainStr);
    int lenSub = strLength(subStr);
    for (int i = lenMain - 1; i >= pos; i--) {
        mainStr[i + lenSub] = mainStr[i];
    }
    for (int i = 0; i < lenSub; i++) {
        mainStr[pos + i] = subStr[i];
    }

    mainStr[lenMain + lenSub] = '\0';
}
void deleteSubstring(char mainStr[], char subStr[]) {
    int lenMain = strLength(mainStr);
    int lenSub = strLength(subStr);
    int i, j, k, found;

    for (i = 0; i <= lenMain - lenSub; i++) {
        found = 1;
        for (j = 0; j < lenSub; j++) {
            if (mainStr[i + j] != subStr[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            for (k = i; k <= lenMain - lenSub; k++) {
                mainStr[k] = mainStr[k + lenSub];
            }
            break;
        }
    }
}

int main() {
    char str1[100], str2[100], sub[50];
    int choice, pos;

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    do {
        printf("\nMenu:\n");
        printf("1. Length of a string\n");
        printf("2. String concatenation\n");
        printf("3. String comparison\n");
        printf("4. Insert a substring\n");
        printf("5. Delete a substring\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        switch (choice) {
            case 1:
                printf("Length of first string: %d\n", strLength(str1));
                printf("Length of second string: %d\n", strLength(str2));
                break;
            case 2:
                strConcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;
            case 3:
                if (strCompare(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are NOT equal.\n");
                break;
            case 4:
                printf("Enter substring to insert: ");
                gets(sub);
                printf("Enter position to insert at (0-based index): ");
                scanf("%d", &pos);
                insertSubstring(str1, sub, pos);
                printf("After insertion: %s\n", str1);
                break;
            case 5:
                printf("Enter substring to delete: ");
                gets(sub);
                deleteSubstring(str1, sub);
                printf("After deletion: %s\n", str1);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
