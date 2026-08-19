#include <stdio.h>

int main()
{
    int n, i, count = 0;
    int bits[100], stuffed[200];
    int j = 0;

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter the bits (0 or 1):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &bits[i]);

    for (i = 0; i < n; i++)
    {
        stuffed[j++] = bits[i];

        if (bits[i] == 1)
            count++;
        else
            count = 0;

        // Insert 0 after five consecutive 1s
        if (count == 5)
        {
            stuffed[j++] = 0;
            count = 0;
        }
    }

    printf("After bit stuffing: ");
    for (i = 0; i < j; i++)
        printf("%d", stuffed[i]);

    return 0;
}
