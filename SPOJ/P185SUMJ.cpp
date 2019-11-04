#include<bits/stdc++.h>
 
#define forn(i,n) for (i=0;i<n;++i)
#define for1(i,n) for (i=1;i<=n;++i)
#define fore(i,l,r) for (i=l,i<=r;++i)
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
	int n, a,b,counter=0;
	cin>>n>>a>>b;
	int single[a]={0},couple[b]={0},i,j,temp;
	forn(j,n)
	{
		cin>>temp;
		if(temp==1)
		{
			bool flag=0;
			for(auto &i:single)
				if(i==0)
				{
					flag=1;
					i++;
					break;
				}
			if(flag==0)
			{
				for(auto &i:couple)
					if(i==1 || i==0)
					{
						flag=1;
						i++;
						break;
					}
			}
			if(flag==0)
			{
//				cout<<"group "<<j<<" must be denied"<<endl;
				counter++;
			}
		}
		else
		{
			bool flag=0;
			for(auto &i:couple)
				if(i==0)
				{
					flag=1;
					i=2;
					break;
				}
			if(flag==0) 
			{
//				cout<<"group "<<j<<" must be denied"<<endl;
				counter+=2;
			}
		}
	}
	cout<<counter;
} 
