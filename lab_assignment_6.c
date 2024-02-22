#include <stdio.h>
#include <stdlib.h> // For malloc and free

int search(int numbers[], int low, int high, int value) {
    if (low > high) {
        return -1; // Base case: value not found
    }
    
    int mid = low + (high - low) / 2; // Calculate the middle index
    
    if (numbers[mid] == value) {
        return mid; // Found the value
    } else if (numbers[mid] < value) {
        // Value is in the right half of the array
        return search(numbers, mid + 1, high, value);
    } else {
        // Value is in the left half of the array
        return search(numbers, low, mid - 1, value);
    }
}

void printArray(int numbers[], int sz) {
    int i;
    printf("Number array : ");
    for (i = 0; i < sz; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {
    int i, numInputs;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt", "r");

    if (inFile == NULL) {
        printf("Error opening input file.\n");
        return 1; // Exit with error
    }

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *) malloc(countOfNums * sizeof(int));
        if (numArray == NULL) {
            printf("Memory allocation failed.\n");
            return 1; // Exit with error
        }

        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile, " %d", &value);
            numArray[i] = value;
        }

        printArray(numArray, countOfNums);
        index = search(numArray, 0, countOfNums - 1, numArray[countOfNums / 2]); // Using the middle value as the search value
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", numArray[countOfNums / 2], index);
        } else {
            printf("Item %d does not exist in the number array!\n", numArray[countOfNums / 2]);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}