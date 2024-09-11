#include <stdio.h>

void printSubset(int arr[], int n, int subset[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", subset[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void findSubsets(int arr[], int n, int target, int subset[], int size, int index) {
    if (target == 0) {
        printSubset(arr, n, subset, size);
        return;
    }

    if (index == n || target < 0) {
        return;
    }

    subset[size] = arr[index];
    findSubsets(arr, n, target - arr[index], subset, size + 1, index + 1);


    findSubsets(arr, n, target, subset, size, index + 1);
}


int main() {
	         printf("192211572,S.rohith\n"); 
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int subset[100]; 

    printf("Subsets that sum up to %d:\n", target);
    findSubsets(arr, n, target, subset, 0, 0);

    return 0;
}
