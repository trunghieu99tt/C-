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

bool isVowel(char a)
{
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s, t;
    cin>>s>>t;
    if(s.size()!=t.size())
    {
        cout<<"No";
        return 0;
    }
    int i;
    for(i = 0;i<s.size();i++)
    {
        if(isVowel(s[i]) && !isVowel(t[i])
            || !isVowel(s[i]) && isVowel(t[i]))
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}