#include <stdio.h>
#include <string.h>

void xorOperation(char *a, char *b, int pos, int keyLen)
{
    int i;

    for (i = 0; i < keyLen; i++)
        a[pos + i] = (a[pos + i] == b[i]) ? '0' : '1';
}

int main()
{
    char data[100], key[50], temp[150];
    int dataLen, keyLen, i;

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter generator bits: ");
    scanf("%s", key);

    dataLen = strlen(data);
    keyLen = strlen(key);

    // Copy data into temp
    strcpy(temp, data);

    // Append keyLen - 1 zeros
    for (i = 0; i < keyLen - 1; i++)
        temp[dataLen + i] = '0';

    temp[dataLen + keyLen - 1] = '\0';

    // CRC division
    for (i = 0; i < dataLen; i++)
    {
        if (temp[i] == '1')
            xorOperation(temp, key, i, keyLen);
    }

    printf("CRC: ");

    // Print remainder
    for (i = dataLen; i < dataLen + keyLen - 1; i++)
        printf("%c", temp[i]);

    printf("\n");

    // Print transmitted data
    printf("Transmitted data: %s", data);

    for (i = dataLen; i < dataLen + keyLen - 1; i++)
        printf("%c", temp[i]);

    printf("\n");

    return 0;
}
