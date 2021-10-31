#include <stdio.h>
int main(){
    long long a,b,m,n,c;
    scanf("%lld %lld",&a,&b);
    c=a*b;
    while(a&&b){
        if(a>b) a%=b;
        else b%=a;
    }
    m=a>b?a:b;
    printf("%lld\n",m+c/m);
}