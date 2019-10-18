#include<bits/stdc++.h>

using namespace std;

/*-----------------------------------GENERAL USER's DEFINITION ------------------------------*/
#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

/*---------------------------------------------------------------------------------------*/

bool check(vi v, int n){
	for(int i=0; i<=n/2; ++i){
		if(v[i]!= v[n-i-1]){
			return false;
		}
	}
	return true;
}

vi saveMod(vi v, int minV, int n){
	vi m;
	for(int i=minV; i>=1; --i){
		if(v[n-1] % i == v[0]%i){
			m.push_back(i);
		}
	}
	return m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n, minV=0, index=0;
    cin>>n;
    vi v(n);
    for(int i=0; i<n; ++i){
    	cin>>v[i];
    	if(v[i]>minV){
    		minV = v[i];
    		index = i;
    	}
    }
    if(check(v, n)){
    	cout<<"-1";
    }
    else {
    	vi m;
    	m = saveMod(v, minV, n);

    	bool f= true;
    	for(auto x: m){
    		f = true;
    		for(int i=0; i<=n/2; ++i){
    			if(v[i] % x != v[n-i-1]% x){
    				f = false;
    				break;
    			}
    		}
    		if(f){
    			cout<<x;
    			break;
    		}
    	}
    	if(!f) cout<<"-1";
    }


    
    return 0;
}