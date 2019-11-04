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

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef double ld;

int check3(int n)
{
    string s = to_string(n);
    string s1 = s.substr(0,s.size()/2),s2 = s.substr(s.size()/2);
    reverse(all(s2));
    return s1==s2;
}

int check1(int n)
{
    string s = to_string(n);
    for(auto i:s)
        if(i=='0') return 0;
    return 1;
}

int check2(int n)
{
    string s = to_string(n);
    int sum = 0;
    for(auto i:s)
        sum+=(i-'0');
    return sum%10==0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    int t,l,i;
    cin>>t;
    vi conditional1,conditional2,conditional3;
    for(i=1e5;i<=1e6-1;i++)
    {
        if(check3(i))
            conditional3.pb(i);
    }
    for(auto i:conditional3)
        if(check2(i))
            conditional2.pb(i);
    for(auto i:conditional2)
        if(check1(i))
            conditional1.pb(i);
    int n1 = conditional1.size(),n2 = conditional2.size(),n3 = conditional3.size();
    forn(l,t)
    {
        int n,m,k,i;
        cin>>n>>m>>k;
        if(n1 - n >=0 && n2 - n - m >=0 && n3 - n - k - m>=0)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
