#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

ll inverserEuler(int n){return binPow(n, mod-2);}

ll C(int k, int n){vll f(n+1,1);for(int i = 2;i<=n;i++)f[i] = (f[i-1]*i)%mod;return (f[n] * ((inverserEuler(f[k]) * inverserEuler(f[n-k]))%mod)%mod)%mod;}

/* Extend Euclid: ax + by = c; */
ll x, y;
 
void extendEuclid(ll a, ll b){if(b == 0){x = 1;y = 0;return;}extendEuclid(b,a%b);ll x1 = y, y1 = x - (a/b) * y;x = x1;y = y1;}
// nghiem : x + (b/d)*k, y - (a/d) * k;

/*--------------------------------------------------------------------------------------------------*/

bool check(string a, string b)
{
	sort(all(a));
	sort(all(b));
	int cnt = 0,i,n = a.size();
	forn(i,n)
	{
		if(a[i]!=b[i])
			cnt++;
		if(cnt > 1)
			return 0;
	}
	return cnt == 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    #ifndef ONLINE_JUDGE
    	freopen("input.txt","r",stdin);
    	//freopen("output.txt","w",stdout);
    #endif
    map<string,vs> adjList;
    map<pair<string,string>,int> cmp, checker;
    int n;
    cin>>n;
   	string words[n];
   	int i,j;
   	forn(i,n)
   		cin>>words[i];
   	forn(i,n)
   	{
   		for(j = i+1;j<n;j++)
   		{
   			if(cmp[{words[i],words[j]}] == 0)
   			{
   				int x = check(words[i],words[j]);
   				checker[{words[i],words[j]}] = x;
   				checker[{words[j], words[i]}] = x;
   				cmp[{words[i],words[j]}] = 1;
   				cmp[{words[j],words[i]}] = 1;
   			}
   			if(checker[{words[i],words[j]}])
   			{
   				adjList[words[i]].pb(words[j]);
   				adjList[words[j]].pb(words[i]);
   			}
   		}
   	}
   	forn(i,n)
   	{
   		cout<<words[i]<<" : ";
   		for(auto j:adjList[words[i]])
   			cout<<j<<" ";
   		cout<<endl;
   	}
   	queue<string> q;
   	q.push(words[0]);
   	map<string,int> cnt, visited;
   	cnt[words[0]] = 1;
   	map<string,string> pre;
   	while(!q.empty())
   	{
   		string u = q.front();
   		q.pop();
   		for(auto i:adjList[u])
   		{
   			if(visited[i] == 0)
   			{
   				cnt[i] = cnt[u] + 1;
   				pre[i] = u;
   				if(i == words[n-1])
   				{
   					cout<<cnt[i];
   					vs ans;
   					string s = i;
   					while(pre[s]!= words[0])
   					{
   						ans.pb(s);
   						s = pre[s];
   					}
   					ans.pb(words[0]);
   					reverse(all(ans));
   					for(auto i:ans)
   						cout<<i<<endl;
   					return 0;
   				}
   				q.push(i);
   				visited[i] = 1;
   			}
   		}
   	}
   	cout<<"FAIL";
    return 0;
}