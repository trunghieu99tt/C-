int eulersTotientFunction(int n) {
    int ans = 0;
    for(int i = 1;i<=n;i++)
        if(__gcd(i,n) == 1)
            ans++;
    return ans;
}
