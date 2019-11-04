string decodeString(string s) {
    vector<char> temp;
    int i,n=s.size(),j,k;
    string save="";
    for(i=0;i<n;i++)
    {
        if(s[i] == '[') temp.push_back('$');
        else if(s[i]==']')
        {
            string save="";
            while(temp.back()!='$')
            {
                save+=temp.back();
                temp.pop_back();
            }
            temp.pop_back();
            reverse(save.begin(),save.end());
            string num="";
            while(isdigit(temp.back()) && temp.size()>=0)
            {
                num+=temp.back();
                temp.pop_back();
            }
            reverse(num.begin(),num.end());
            int l = stoi(num);
            string s1="";
            for(k=0;k<l;k++)
                    s1+=save;
            for(auto j:s1)
                temp.push_back(j);
        }
        else temp.push_back(s[i]);
    }
    string res="";
    for(auto i:temp)
        res+=i;
    return res;
}
