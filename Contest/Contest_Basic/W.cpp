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
typedef vector<vs> vvs;

string To_string(int n)
{
    string ans;
    ostringstream convert;
    convert<<n;
    ans = convert.str();
    return ans;
}
// Tru 2 so lon:
string Minus(string a, string b)
{
    string ans = "";
    int i,reminder = 0, n = max(a.size(),b.size());
    while(a.size()!=n)
        a = '0'+a;
    while(b.size()!=n)
        b = '0'+b;
    int f = 0;
    if(a<b)
    {
        swap(a,b);
        f = 1;
    }
    for(i = a.size() - 1;i>=0;i--)
    {
        int temp = (a[i]-'0')-(b[i]-'0') - reminder;
        if(temp<0 && i>0)
        {
            temp+=10;
            reminder = 1;
        }
        else reminder = 0;
        ans = To_string(temp) + ans;
    }
    i = 0;
    while(ans[i]=='0') i++;
    if(i>0 && i<ans.size()) ans = ans.substr(i);
    if(f)
        ans = '-'+ans;
    return count(all(ans),'0') == ans.size()?"0":ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    int t,k;
    cin>>t;
    forn(k,t)
    {
        string a,b;
        cin>>a>>b;
        string ans = Minus(a,b);
        if(ans[0] == '-')
            ans = ans.substr(1);
        cout<<ans<<endl;
    }
    return 0;
}
