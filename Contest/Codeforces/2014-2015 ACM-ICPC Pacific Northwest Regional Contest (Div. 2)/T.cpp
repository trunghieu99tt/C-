#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
#define whatIs(a) cout<<#a<<" is : "<<a<<endl

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;
clock_t t1,t2;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

ll inverserEuler(int n){return binPow(n, mod-2);}

ll C(int k, int n){vll f(n+1,1);for(int i = 2;i<=n;i++)f[i] = (f[i-1]*i)%mod;return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n-k]))%mod)%mod)%mod;}

/* Extend Euclid: ax + by = c;
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;
*/
/*--------------------------------------------------------------------------------------------------*/

void trunghieu()
{
    int t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	vs split;
    	int i , j , n = s.size();
    	i = 0;
    	string ope3 = s.substr(s.find('=') + 1), s2 = s.substr(0, s.find('=')),
    	ope1 = "", ope2 = "";
    	if(s[0] == '-')
    		ope1+=s[0],i = 1;
    	while(isdigit(s[i]) || s[i] == '?')
    		ope1+=s[i++];
    	char dau = s[i];
    	ope2 = s.substr(i + 1, s.find('=') - i - 1);
    	map<char,int> exist;
    	for(auto i:ope1)
    		exist[i] = 1;
    	for(auto i:ope2)
    		exist[i] = 1;
    	for(auto i:ope3)
    		exist[i] = 1;
    	int flag = 0;
    	for(char c = '0';c<='9';c++)
    	{
    		if(exist[c] == 0)
    		{
    			string t1 = ope1, t2 = ope2, t3 = ope3;
	    		for(auto &i: t1)
	    			if(i == '?')
	    				i = c;
	    		for(auto &i:t2)
	    			if(i == '?')
	    				i = c;
	    		for(auto &i:t3)
	    			if(i == '?')
	    				i = c;
	    		int n1 = stoi(t1), n2 = stoi(t2), n3 = stoi(t3);
	    		string t11 = to_string(n1), t22 = to_string(n2), t33 = to_string(n3);
	    		if(t11 == t1  && t22 == t2 && t33 == t3)
	    		{
		    			//cout<<n1<<" "<<n2<<" "<<n3<<endl;
		    		if(dau == '-' && n1 - n2 == n3 ||
		    			dau == '+' && n1 + n2 == n3 ||
		    			dau == '*' && n1 * n2 == n3)
			    		{
			    				cout<<c<<endl;
			    				flag = 1;
			    				break;
			    		}
	    		}
    		}
    	}
    	if(!flag)
    		cout<<-1<<endl;
    }
}

int main()
{
    cerr << "Program is running" << endl;
    t1 = clock();
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    trunghieu();
    t2 = clock();
    float diff ((float)t2-(float)t1);
    float seconds = diff / CLOCKS_PER_SEC;
    cerr << "\nRunning in " << seconds << " seconds" << endl;
    return 0;
}