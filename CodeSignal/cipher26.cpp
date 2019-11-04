std::string cipher26(std::string message) {
    string r="";
    int s=0,pr=0;
    for (auto i:message)
    {
        int t=i-97;
        s=t-pr;
        if(s<0) s+=26;
        r+=char(s+97);
        pr=t;
    }
    return r;
}
