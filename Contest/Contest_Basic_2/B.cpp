#include<bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
bool checker(ll n)
{
	while(n)
	{
		int digit = n%10;
		if(digit!=2 && digit!=5 && digit!=7 && digit!=3)
			return 0;
		n/=10;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    getline(cin,s);
    stringstream ss(s);
    map<ll,int> counter, visited;
    string token;
    vll ans;
    while(ss>>token)
    {
    	ll number = atoll(token.c_str());
    	if(checker(number))
    	{
    		if(visited[number] == 0)
    		{
    			ans.pb(number);
    			visited[number] = 1;
    		}
    		counter[number]++;
    	}
    }
    for(int i = 0;i<ans.size();i++)
    	cout<<ans[i]<<" "<<counter[ans[i]]<<endl;
    return 0;
}