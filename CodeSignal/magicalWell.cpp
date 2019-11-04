int magicalWell(int a, int b, int n) {
    int sum=0,i;
    for (i=0;i<n;i++)
    {
        sum+=(a*b);
        a++;
        b++;
    }
    return sum;
}
