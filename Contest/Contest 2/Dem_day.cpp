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
const long long mod = 123456789;
 
long long PowPow(int a, ll b, ll mod){
    long long x=1, y=a; 
    while (b) {
        if (b&1) {
            x = (x*y) % mod;
        }
        y = (y*y) % mod;
        b >>= 1;
    }
    return x % mod;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<PowPow(2,n-1,mod)<<endl;
    }
    return 0;
} 