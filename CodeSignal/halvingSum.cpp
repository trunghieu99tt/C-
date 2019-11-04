int halvingSum(int n) {
    int res=0;
    while(n!=1)
    {
        res+=n;
        n/=2;
    }
    return res+1;
}
