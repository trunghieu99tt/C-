std::vector<std::vector<int>> spiralNumbers(int n) {
    vector<vector<int>> a (n,vector<int>(n));
    int d=0, gt=1, hang=n-1, cot=n-1,i;
	while(d<=n/2)
	{
		for(i=d;i<=cot;i++) a[d][i]=gt++;
		for(i=d+1;i<=hang;i++) a[i][cot]=gt++;
		for(i=cot-1;i>=d;i--) a[hang][i]=gt++;
		for(i=hang-1;i>d;i--) a[i][d]=gt++;
	  d++; hang--; cot--;
	}
    return a;
}
