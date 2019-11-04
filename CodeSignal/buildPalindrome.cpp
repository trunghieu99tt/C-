bool CheckPalindrome(string s)
{
    auto s1=s;
    reverse(s1.begin(),s1.end());
    return (s1==s);
}
std::string buildPalindrome(std::string st) {
	if(CheckPalindrome(st)==true) return st;
    string temp=st;
    reverse(temp.begin(),temp.end());
    for (int i=0;i<st.length();i++)
    {
        if(CheckPalindrome(st+temp.substr(temp.length()-1-i)))
            return st+temp.substr(temp.length()-1-i);
    }
    return st+temp.substr(1);
}

