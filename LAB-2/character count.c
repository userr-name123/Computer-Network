#include <stdio.h>
#include <string.h>

int main()
{
    char data[100];
    int count;

    printf("Enter the data: ");
    scanf("%s", data);

    count = strlen(data);

    printf("Character count: %d\n", count);
    printf("Framed data: %d%s\n", count, data);

    return 0;
}
