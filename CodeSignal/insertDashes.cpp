std::string insertDashes(std::string s) {
    string res="";
    for (int i=0;i<s.length();i++)
    {
        res+=s[i];
        if(s[i+1]!=' ' && s[i]!=' ' && i+1<s.length()) res+='-';
    }
    return res;
}
