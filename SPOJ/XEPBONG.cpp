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

string sum(string a, string b)
{
    if(a.size() > b.size()) swap(a,b);
    while(a.size()!=b.size())
        a = '0'+a;
    int add = 0,i;
    string ans = "";
    for(i = a.size()-1;i>=0;i--)
    {
        int temp = (a[i]- '0') + (b[i] - '0') + add;
        if(temp>=10 && i!=0)
        {
            temp%=10;
            add = 1;
        }
        else add = 0;
        ans = to_string(temp) + ans;
    }
    return ans;
}

string solve(int n)
{
    vector<vector<string>> res(n+1,vector<string>(n+1));
    res[0][0] = "1";
    int i,j;
    for1(i,n)
    {
        res[i][0] = res[i-1][i-1];
        for1(j,n)
            res[i][j] =sum(res[i-1][j-1],res[i][j-1]);
    }
    return res[n][0];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    while(1)
    {
        int n;
        cin>>n;
        if(n==0) return 0;
        cout<<n<<" "<<solve(n)<<endl;
    }
    return 0;
}
