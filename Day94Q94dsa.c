/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }

    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // frequency
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // prefix sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }

    free(count);
    free(output);

    return 0;
}