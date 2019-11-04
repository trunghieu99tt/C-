bool isLucky(int n) {
    string s=to_string(n);
    int sum=0,i;
    for (i=0;i<s.length()/2;i++) sum+=(s[i]-'0');
    for (i=s.length()/2;i<s.length();i++) sum-=(s[i]-'0');
    return (sum==0);
}
