#include<bits/stdc++.h>

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    stack<char> st;
    string s;
    cin>>s;
    for(int i = 0;i<s.size();i++)
    {
    	if(st.empty())
    		st.push(s[i]);
    	else if(s[i] > st.top() && k > 0)
    	{
    		while(!st.empty() && s[i] > st.top() && k > 0 )
    		{
    			st.pop();
    			k--;
    		}
    		st.push(s[i]);
    	}
    	else st.push(s[i]);
    }
    if(k>0)
    {
    	while(k>0)
    	{
    		st.pop();
    		k--;
    	}
    }
    string ans = "";
    while(!st.empty())
    {
    	ans+= (st.top());
    	st.pop();
    }
    reverse(all(ans));
    cout<<ans;
    return 0;
}