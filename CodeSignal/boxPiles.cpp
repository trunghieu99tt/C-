int boxPiles(std::vector<int> a) {
    sort(a.begin(),a.end());
    int check[a.size()]={0},i,used=0,res=0,height;
    while(used<a.size())
    {
        height=0;
        for (i=0;i<a.size();i++)
        {
            if(a[i]>=height && check[i]==0)
            {
                height++;
                check[i]=1;
                used++;
            }
        }
        res++;
    }
    return res;
}
