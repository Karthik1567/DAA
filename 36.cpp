#include <stdio.h>

void containerLoader(int weights[], int capacities[], int n) {
    int i, j;
    int totalWeight = 0;

    for (i = 0; i < n; i++) {
        totalWeight += weights[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (weights[j] <= capacities[i]) {
                capacities[i] -= weights[j];
                weights[j] = 0;
                break;
            }
        }
    }

    printf("Total weight loaded: %d\n", totalWeight);
}

int main() {
	         printf("192211572,S.rohith\n"); 
    int weights[] = {10, 20, 30, 40, 50};
    int capacities[] = {100, 80, 60, 40, 20};
    int n = sizeof(weights) / sizeof(weights[0]);

    containerLoader(weights, capacities, n);

    return 0;
}
