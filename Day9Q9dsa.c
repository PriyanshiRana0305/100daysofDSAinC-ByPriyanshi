/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order. Input: - Single line: a lowercase string containing only alphabetic characters (no spaces) Output: - Print the transformed code name after applying the mirror operation Example: Input: hello Output: olleh Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/
#include <stdio.h>
#include <string.h>

void reverse(char s[], int i)
{
    int n = strlen(s);

    if (i >= n / 2)
        return;

    char temp = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = temp;

    reverse(s, i + 1);
}

int main()
{
    char s[100];
    scanf("%s", s);

    reverse(s, 0);
    printf("%s", s);

    return 0;
}
