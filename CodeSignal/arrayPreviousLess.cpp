std::vector<int> arrayPreviousLess(std::vector<int> items) {
    int i,j;
    vector<int> result;
    result.push_back(-1);
    for (i=1;i<items.size();i++)
    {
        bool flag=false;
        for (j=i-1;j>=0;j--)
        {
            if(items[j]<items[i])
            {
                flag=true;
                result.push_back(items[j]);
                break;
            }
        }
        if(flag==false) result.push_back(-1);
    }
    return result;
}
