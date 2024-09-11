#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int cost[MAX][MAX];
int n;

int main() {
	         printf("192211572,S.rohith\n"); 
    int i, j;
    long long min_cost = LLONG_MAX; 
    int temp[MAX][MAX];

    printf("Enter the number of tasks and agents: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            temp[i][j] = cost[i][j];

    min_cost = LLONG_MAX;

    int k, l;
    long long temp_cost;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            temp_cost = 0;
            for (k = 0; k < n; k++)
                temp_cost += temp[k][k];

            if (temp_cost < min_cost)
                min_cost = temp_cost;

            for (k = 0; k < n; k++) {
                if (temp[i][k] != INT_MAX) {
                    temp_cost = temp[i][k];

                    for (l = 0; l < n; l++)
                        temp[l][k] = INT_MAX;

                    for (l = 0; l < n; l++)
                        temp[i][l] = INT_MAX;

                    temp[i][k] = INT_MAX;

                    for (int m = i + 1; m < n; m++) {
                        for (int p = 0; p < n; p++) {
                            if (temp[m][p] != INT_MAX) {
                                temp_cost += temp[m][p];

                                for (l = 0; l < n; l++)
                                    temp[l][p] = INT_MAX;

                                for (l = 0; l < n; l++)
                                    temp[m][l] = INT_MAX;

                                temp[m][p] = INT_MAX;

                                long long lower_bound = 0; // Use long long to store lower bound
                                for (l = 0; l < n; l++)
                                    lower_bound += temp[l][l];

                                if (temp_cost + lower_bound < min_cost)
                                    min_cost = temp_cost + lower_bound;

                                for (l = 0; l < n; l++)
                                    temp[l][p] = cost[l][p];

                                for (l = 0; l < n; l++)
                                    temp[m][l] = cost[m][l];

                                temp[m][p] = cost[m][p];
                            }
                        }
                    }

                    for (l = 0; l < n; l++)
                        temp[l][k] = cost[l][k];

                    for (l = 0; l < n; l++)
                        temp[i][l] = cost[i][l];

                    temp[i][k] = cost[i][k];
                }
            }
        }
    }

    printf("Minimum cost: %lld\n", min_cost);

    return 0;
}
