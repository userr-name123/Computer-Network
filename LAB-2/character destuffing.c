#include <stdio.h>
#include <string.h>

int main()
{
    char stuffed[200], destuffed[100];
    int i, j = 0, len;

    printf("Enter the stuffed data: ");
    scanf("%s", stuffed);

    len = strlen(stuffed);

    // Skip STX (first 3 characters)
    i = 3;

    // Remove ETX (last 3 characters)
    while (i < len - 3)
    {
        // If two consecutive D's are found,
        // remove one D
        if (stuffed[i] == 'D' && stuffed[i + 1] == 'D')
        {
            destuffed[j++] = 'D';
            i += 2;
        }
        else
        {
            destuffed[j++] = stuffed[i++];
        }
    }

    destuffed[j] = '\0';

    printf("After character destuffing: %s\n", destuffed);

    return 0;
}
