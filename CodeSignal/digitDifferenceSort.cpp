int diff(int n)
{
    int max=0,min=9;
    while(n)
    {
        int k=n%10;
        if(k>max) max=k;
        if(k<min) min=k;
        n/=10;
    }
    return max-min;
}
std::vector<int> digitDifferenceSort(std::vector<int> a) {
    if(a.empty()) return a;
    std::stable_sort(a.begin(),a.end(),[&](int a1,int a2){
        return diff(a1)<=diff(a2);
    });
    return a;
}
