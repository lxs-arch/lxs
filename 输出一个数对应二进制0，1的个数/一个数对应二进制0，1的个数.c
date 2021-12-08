#include<stdio.h>
int main(){
    int x,a=0,b=0;
    scanf("%d",&x);
    while(x>0){
        if(x%2==1){
            a++;
        }
        else b++;
        x/=2;
    }
    printf("%d %d",a,b);
    return 0;
}