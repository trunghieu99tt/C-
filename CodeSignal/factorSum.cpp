int SumDigit(int n)
{
   int sum=0,i;
    for (i=2;i<=n;i++)
    {
        while (n%i==0)
        {
            sum+=i;
            n/=i;
        }
    }
    return sum;
}
int factorSum(int n) {
    while (n!=SumDigit(n))
    {
        n=SumDigit(n);
    }
    return n;
}
