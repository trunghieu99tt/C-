int lastDigit(int a, int b) {
    int res=1;
    for(int i=0;i<b;i++)
        res=(res*a)%10;
    return res;
}
