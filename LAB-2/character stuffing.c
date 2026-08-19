#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], stuffed[200];
    int i, j = 0;

    printf("Enter the data: ");
    scanf("%s", data);

    // Add STX at the beginning
    strcpy(stuffed, "STX");
    j = 3;

    for (i = 0; data[i] != '\0'; i++)
    {
        // If DLE occurs in data, insert another DLE
        if (data[i] == 'D')
        {
            stuffed[j++] = 'D';
            stuffed[j++] = 'D';
        }
        else
        {
            stuffed[j++] = data[i];
        }
    }

    // Add ETX at the end
    stuffed[j++] = 'E';
    stuffed[j++] = 'T';
    stuffed[j++] = 'X';
    stuffed[j] = '\0';

    printf("After character stuffing: %s\n", stuffed);

    return 0;
}
