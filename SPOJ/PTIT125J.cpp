#include<bits/stdc++.h>

#define forn(i,n) for (i=0;i<n;++i)
#define for1(i,n) for (i=1;i<=n;++i)
#define fore(i,l,r) for (i=l;i<=r;++i)
#define ford(i,n) for (i=n-1;i>=0;--i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	char a[n][n];
	int i,j;
	forn(i,n)
		forn(j,n)
			cin>>a[i][j];
	int way1=0,way2=0,way3=0,way4=0;
	forn(i,n)
		forn(j,n)
		{
			if(a[i][j]!='.')
			{
				way1=way2=way3=way4=0;
				char comp = a[i][j];
				if(i-1>=0 && j-1 >=0 && a[i-1][j-1] == comp) way1++;
				if(i+1 < n && j+1 < n && a[i+1][j+1]==comp) way1++;
				if(i-1>=0 && j+1<n && a[i-1][j+1]==comp) way2++;
				if(i+1<n && j-1>=0 && a[i+1][j-1]==comp) way2++;
				if(j-1>=0 && a[i][j-1]==comp) way3++;
				if(j+1<n && a[i][j+1]==comp) way3++;
				if(i-1>=0 && a[i-1][j]==comp) way4++;
				if(i+1<n && a[i+1][j]==comp) way4++;
				if(way1==2 || way2==2 || way3==2 || way4==2)
				{
					cout<<comp;
					return 0;
				}
			}
		}
	cout<<"ongoing";
	return 0;
}
