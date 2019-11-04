int rounders(int n) {
    int tmp=0, dem=1;
	while(n/10!=0)
	{
		tmp=(n%10+tmp>=5);
		n/=10; dem*=10;
	}
	return (n+tmp)*dem;
}
