std::string reduceString(std::string s) {
    while(s[0]==s[s.length()-1] && s.length()!=0)
        s=s.substr(1,s.length()-2);
    return s;
}   
