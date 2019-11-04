#include<bits/stdc++.h>
 
#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define fore(i,l,r) for(i=l;i<=r;++i)
#define ford(i,n) for(i=n-1;i>=0;--i)
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
typedef vector<string> vs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int i,counter = 0;
    map<string,int> num;
    for1(i,n)
    {
        string s;
        cin>>s;
        num[s]++;
        if(i - num[s] < num[s] - 1)
            counter++;
    }
    cout<<counter;
    return 0;
}
