#include <stdio.h>
int main()
{
    static int arr[100][100];
    int r, c, ctr = 0;
    printf("Enter rows: ");
    scanf("%d", &r);
    printf("Enter columns: ");
    scanf("%d", &c);
    printf("Enter elements:\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0){
                ctr++;
            }
        }
    }
    if (ctr > ((r * c) / 2)){
        printf("The matrix is sparse matrix.\n");
    }
    else{
        printf("The matrix is not a sparse matrix.\n");
    }
    printf("Number of zeros in mattrix is %d\n", ctr);
    return 0;
}