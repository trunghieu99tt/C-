#include<bits/stdc++.h>

using namespace std;

typedef pair<long long,long long> ii;
typedef pair<long long,long long> pli;

const long long inf = 1e18;
const long long maxn = 1e5 + 5;

long long n,m;

vector<pli> adjList[maxn];

long long dist[maxn], cnt[maxn], minDist  = 0;

void Dijkstra(long long s, long long f, long long n){
	for(long long i = 1;i<=n;i++)
		dist[i] = inf;
	memset(cnt,0,sizeof(cnt));
	dist[s] = 0;
	cnt[s] = 1;
	priority_queue<pli, vector<pli> , greater<pli>> q;
	q.push(pli(0,s));
	while(!q.empty())
	{
		pli u = q.top();q.pop();
		long long v = u.second, c = u.first;
		for(auto e:adjList[v])
		{
			long long v2 = e.second, c2 = e.first;
			if( c + c2 > dist[v2]) continue;
			else if(c + c2 == dist[v2])
				cnt[v2] += cnt[v];
			else
			{
				dist[v2] = c + c2;
				cnt[v2] = cnt[v];
				q.push(pli(dist[v2],v2));
			}
		}
	}
	minDist = dist[f];
	cout<<minDist<<" "<<cnt[f];
}

void solve()
{
	cin>>n>>m;
	long long i,j, u, v,k,c;
	for(i = 0;i<m;i++)
	{
		cin>>u>>v>>c;
		adjList[u].push_back({c,v});
		adjList[v].push_back({c,u});
	}
	Dijkstra(1,n,n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}