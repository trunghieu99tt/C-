int increasingNumber(int x, int n) {
    for (int i = 2; i <= n; i++)
        while (x%i!=0)
            x++;
    return x;
}
