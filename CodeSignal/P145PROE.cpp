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
typedef double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	string s , row1 ="",row2="",row3="";
	cin>>s;
	string s1,s2,s3,s4,r1,r2,r3,r4;
	if(s.size()==1)
	{
		s1 = "..#.."; s2 = ".#.#.";s3 = "#.";s4= ".#";
		r1= "..*.."; r2 = ".*.*."; r3 = "*."; r4 = ".*";
	}
	else
	{
		s1 = "..#."; s2 = ".#.#";s3 = "#.";s4= ".";
		r1= "..*.";r2 = ".*.*"; r3 = "*."; r4 = ".";
	}
	int counter = 1,j=1;
	for(auto i:s)
	{
		if(counter%3!=0)
		{
			row1+=s1;
			row2+=s2;
			if((counter-1)%3==0 && counter-1!=0)
			{
				string change = "*.";
				change+=i;
				change+=s4;
				row3+=change;
			}
			else
				row3+=(s3+i+s4);
			counter++;
		}
		else
		{
			row1+=r1;
			row2+=r2;
			row3+=(r3+i+r4);
			counter++;
		}
	}
	if(s.size()>1)
	{
		row1+=".";
		row2+=".";
		if(row1[row1.size()-3]=='#') row3+="#";
		else row3+="*";
	}
	cout<<row1<<endl;
	cout<<row2<<endl;
	cout<<row3<<endl;
	cout<<row2<<endl;
	cout<<row1<<endl;
}
