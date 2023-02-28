#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float marks;
    char address[50];
};

int main()
{
    struct student s[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
        printf("Enter the address: ");
        scanf("%s", s[i].address);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Displaying Information:\n");
        printf("Name: ");
        printf("%s\n", s[i].name);
        printf("Roll number: %d\n", s[i].roll);
        printf("Marks: %.1f\n", s[i].marks);
        printf("Address: %s\n", s[i].address);
    }
    return 0;
}