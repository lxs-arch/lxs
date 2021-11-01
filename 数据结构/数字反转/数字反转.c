int reverse(int x){
    int ret=0;
    while(x!=0){
        if(ret<INT_MIN/10||ret>INT_MAX/10){
            return 0;
        }
        int a=x%10;
        ret=ret*10+a;
        x=x/10;
    }
        return ret;
}