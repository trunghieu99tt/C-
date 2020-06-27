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

string convert(int n)
{
	string ans;
	ostringstream cv;
	cv<<n;
	ans = cv.str();
	return ans;
}

string sum(string a, string b, int n, int base)
{
	string ans = "";
	int i, add = 0;
	for(i = n- 1;i>=0;i--)
	{
		int tmp = (a[i] - '0') + (b[i] - '0') + add;
		if(tmp >= base)
		{
			add = tmp/base;
			tmp%=base;
		}
		else add = 0;
		ans = convert(tmp) + ans;
	}
	if(add!=0)
		ans = convert(add) + ans;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int k;
    string a, b;
    cin>>k>>a>>b;
    int n = max(int(a.size()), int(b.size()));
    while(a.size()!=n)
    	a = '0' + a;
    while(b.size()!=n)
    	b = '0' + b;
    cout<<sum(a,b,n,k);
    return 0;
}