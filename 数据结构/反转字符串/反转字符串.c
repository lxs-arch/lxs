char* solve(char* str ) {
    char* left=str;
    char* right=str+strlen(str)-1;
    while(left<right){
        char t;
        t=*left;
        *left=*right;
        *right=t;
        left++;
        right--;
    }
    return str;
}