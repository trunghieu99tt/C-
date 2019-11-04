bool isSmooth(std::vector<int> a) {
    int mid,n=a.size();
    if(n%2==0) mid=a[n/2-1]+a[n/2];
    else mid=a[n/2];
    return (mid==a[0] && a[0]==a[n-1]);
}
