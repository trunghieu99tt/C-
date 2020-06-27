#include <bits/stdc++.h>
 
#define forn(i, n) for (i = 0; i < n; ++i)
#define for1(i, n) for (i = 1; i <= n; ++i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;
 
ll x, y;
 
void extendEuclid(ll a, ll b)
{
    if(b == 0){x = 1;y = 0;return;}
    extendEuclid(b,a%b);
    ll x1 = y, y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

bool cmp(string a, string b)
{
	if(a.size() < b.size())
		return 1;
	if(a.size() > b.size())
		return 0;
	return a < b;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    // int t;
    // cin >> t;
    // while (t--)
    // {
        ll n, a, b;
        cin >> n;
        a = 4;b = 7;
        extendEuclid(a, b);
        ll d = __gcd(a,b);
        if(n%d!=0)
        {
            cout<<-1<<endl;
        }
        else
        {
            ll mul = n / d;
            x *= mul;
            y *= mul;
            int flag = 0,l = - x / (b/d), r = y / (a/d);
            string ans = "";
            for(ll i = l ; i <= r;i++)
            {
                if(x + (b/d) * i>=0 && y - (a/d) * i >= 0)
                {
                    flag = 1;
                    string tmp = string(x + (b/d) * i, '4') + string(y - (a/d) * i, '7');
                    ans = tmp;
                    break;
                }
            }
            if(!flag)
                cout<<-1<<endl;
            else cout<<ans<<endl;
        }
    //}
    return 0;
} 