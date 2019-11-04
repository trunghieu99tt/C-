int step(int n)
{
    int res=0;
    while(n)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}
int mostFrequentDigitSum(int n) {
    vector<int> temp1;
    int res,max;
    while(n)
    {
        temp1.push_back(n);
        n=n-step(n);
    }
    temp1.push_back(0);
    for (auto &i:temp1)
        i=step(i);
    res=temp1[0];
    max=count(temp1.begin(),temp1.end(),res);
    for (auto i:temp1)
    {
        int k=count(temp1.begin(),temp1.end(),i);
        if(k>max)
        {
            res=i;
            max=k;
        }
        else if(k==max && i>res)
            res=i;
    }
    return res;
}
