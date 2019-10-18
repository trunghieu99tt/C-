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

bool checkPositive(int a[],int n)
{
    for(int i = 0;i<n;i++)
        if(a[i]<0)
            return 0;
    return 1;
}

bool checkNegative(int a[],int n){
    for(int i = 0;i<n;i++)
        if(a[i]>=0)
            return 0;
    return 1;
}

long long maxSubArraySum(int a[], int n) 
{ 
   long long ans = 0, currAns = 0; 
   for (int i = 0; i < n; i++) 
   { 
       currAns += a[i]; 
       if (currAns < 0) 
           currAns = 0;
       else if (ans < currAns) 
           ans = currAns; 
   } 
   return ans; 
} 


int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,k;
    cin>>t;
    forn(k,t)
    {
      int n;
      cin>>n;
      int a[n],i;
      long long s1 = 0;
      forn(i,n)
      {
          cin>>a[i];
          s1+=a[i];
      }
      if(checkPositive(a,n))
          cout<<s1<<endl;
      else if(checkNegative(a,n))
      {
          sort(a,a+n,greater<int>());
          cout<<a[0]<<endl;
      }
      else
        cout<<maxSubArraySum(a,n)<<endl;
    }
    return 0;
}