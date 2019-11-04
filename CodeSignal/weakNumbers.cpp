int countDiv(int n)
{
    int i,counter=0;
    for(i=1;i*i<=n;i++)
        if(n%i==0)
        {
            if(i!=n/i) counter+=2;
            else counter++;
        }
    return counter;
}
int weakNess(int n)
{
    int divn=countDiv(n),counter=0;
    for(int i=1;i<n;i++)
        if(countDiv(i)>divn) counter++;
    return counter;
}
std::vector<int> weakNumbers(int n) {
    map<int,int,greater<int>> res;
    int i;
    for(i=1;i<=n;i++)
    {
        int weak=weakNess(i);
        if(res.find(weak)==res.end()) res.insert(make_pair(weak,1));
        else res[weak]++;
    }
    auto it=res.begin();
    return {it->first,it->second};
}
