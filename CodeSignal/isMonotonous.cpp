bool c(vector<int> a)
{
    for(int i=0;i<a.size()-1;i++)
        if(a[i]>=a[i+1]) return 0;
    return 1;
}
bool c1(vector<int> a)
{
    for(int i=0;i<a.size()-1;i++)
        if(a[i]<=a[i+1]) return 0;
    return 1;
}
bool isMonotonous(std::vector<int> a) {
    return (c(a) || c1(a));
}
