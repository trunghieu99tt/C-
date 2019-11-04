bool coolString(std::string s) {
    for (int i=0;i<s.length();i++)
    {
        if( s[i]>='a' && s[i]<='z' && s[i+1]>='a' && s[i+1]<='z' ) return 0;
        else  if( s[i]>='A' && s[i]<='Z' && s[i+1]>='A' && s[i+1]<='Z' ) return 0;
        else if(s[i]<'A' || s[i]>'Z' && s[i]<'a' || s[i]>'z') return 0;
    }
    return 1;
}
