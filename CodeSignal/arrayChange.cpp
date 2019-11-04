int arrayChange(std::vector<int> a) {
    int counter=0;
    for (int i=1;i<a.size();i++)
    {
        while(a[i]<=a[i-1])
        {
            counter++;
            a[i]++;
        }
    }
    return counter;
}
