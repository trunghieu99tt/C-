bool isInfiniteProcess(int a, int b) {
    if(a==b) return false;
    while(1)
    {
        a++;
        b--;
        if(a>b) return true;
        else if(a==b) return false;
    }
}
