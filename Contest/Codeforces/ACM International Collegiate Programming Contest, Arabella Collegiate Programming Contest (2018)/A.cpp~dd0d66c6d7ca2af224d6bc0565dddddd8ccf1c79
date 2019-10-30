#include<bits/stdc++.h>

using namespace std;

/*-----------------------------------GENERAL USER DEFINATION ------------------------------*/
#define forn(i,n) for(i=0;i<n;++i)
#define for1(i,n) for(i=1;i<=n;++i)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<vs> vvs;

const int mod = 1e9 + 7;

ll binPow(ll a, ll b){ll x = 1, y = a;while (b){if (b & 1)x = (x * y) % mod;y = (y*y) % mod;b >>= 1;}return x % mod;}

/*---------------------------------------------------------------------------------------*/


ll rounder(ll a)
{
    int numOfDigits = log(abs(a))/log(10) + 1;
    ll  rounderNum = round(pow(10,numOfDigits-1)),
        upperNum = rounderNum * 10,
        mod = a%rounderNum,
        div = a/rounderNum;
    if(a >= 0)
    {
        if(mod >= rounderNum/2)
            a = (div + 1) * rounderNum;
        else a = (div) * rounderNum;
    }
    else
    {
        if(abs(mod) >= rounderNum/2)
            a = (div - 1) * rounderNum;
        else a = div * rounderNum;
    }
    return a;
}

bool checker(ll n)
{
    n = abs(n);
    string s = to_string(n);
    if(s.size() == 1 || (s[0]!='0' && s.substr(1) == string(s.size()-1,'0')))
        return 1;
    return 0;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ll a, b,i,j;
        cin>>a>>b;
        vll numA, numB;
        queue<ll> qA, qB;
        qA.push(a);
        qB.push(b);
        while(!qA.empty())
        {
            ll u = qA.front();
            if(checker(u))
                numA.pb(u);
            qA.pop();
            if(!checker(u))
            {
                ll roundNumber = rounder(u), modulo = u - roundNumber;
                numA.pb(roundNumber);
                if(checker(modulo))
                    numA.pb(modulo);
                else qA.push(modulo);
            }
        }
        while(!qB.empty())
        {
            ll u = qB.front();
            if(checker(u))
                numB.pb(u);
            qB.pop();
            if(!checker(u))
            {
                ll roundNumber = rounder(u), modulo = u - roundNumber;
                numB.pb(roundNumber);
                if(checker(modulo))
                    numB.pb(modulo);
                else qB.push(modulo);
            }
        }
        sort(all(numA));
        sort(all(numB));
        // for(auto i:numA)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(auto i:numB)
        //     cout<<i<<" ";
        // cout<<endl;
        if(numA.size() > numB.size())
        {
            forn(i,numA.size())
            {
                forn(j,numB.size())
                {
                    if(i!=0)
                    {
                        if(numA[i] >=0)
                            cout<<" + "<<numA[i]<<" x "<<numB[j];
                        else cout<<" - "<<abs(numA[i])<<" x "<<numB[j];
                    }
                    else
                    {
                        if(j == 0)
                            cout<<numA[i]<<" x "<<numB[j];
                        else 
                        {
                            if(numA[i] >=0)
                                cout<<" + "<<numA[i]<<" x "<<numB[j];
                            else cout<<" - "<<abs(numA[i])<<" x "<<numB[j];
                        }
                    }
                }
            }
        }
        else 
        {
            forn(i,numB.size())
            {
                forn(j,numA.size())
                {
                    if(i!=0)
                    {
                        if(numB[i] >=0)
                            cout<<" + "<<numB[i]<<" x "<<numA[j];
                        else cout<<" - "<<abs(numB[i])<<" x "<<numA[j];
                    }
                    else
                    {
                        if(j == 0)
                            cout<<numB[i]<<" x "<<numA[j];
                        else 
                        {
                            if(numB[i] >=0)
                                cout<<" + "<<numB[i]<<" x "<<numA[j];
                            else cout<<" - "<<abs(numB[i])<<" x "<<numA[j];
                        }
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}