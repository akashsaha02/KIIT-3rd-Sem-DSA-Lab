#include <stdio.h>
void percent_recur(int, float);
int main()
{
    float num;
    printf("Enter a value to split in percentage: ");
    scanf("%f", &num);
    percent_recur(1, num);
    return 0;
}

void percent_recur(int i, float n)
{
    if (i > 50)
    {
        return;
    }
    else
    {
        printf("%d %% = %f \n", i, (n * i) / 100);
    }
    percent_recur(i = i + 1, n);
}