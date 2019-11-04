#include<bits/stdc++.h>
 
#define forn(i,n)for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define fore(i,l,r) for(i=l;i<=r;++i)
#define ford(i,n) for(i=n-1;i>=0;--i)
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
	int top = 0, bottom = 1000, n,i;
	cin>>n;
	int a[n],f=1,temp=0,sum=0;
	forn(i,n)
	{
		cin>>a[i];
		if(f)
			temp+=a[i];
		else temp-=a[i];
		sum+=a[i];
		top = max(temp,top);
		bottom = min(temp,bottom);
		f = 1 - f;
	}
	bottom = min(bottom,0);
	int r = top - bottom, c = sum,j=0,counter=0,l,k;
	vvi save;
	forn(i,r)
	{
		vi temp;
		forn(j,c)
			temp.pb(0);
		save.pb(temp);
	}
	l = r -(0-bottom)-1;
	k = 0;
	f = 1;
	i = 0;
	j = 0;
	while(i<sum)
	{
		if(f) save[l--][k++]=1;
		else save[l++][k++]=2;
		i++;
		counter++;
		if(counter == a[j])
		{
			if(f) l++;
			else l--;
			f = 1 - f;
			counter = 0;
			j++;
		}
	}
	forn(i,top-bottom)
	{
		forn(j,sum)
			if(save[i][j]==1) cout<<"/";
			else if(save[i][j]==2) cout<<"\\";
			else cout<<" ";
		cout<<endl;
	}
	return 0;
}
 
