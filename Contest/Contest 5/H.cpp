#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)
#define pb push_back

typedef vector<char> vc;

typedef vector<vc> vvc;

typedef vector<vvc> vvvc;

typedef pair<int,int> pii;

typedef pair<int,pii> piii;

#define mp make_pair

void trunghieu()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,i,j,k;
		cin>>a>>b>>c;
		int hs, xs, ys, he,xe,ye;
		vvvc matrix;
		forn(i,a)
		{
			vvc temp(b,vc(c));
			forn(j,b)
				forn(k,c)
				{
					cin>>temp[j][k];
					if(temp[j][k] == 'S')
					{
						hs = i; xs = j; ys = k;
					}
					if(temp[j][k] == 'E')
					{
						he = i; xe = j; ye = k;
					}
				}
			matrix.pb(temp);
		}
		queue<piii> q;
		q.push(mp(hs,mp(xs,ys)));
		map<piii,int> visited, path;
		visited[mp(hs,mp(xs,ys))] = 1;
		path[mp(hs,mp(xs,ys))] = 0;
		int dh[] = {1,-1}, dr[] = {-1,0,0,1}, dc[] = {0,-1,1,0};
		int flag = 0;
		while(!q.empty())
		{
			piii u = q.front();q.pop();
			int h = u.first, x = u.second.first, y = u.second.second;
			if(h == he && x == xe && y == ye)
			{
				cout<<path[u]<<endl;
				flag = 1;
				break;
			}
			for(int i = 0;i<2;i++)
			{
				int h1 = h + dh[i];
				if(h1 >= 0 && h1 < a && visited[mp(h1,mp(x,y))] == 0 && matrix[h1][x][y] != '#')
				{
					piii tmp = mp(h1, mp(x,y));
					q.push(tmp);
					visited[tmp] = 1;
					path[tmp] = path[u] + 1;
				}
			}
			for(int j = 0;j<4;j++)
			{
				int x1 = x + dr[j], y1 = y + dc[j];
				if(x1 >=0 && y1>=0 && x1 < b && y1 < c && visited[mp(h, mp(x1,y1))] == 0 && matrix[h][x1][y1] != '#')
				{
					piii tmp = mp(h,mp(x1,y1));
					q.push(tmp);
					visited[tmp] = 1;
					path[tmp] = path[u] + 1;
				}
			}
		}
		if(!flag)
			cout<<-1<<endl;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     //freopen("output.txt","w",stdout);
    // #endif
    trunghieu();
    return 0;
}