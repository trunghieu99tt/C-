#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for(i=0;i<n;++i)


void trunghieu()
{
	int t, test = 1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string dad, son;
		int year;
		int i,j;
		map<string,vector<string>> adj;
		map<string,int> age;
		age["Ted"] = 100;
		map<pair<string,string>,int> yearGiveBirth;
		forn(i,n)
		{
			cin>>dad>>son>>year;
			adj[dad].emplace_back(son);
			yearGiveBirth[{dad,son}] = year;
		}
		vector<string> ans;
		queue<string> q;
		q.push("Ted");
		while(!q.empty())
		{
			string curr = q.front();q.pop();
			if(curr!="Ted")
				ans.emplace_back(curr);
			forn(i,adj[curr].size())
			{
				age[adj[curr][i]] = age[curr] - yearGiveBirth[{curr, adj[curr][i]}];
				q.push(adj[curr][i]);
			}
		}
		sort(ans.begin(), ans.end(),[=](string a, string b){
			return age.at(a) > age.at(b)
			|| age.at(a) == age.at(b) && a < b;
		});
		cout<<"DATASET "<<test++<<"\n";
		forn(i,ans.size())
			cout<<ans[i]<<" "<<age[ans[i]]<<endl;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    trunghieu();
    return 0;
}