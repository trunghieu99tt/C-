std::vector<int> alternatingSums(std::vector<int> a) {
    int sum1=0,sum2=0,i;
    for (i=1;i<=a.size();i++)
    {
        if(i%2==0) sum2+=a[i-1];
        else sum1+=a[i-1];
    }
    vector<int> b{sum1,sum2};
    return b;
}
