int appleBoxes(int k) {
    int yellow=1,red=0;
    for (int i=2;i<=k;i++)
    {
        int t=i*i;
        i%2!=0?yellow+=t:red+=t;
    }
    return red-yellow;
}
