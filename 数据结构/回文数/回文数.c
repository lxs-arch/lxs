bool isPalindrome(int x){
long int y=0;
int a=x;
if(x<0){
    return false;
}
while(x){
    int t=x%10;
    y=y*10+t;
    x=x/10;
}
if(y==a){
    return true;
}
else return false;
}
//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是

