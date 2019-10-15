#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;

int a[maxn] , n;

void solve()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int i,j;
		for(i = 0;i<n;i++)
			cin>>a[i];
		stack<int> st;
		for(i = 0;i<n;i++)
		{
			if(st.empty() || a[i] < st.top())
				st.push(a[i]);
			else
			{
				int tmp = st.top(), cnt = 0;
				while(!st.empty() && st.top() < a[i])
					cnt++, st.pop();
				if(cnt > 1)
					cout<<tmp<<" ";
				st.push(a[i]);
			}
		}
		if(!st.empty())
			cout<<st.top()<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie();
	//freopen("input.txt","r",stdin);
	solve();
	return 0;
}