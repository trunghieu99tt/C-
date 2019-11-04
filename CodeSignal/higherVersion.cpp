#define pb push_back
#define tr(i) stoi(i,nullptr,10)
#define vi vector<int>
vi split(string s)
{
    vi t;
    int i=0;
    string temp="";
    while(i<s.length())
    {
        if(s[i]!='.') temp+=s[i];
        else{
            t.pb(tr(temp));
            temp="";
        }
        ++i;
    }
    if(temp!="") t.pb(tr(temp));
    return t;
}
bool higherVersion(std::string s1, std::string s2) {
    if(s1.find('.')==string::npos && s2.find('.')==string::npos)
        return tr(s1)>tr(s2);
    vi t1=split(s1),t2=split(s2);
    for (int i=0;i<t1.size();i++)
    {
        if(t1[i]>t2[i]) return 1;
        if(t2[i]>t1[i]) return 0;
    }
    return 0;
}
