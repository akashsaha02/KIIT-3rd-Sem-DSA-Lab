#include <stdio.h>
int total(int num);
int main()
{
    int num;
    printf("enter the number: ");
    scanf("%d", &num);
    printf("Total sum of %d number is %d", num, total(num));
}
int total(int num)
{
    if (num != 0)
    {
        return num + total(num - 1);
    }
    else
    {
        return num;
    }
}
