int differentDigitsNumberSearch(std::vector<int> a) {
    for (int i=0;i<a.size();i++)
    {
        string temp=to_string(a[i]);
        bool flag=true;
        for (auto j:temp)
            if(count(temp.begin(),temp.end(),j)>1)
            {
                flag=false;
                break;
            }
        if(flag==true) return a[i];
    }
    return -1;
}
