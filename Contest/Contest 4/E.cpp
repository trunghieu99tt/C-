#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)

const int maxn = 1e5;

string s;
int dp[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        stack<int> st;
        memset(dp,0,sizeof(dp));
        int n = s.size(),i;
        forn(i,n)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(!st.empty())
                {
                    int lo = st.top();
                    st.pop();
                    if(!lo)
                        dp[i] = i + 1;
                    else dp[i] = dp[lo - 1] + i - lo + 1;
                }
            }
        }
        int ans = 0;
        forn(i,n)
            ans = max(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}