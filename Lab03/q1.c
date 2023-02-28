#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int c = 0, i;
    char *ptr, str[30];
    printf("Enter string: \n");
    gets(str);
    for (int i = 0; str[i]; i++)
    {
        c++;
    }
    ptr = (char *)malloc(c * sizeof(char));
    strcpy(ptr, str);
    for (int i = 0; i < c / 2;)
    {
        if (ptr[i] == ptr[c - i - 1])
            i++;
        else
            break;
    }
    if (i == c / 2)
    {
        printf("\n%s string is palindrome", str);
    }
    else
    {
        printf("\n%s string is not palindrome", str);
    }
    free(ptr);
    return 0;
}