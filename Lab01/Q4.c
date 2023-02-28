#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float marks;
    char address[50];
};
struct student Func1()
{
    struct student s;
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    printf("Enter the address: ");
    scanf("%s", s.address);
    return s;
}

void Display(struct student s)
{
    printf("Displaying Information:\n");
    printf("Name: ");
    printf("%s\n", s.name);
    printf("Roll number: %d\n", s.roll);
    printf("Marks: %.1f\n", s.marks);
    printf("Address: %s\n", s.address);
}
int main()
{

    int n;
    printf("Enter no of student:");
    scanf("%d", &n);
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        s[i] = Func1();
    }
    for (int i = 0; i < n; i++)
    {

        Display(s[i]);
    }

    return 0;
}