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
    int n, i , ans = INT_MAX;
    cin>>n;
    string s;
    cin>>s;
    string pattern = "BGR", ansStr;
    do{
        string temp = pattern;
        while(temp.size() < n)
            temp+=pattern;
        int tempAns = 0;
        forn(i,n)
            if(s[i]!=temp[i])
                tempAns++;
        if(tempAns < ans)
        {
            ans = tempAns;
            ansStr = temp.substr(0,n);
        }
    }
    while(next_permutation(all(pattern)));
    cout<<ans<<endl;
    cout<<ansStr;
    return 0;
}