/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/

#include <stdio.h>

int main()
{
    int n, i, k = 0;

    scanf("%d", &n);
    int a[n];

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
    {
        if (i == 0 || a[i] != a[i - 1])
            a[k++] = a[i];
    }

    for (i = 0; i < k; i++)
        printf("%d ", a[i]);

    return 0;
}
