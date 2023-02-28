#include <stdio.h>
struct date
{
    int day;
    int month;
    int year;
};
void sort(struct date d[], int n);
int main()
{
    struct date d[100];
    int n, i;
    printf("Enter the number of the dates:\n");
    scanf("%d", &n);
    printf("Enter dates\n");
    for (i = 0; i < n; i++)
        scanf("%d %d %d", &d[i].day, &d[i].month, &d[i].year);
    sort(d, n);
    printf("Dates in ascending order\n");
    for (i = 0; i < n; i++)
        printf("%d %d %d ", d[i].day, d[i].month, d[i].year);
    return 0;
}
void sort(struct date d[], int n)
{
    struct date temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (d[j].year > d[j + 1].year)
            {
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }
}