#include <stdio.h>

int main()
{
    int n;
    printf("Enter matrics n X n :\n");
    scanf("%d", &n);
    int mat[n][n], upper = 0, lower = 0, tri = 0;
    printf("Enter matrics eliments:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("\t%d", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j < i && mat[i][j] == 0)
                upper = 1;
            else if (j > i && mat[i][j] == 0)
                lower = 1;
            else if (mat[i][i] != 0 && mat[i][i + 1] != 0 && mat[i + 1][i] != 0)
                tri = 1;
        }
    }
    if (lower == 1 && upper == 1)
        printf("Tri Diagonal Matrix\n");
    else if (lower == 1 && upper == 0)
        printf("Lower Triangular Matrix\n");
    else if (upper == 1 && lower == 0)
        printf("Upper Triangular Matrix\n");
    else
        printf("Normal Matrix\n");

    return 0;
}