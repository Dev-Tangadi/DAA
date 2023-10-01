#include <stdio.h>

void fractionalKnapsack(int n, int V[], int W[], int M) {
    int selected[n];
    int sw = 0;      // Weight of selected items
    double sp = 0.0;      // Profit of selected items
    int counter=0;
    // Calculate profit-to-weight ratio (pi/wi) for each item
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)V[i] / W[i];
        counter++;
    }

    // Sort items in descending order of profit-to-weight ratio
    for (int i = 0; i< n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            counter++;
            if (ratios[i] < ratios[j]) {
                // Swap ratios
                double tempRatio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = tempRatio;

                // Swap weights
                int tempWeight = W[i];
                W[i] = W[j];
                W[j] = tempWeight;

                // Swap profits
                int tempProfit = V[i];
                V[i] = V[j];
                V[j] = tempProfit;
            }
        }
    }
for(int i=0;i<n;i++) {
    if (sw + W[i] <= M) {
        selected[i] = 1;
        sw = sw + W[i];
        sp = sp + V[i];
    } 
else {
        double frac = (double)(M - sw) / W[i];
        selected[i] = frac; // Select a fraction of item i
        sw = M; // Knapsack is full
        sp = sp + (V[i] * frac);
    }
    counter++;
}
    printf("Total Weight: %d\n", sw);
    printf("Total Profit: %lf\n", sp);
    printf("Time Complexity: %d",counter);
}

int main() {
    int n, M;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int V[n]; // Array of profits
    int W[n]; // Array of weights

    printf("Enter the profits of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &V[i]);
    }
    printf("Enter the weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &W[i]);
    }
   
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &M);

    fractionalKnapsack(n, V, W, M);

    return 0;
}
