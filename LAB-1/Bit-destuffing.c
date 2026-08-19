#include <stdio.h>

int main()
{
    int n, i, count = 0;
    int bits[200], destuffed[200];
    int j = 0;

    printf("Enter number of bits: ");
    scanf("%d", &n);

    printf("Enter the stuffed bits (0 or 1):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &bits[i]);

    for (i = 0; i < n; i++)
    {
        destuffed[j++] = bits[i];

        if (bits[i] == 1)
            count++;
        else
            count = 0;

        // Remove 0 after five consecutive 1s
        if (count == 5)
        {
            if (i + 1 < n && bits[i + 1] == 0)
            {
                i++;       // Skip the stuffed 0
            }
            count = 0;
        }
    }

    printf("After bit destuffing: ");
    for (i = 0; i < j; i++)
        printf("%d", destuffed[i]);

    return 0;
}
