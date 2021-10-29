#include<stdio.h>
int main(void){
	int x,j;
	int t=1,count=1;
	while(scanf("%d",&x)!=EOF){
		count=1;
	for(int i=1;i<=x;i++){
		j=1;
		t=count;
		for(;t<=x-1;t++){
				printf(" ");
		}	
         count++;
		for(int j=1;j<=i;j++){
			printf("* ");
		}
		printf("\n");
	}}
    return 0;
	}