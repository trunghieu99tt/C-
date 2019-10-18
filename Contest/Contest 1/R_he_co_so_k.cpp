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

string convert(int a, int k)
{
	string s = "";
	while(a)
	{
		s+=(a%k + '0');
		a/=k;
	}
	reverse(all(s));
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int k, a, b;
    cin>>k>>a>>b;
    string aInBase = convert(a,k),
    	   bInBase = convert(b,k);
   	int n = max((int)aInBase.size(), (int)bInBase.size());
   	while(aInBase.size() < n)
   		aInBase = '0' + aInBase;
   	while(bInBase.size() < n)
   		bInBase = '0' + bInBase;
   	int reminder = 0, i;
   	string ans = "";
   	for(i = n-1;i>=0;i--)
   	{
   		int tmp = (aInBase[i] - '0') + (bInBase[i] - '0') + reminder;
   		if(tmp >= k)
  		{
   			reminder = 1;
   			tmp%=k;
   		}
   		else reminder = 0;
   		ans = char(tmp + 48) + ans;
   	}
   	cout<<ans;
    return 0;
}