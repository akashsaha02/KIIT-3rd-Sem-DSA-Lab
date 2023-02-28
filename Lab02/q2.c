#include <stdio.h>
#include <stdlib.h>
int main()
{

  int *p;
  int n;
  printf("Enter the dynamic array size: ");
  scanf("%d", &n);
  p = (int *)malloc(n * sizeof(int));
  printf("Enter dynamic memory elements\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &p[i]);
  }
  printf("The array elements are:\n");
  for (int i = n - 1; i >= 0; i--)
  {
    printf("%d ", p[i]);
  }
  free(p);
  return 0;
}