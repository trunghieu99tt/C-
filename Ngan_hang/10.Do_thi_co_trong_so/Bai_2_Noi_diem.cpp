#include<bits/stdc++.h>

using namespace std;

typedef pair<double,double> pdd;

double dist(pdd a, pdd b){
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

class UnionFind{
private:
	map<pdd, pdd> p;
	map<pdd, int> rank;
public:
	UnionFind(vector<pdd> point)
	{
		for(auto i:point)
		{
			p[i] = i;
			rank[i] = 0;
		}
	}
	pdd findSet(pdd u)
	{
		return (p[u] == u) ? u : (p[u] = findSet(p[u]));
	}
	bool unionSet(pdd a, pdd b)
	{
		auto xx = findSet(a), yy = findSet(b);
		if(xx == yy)
			return 0;
		if(rank[xx] == rank[yy])
			rank[xx]++;
		if(rank[xx] > rank[yy])
			p[xx] = yy;
		else p[yy] = xx;
		return 1;
	}
};

void solve()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		double ans = 0.0;
		cin>>n;
		vector<pdd> point(n);
		vector<pair<double,pair<pdd,pdd>>> edge;
		for(auto &i:point)
			cin>>i.first>>i.second;
		for(auto i:point)
			for(auto j:point)
				if(i!=j)
				{
					double d = dist(i,j);
					edge.emplace_back(make_pair(d, make_pair(i,j)));
				}
		sort(edge.begin(),edge.end());
		UnionFind UF(point);
		for(auto i:edge)
		{
			auto u = i.second.first, v = i.second.second;
			if(UF.unionSet(u,v))
				ans+= i.first;
		}
		cout<<setprecision(6)<<fixed<<ans<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	solve();
	return 0;
}