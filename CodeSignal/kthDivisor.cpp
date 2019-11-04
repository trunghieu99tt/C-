int kthDivisor(int n, int k) {
	int i,counter=0;
    for (i=1;i<=n;i++)
    {
        if(n%i==0) counter++;
        if(counter==k) return i;
 	}
    return -1;
}
