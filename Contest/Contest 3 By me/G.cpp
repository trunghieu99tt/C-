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

ll deletedRow[17], deletedCol[17],pointsA = 0, pointsB = 0, 
ansA = LLONG_MAX, a[17][17], n, countNev, ansB = LLONG_MIN;

void solve(int u)
{
    for(int r = 0;r<n;r++)
    {
        if(deletedRow[r] == 0)
        {
            ll indexC, valueC = LLONG_MAX;
            for(int c = 0;c<n;c++)
            {
                if(deletedCol[c] == 0 && a[r][c] <= valueC)
                {
                    indexC = c;
                    valueC = a[r][c];
                }
            }
            pointsA+=a[r][indexC];
            pointsB-=a[r][indexC];
            deletedCol[indexC] = 1;
            deletedRow[r] = 1;
            if(u == n-1)
            {
                ansA = min(ansA, pointsA);
                ansB = max(ansB, pointsB);
            }
            else if(pointsA < ansA || pointsB < ansB) solve(u+1);
            pointsA-=a[r][indexC];
            pointsB+=a[r][indexC];
            deletedRow[r] = 0;
            deletedCol[indexC] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,k;
    cin>>t;
    forn(k,t)
    {
        cin>>n;
        countNev = 0;
        int i,j;
        forn(i,n)
            forn(j,n)
                cin>>a[i][j];
        ansA = LLONG_MAX;
        ansB = LLONG_MIN;
        pointsA = 0;pointsB = 0;
        memset(deletedRow,0,n);
        memset(deletedCol,0,n);
        solve(0);
        cout<<ansA<<endl;
    }
    return 0;
}