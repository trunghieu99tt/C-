std::vector<int> switchLights(std::vector<int> a) {
    for (int i=0;i<a.size();i++)
    {
        if(a[i]==1)
            for (int j=0;j<=i;j++)
                a[j]=abs(a[j]-1);
    }
    return a;
}
