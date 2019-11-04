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
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef double ld;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	n = 4*n+(n+1);
	int i,j;
	vector<vector<string>> res;
	string temp,token;
	forn(i,n)
	{
		cin>>temp;
		if(i%5)
		{
			vector<string> a;
			stringstream ss(temp);
			while(getline(ss,token,'#'))
			{
				if(token.size())
					a.pb(token);
			}
			res.pb(a);
		}
	}
	vector<string> rev;
	int r = res.size(), c = res[0].size(),counter=0;
	temp="";
	for(j=0;j<c;j++)
	{
		for(i=0;i<r;i++)
		{
			temp+=res[i][j];
			counter++;
			if(counter%4==0)
			{
				rev.pb(temp);
				temp="";
			}
		}
	}
	int stt1=0,stt2=0,stt3=0,stt4=0,stt5=0;
	for(auto i:rev)
	{
		int counter = count(all(i),'*');
		if(counter==0) stt1++;
		else if(counter==4) stt2++;
		else if(counter==8) stt3++;
		else if(counter==12) stt4++;
		else stt5++;
	}
	cout<<stt1<<" "<<stt2<<" "<<stt3<<" "<<stt4<<" "<<stt5; 
	return 0;
} 
