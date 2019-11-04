bool pairOfShoes(std::vector<std::vector<int>> shoes) {
    int i,j, counter=0,n=shoes.size();
    if (n<2) return 0;
    vector<int> type,size;
    for (i=0;i<shoes.size();i++)
    {
        type.push_back(shoes[i][0]);
        size.push_back(shoes[i][1]);
    }
    int checked[n+1]={0};
    for (i=0;i<n;i++)
    {
        if(checked[i]==0)
        {
            bool flag=false;
            for (j=i+1;j<n;j++)
            {
                if( checked[j]==0 && type[j]==(1-type[i]) && size[j]==size[i])
                {
                    checked[j]=1;
                    flag=true;
                    break;
                }
            }
        if(flag==false) return 0;
        }
    }
    return 1;
}
