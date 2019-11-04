#include<bits/stdc++.h>

#define forn(i,n) for (i=0;i<n;++i)
#define for1(i,n) for (i=1;i<=n;++i)
#define fore(i,l,r) for (i=l,i<=r;++i)
#define ford(i,n) for (i=n-1;i>=0;--i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mod 1073741824
using namespace std;

int countDiv(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                cnt++;
 
            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	int a, b,c,i,j,k,res=0;
	cin>>a>>b>>c;
	map<int,int> div;
	for1(i,a)
	{
		for1(j,b)
		{
			for1(k,c)
			{
				if(div.find(i*j*k)==div.end()) div.insert(make_pair(i*j*k,countDiv(i*j*k)));
					res+=div[i*j*k];
					res%=mod;
			}
		}
	}
	cout<<res;
	return 0;
}
