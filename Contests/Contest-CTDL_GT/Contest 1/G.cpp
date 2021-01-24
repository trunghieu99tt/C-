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

int ans = INT_MIN, r = 8, c = 8;

bool checker(int r1, int c1, int r2, int c2){
    return abs(r1 - r2) == abs(c1 - c2);
}


int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    vvi checkSet;
    vi a;
    for(int i = 0;i<8;i++)
    	a.pb(i);
    do{
    	checkSet.pb(a);
    }
    while(next_permutation(all(a)));
    int t,k;
    cin>>t;
    forn(k,t)
    {
    	int a[] = {0,1,2,3,4,5,6,7}, ans = 0,i;
    	int chess[8][8],j, n = 8;
    	forn(i,n)
    		forn(j,n)
    			cin>>chess[i][j];
    	for(int x = 0;x < checkSet.size(); x++)
    	{
    		int flag = 1, temp = 0;
    		forn(i,n)
    		{
    			forn(j,n)
    				if(i!=j && checker(i,checkSet[x][i], j, checkSet[x][j]))
    				{
    					flag = 0;
    					break;
    				}
    			if(flag == 0)
    				break;
    		}
    		if(flag)
    		{
    			forn(i,n)
    				temp+= chess[i][checkSet[x][i]];
    		}
    		ans = max(temp, ans);
    	}
    	cout<<ans<<endl;
    }
    return 0;
}