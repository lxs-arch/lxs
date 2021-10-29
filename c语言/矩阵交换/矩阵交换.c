#include<stdio.h>
int main()
{
    int n  = 0;
    int m  = 0;
    int i = 0;
    int j = 0;
        int arr[10][10] = {0};
    scanf("%d %d",&n,&m);
    for(i = 0;i<n;i++)
    {
    for(j = 0;j<m;j++)
    {
        scanf("%d",&arr[i][j]);
    }
    }
    int k = 0; //进行几次转置
    scanf("%d",&k);
    for(int r=0;r<k;r++)
    {
        char t = 0;
        int a = 0;
        int b =0;
        scanf(" %c %d %d",&t,&a,&b);
        if(t == 'r')
        {
            //交接arr[a-1][i];
            //交接arr[b-1][i] 行交接
            for(i=0;i<m;i++)
            {
                int tmp = arr[a-1][i];
               arr[a-1][i] = arr[b-1][i];
               arr[b-1][i] = tmp;   
            }
        }
        else if(t =='c')
        {
            //交接列
            for(i=0;i<n;i++)
            {
                int tmp = arr[i][a-1];
               arr[i][a-1] = arr[i][b-1];
               arr[i][b-1]  = tmp;
            }
        } 
    }
    for(i = 0;i<n;i++)
    {
    for(j = 0;j<m;j++)
    {
        printf("%d ",arr[i][j]);
    }
        printf("\n");
    }
    
    
    
    return 0;
}