#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)

typedef pair<int,int> pii;

const int maxn = 1e5;

int n,k;

vector<pii> a(maxn);

bool cmp(pii a, pii b)
{
	return b.first - b.second > a.first - a.second;
}

void solve()
{
	cin>>n>>k;
	int i,j;
	forn(i,n)
		cin>>a[i].first;
	forn(i,n)
		cin>>a[i].second;
	sort(a.begin(), a.begin() + n,cmp);
	long long ans = 0;
	forn(i,k)
		ans+= a[i].first;
	for(i = k;i<n;i++)
		ans+= a[i].second;
	cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    solve();
    return 0;
}