#include<bits/stdc++.h>
using namespace std;
int main()
{
	long a,b;
	cin>>a>>b;
	long long c=a+b;
	string a1=to_string(a),b1=to_string(b),c1=to_string(c);
	while(a1.find("0")!=string::npos) a1.erase(a1.find("0"),a1.find("0")+1);
	while(b1.find("0")!=string::npos) b1.erase(b1.find("0"),b1.find("0")+1);
	while(c1.find("0")!=string::npos) c1.erase(c1.find("0"),c1.find("0")+1);
	long tempa=stoi(a1,nullptr,10),tempb=stoi(b1,nullptr,10),tempc=stoi(c1,nullptr,10);
	if(tempa+tempb==tempc)
		cout<<"YES";
	else cout<<"NO";
	return 0;
}
