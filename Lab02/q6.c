#include<stdio.h>
#include<stdlib.h>

void nozero(int n,int (*a)[n])
{
int i,j;
int count =0;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(*(*(a+i)+j)!=0)
        {
            count ++;
        }
    }
}   
printf("No. of non zero elements :%d",count); 
}

void above(int n,int(*a)[n])
{
    int i,j;
    int add =0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j>i){
                add +=a[i][j];
            }
        }
    } 
    printf("\nSum of elements above leading diagonal : %d",add);
}

void below(int n,int(*a)[n])
{
int i,j;
printf("\nelements below minor diagonal :\n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if((i+j)>((n+1)-2)){
            printf("%d\t",a[i][j]);
        }
    }
}
}
void product1(int n,int (*a)[n]){
    int i,j;
    int product1 =1;
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(i==j){
            product1 = product1*(*(*(a+i)+j));
        }
    }
    }
    printf("\nproduct of major diagonal : %d",product1);
}

void product2(int n,int (*a)[n]){
    int i,j;
    int product =1;
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if((i+j)==((n+1)-2)){
            product = product*(*(*(a+i)+j));
        }
    }
    }
    printf("\nproduct of minor diagonal : %d",product);
}
int main()
{
int n;
    printf("Enter size of square matrix :\n ");
    scanf("%d",&n);
    int (*a)[n]=(int*)malloc((n*n)*sizeof(int));
    printf("Enter the elements :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        } 
    }
    nozero(n,a);
    above(n,a);
    below(n,a);
    product1(n,a);
    product2(n,a);

    return 0;
}