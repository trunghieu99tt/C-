bool evenDigitsOnly(int n) {
	string s=to_string(n);
    for (int i=0;i<s.length();i++)
        if((s[i]-'0')%2!=0) return 0;
    return 1;
}
