#define pb push_back
#define all(x) (x).begin(),(x).end()
vector<string> convert(string s)
{
	vector<string> res;
	int i=0,n=s.length();
	while(i<n)
	{
		string temp="";
		if(isdigit(s[i]))
		{
			while(isdigit(s[i]) && i<n)
			{
				temp+=s[i];
				i++;
			}
		}
		else {
			temp+=s[i];
			i++;
		}
        res.pb(temp);
	}
	return res;
}
bool alphanumericLess(std::string s1, std::string s2) {
    vector<string> temp=convert(s1),temp2=convert(s2);
	int i=0,j=0,n1=temp.size(),n2=temp2.size();
	while(i<n1 && j<n2)
	{
		if(isdigit(temp[i][0]) && isdigit(temp2[j][0])==false)
		    return 1;
		else if(isdigit(temp[i][0])==false && isdigit(temp2[j][0]))
		    return 0;
		else if(isdigit(temp[i][0]) && isdigit(temp2[j][0]))
		{
            if(temp[i].size()>=19 || temp2[j].size()>=19)
                return (temp[i]<temp2[j]);
            else
            {
                int num1=stoll(temp[i],nullptr,10),num2=stoll(temp2[j],nullptr,10);
			    if(num1<num2)
			        return 1;
			    else if(num1>num2)
			        return 0;
            }
		}
		else
		{
			if(temp[i]>temp2[j])
			    return 0;
			else if(temp[i]<temp2[j])
			    return 1;
		}
		i++;
		j++;
	}
	if(i<n1 && j>=n2)
	    return 0;
	else if(i>=n1 && j<n2)
	    return 1;
	else
	{
		int k=0,l=0;
		for(k=0;k<temp.size();k++)
		{
			if(isdigit(temp[k][0]) && isdigit(temp2[k][0]))
			{
				int c1=count(all(temp[k]),'0'),c2=count(all(temp2[k]),'0');
                return c1>c2;
			}
		}
	}
	return 0;
}
