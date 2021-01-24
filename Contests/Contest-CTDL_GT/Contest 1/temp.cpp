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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,w;
        cin>>n>>m>>w;
        int weight[n][n],i,j,u,v;
        forn(i,n)
            forn(j,n)
                if(i == j)
                    weight[i][j] = 0;
                else weight[i][j] = INT_MAX;
        forn(i,m)
        {
            int s,e,c;
            cin>>s>>e>>c;
            s--;e--;
            weight[s][e] = c;
            weight[e][s] = c;
        }
        forn(i,w)
        {
            int s,e,c;
            cin>>s>>e>>c;
            s--;e--;
            weight[s][e] = -c;
        }
        vi dist(n,0); dist[0] = 0;
        queue<int> q;
        q.push(0);
        vi in_queue(n, 0); in_queue[0] = 1;
        vi count_in_queue(n,0); count_in_queue[0] = 1;
        int cycle = 0;
        while(!q.empty())
        {
            int u = q.front();q.pop();in_queue[u] = 0;
            forn(v,n)
            {
                if(weight[u][v]!= INT_MAX)
                {
                    if(dist[u] + weight[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + weight[u][v];
                        if(!in_queue[v])
                        {
                            q.push(v);
                            count_in_queue[v]++;
                            if(count_in_queue[v] >= n-1)
                            {
                                cout<<"NO\n";
                                cycle = 1;
                                break;
                            }
                            in_queue[v] = 1;
                        }
                    }
                }
            }
        }
        if(!cycle)
        {
            forn(i,n)
                if(count_in_queue[i] >= n-1)
                {
                    cout<<"NO\n";
                    cycle = 1;
                    break;
                }
            if(!cycle)
                cout<<"YES\n";
        }
    }
    return 0;
}