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

int main()
{
	ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int i,j,k, temp, buoc = 1;
    vi a, b;
    forn(i,n)
    {
    	cin>>temp;
    	a.pb(temp);
    }
    bool flag;
    forn(i,n-1)
    {
        flag = 0;
        for(j = 0;j<n-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
        cout<<"Buoc "<<buoc++<<" : ";
        forn(j,n)
            cout<<a[j]<<" ";
        cout<<endl;
        
    }
    return 0;
}