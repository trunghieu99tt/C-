#define pb push_back
std::string reverseParentheses(std::string s) {
    vector<char> temp;
	string res="";
	int i;
	i=0;
	while(i<s.length() && s[i]!='(') 
	{
		res+=s[i];
		i++;
	}
    if(i==s.length()) return res;
	temp.pb('0');
	i++;
	while(i<s.length())
	{
		if(s[i]!='(' && s[i]!=')') temp.pb(s[i]);
		else if(s[i]=='(') temp.pb('0');
		else if(s[i]==')')
		{
			string tem="";
			while(temp[temp.size()-1]!='0')
			{
				tem+=temp[temp.size()-1];
				temp.pop_back();
			}
			temp.pop_back();
			for (auto k:tem)
				temp.pb(k);
		}
		i++;
	}
	for (auto i:temp)
		res+=i;
    return res;
}
