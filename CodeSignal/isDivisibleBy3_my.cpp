std::vector<std::string> isDivisibleBy3(std::string s) {
    int t=0,i,v;
    for (i=0;i<s.length();i++)
        if(s[i]=='*')
        {
            v=i;
            break;
        }
    for (auto i:s)
        if(i!='*') t+=i-'0';
    vector<string> res;
    string temp;
    for (i=0;i<=9;i++)
    {
        temp=s;
        temp[v]=(i+'0');
        if((t+i)%3==0) res.push_back(temp);
    }
    return res;
}
