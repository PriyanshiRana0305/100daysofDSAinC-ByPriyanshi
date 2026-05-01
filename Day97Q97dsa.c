/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int cmpEnd(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmpStart);

    int *heap = (int *)malloc(n * sizeof(int)); // min-heap for end times
    int size = 0;

    for (int i = 0; i < n; i++) {
        // remove all meetings that ended
        int j = 0;
        while (j < size) {
            if (heap[j] <= arr[i].start) {
                heap[j] = heap[size - 1];
                size--;
            } else {
                j++;
            }
        }

        // add current meeting end time
        heap[size++] = arr[i].end;

        // maintain heap (simple sort for min behavior)
        qsort(heap, size, sizeof(int), cmpEnd);
    }

    printf("%d\n", size);

    free(heap);
    return 0;
}