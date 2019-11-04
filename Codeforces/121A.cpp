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
 
set<ll> ans;
 
void builder(int n)
{
    for (int i = 0;i <= n;i++)
    {
        string s = string(i, '4') + string(n - i, '7');
        do {
            ans.insert(stoll(s));
        } while (next_permutation(all(s)));
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll index = 0, i, a, b;
    cin >> a >> b;
    int number = log(b) / log(10) + 1;
    for (i = 1;i <= number + 1;i++)
        builder(i);
    vll v;
    for (auto i : ans)
        v.pb(i);
    unsigned long long res = 0;
    i = a;
    while (v[index] < i)
        index++;
    if(a == b)
    {
        cout<<v[index];
        return 0;
    }
    ll prev = a;
    while (v[index] < b)
    {
        res+= v[index] * (v[index] - prev + 1);
        //cout<<v[index]<<" "<<res<<endl;
        prev = v[index] + 1;
        index++;
    }
    if(v[index] >= b)
        res+= (v[index]) * (b - prev + 1);
    cout << res << endl;
} 