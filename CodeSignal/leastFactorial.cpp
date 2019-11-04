int leastFactorial(int n) {
    int product =1,i=1;
    while(product< n)
    {
        product*=i;
        i++;
    }
    return product;
}
