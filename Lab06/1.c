#include <stdio.h>
int stack[100], c, n, top, x, i;
void push()
{
    if (top >= n - 1)
        printf("STACK is over flow");
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top <= -1)
        printf("Stack is under flow");
    else
    {
        printf("The popped elements is %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK \n");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\n Press Next Choice");
    }
    else
        printf("\n The STACK is empty");
}
int main()
{
    top = -1;
    printf("\n Enter the size of STACK:");
    scanf("%d", &n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("EXIT POINT ");
            break;
        }
        default:
        {
            printf("Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (c != 4);
    return 0;
}
