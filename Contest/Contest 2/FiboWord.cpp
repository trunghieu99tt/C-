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

unsigned long long fibo[100];

void preFibo()
{
	fibo[1] = 1;
	fibo[2] = 1;
	for(int i = 3;i<=92;i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
}

char fiboWord(int n, ll k)
{
	if(n == 1)
        return 'A';
    if(n == 2)
        return 'B';
    if(k <= fibo[n-2])
        return fiboWord(n-2,k);
    return fiboWord(n - 1, k - fibo[n-2]);
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    preFibo();
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
        ll k;
    	cin>>n>>k;
    	cout<<fiboWord(n,k)<<endl;
    }
    return 0;
}