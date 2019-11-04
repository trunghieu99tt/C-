int createAnagram(std::string s, std::string t) {
    int a[27]={0},b[27]={0},i,counter=0;
    for (i=0;i<s.length();i++)
    {
        a[s[i]-'A']++;
        b[t[i]-'A']++;
    }
    for (i=0;i<27;i++)
        counter+=abs(a[i]-b[i]);
    return counter/2;
}
