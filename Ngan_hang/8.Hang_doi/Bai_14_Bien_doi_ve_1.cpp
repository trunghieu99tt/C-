// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie();
// 	int t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		int n;
// 		cin >> n;
// 		queue<int> q;
// 		map<int, int> path, visited;
// 		q.push(n);
// 		visited[n] = 1;
// 		path[n] = 0;
// 		while (!q.empty())
// 		{
// 			int u = q.front(); q.pop();
// 			if (u == 1)
// 			{
// 				cout << path[1] << endl;
// 				break;
// 			}
// 			if (!visited[u - 1])
// 			{
// 				q.push(u - 1);
// 				visited[u - 1] = 1;
// 				path[u - 1] = path[u] + 1;
// 			}
// 			for (int x = sqrt(u); x >= 2; x--)
// 			{
// 				if (u % x == 0)
// 				{
// 					int x1 = u / x, v = max(x, x1);
// 					if (!visited[v])
// 					{
// 						q.push(v);
// 						path[v] = path[u] + 1;
// 						visited[v] = 1;
// 					}
// 				}
// 			}
// 		}
// 	}
// }

#include<bits/stdc++.h>
using namespace std;
int chuaxet[10000001];
int truoc[10000001];
void solve(int a){
	memset(chuaxet,0,sizeof(chuaxet));
	memset(truoc,0,sizeof(truoc));
	queue<int> q;
	q.push(a);
	chuaxet[a]=1;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		int x=v-1;
		if(x>0 && !chuaxet[x]){
			chuaxet[x]=1;
			truoc[x]=v;
			if(x==1) break;
			q.push(x);
		}
		int y;
		int kt=1;
		for(int i=2;i*i<=v;i++){
			if(v%i==0){
					int MAX = max(i,v/i);
					if(!chuaxet[MAX]){
						chuaxet[MAX]=1;
						truoc[MAX]=v;
						q.push(MAX);
						if(MAX==1){
							kt=0;
							break;
						}
					}
				}
		}
		if(kt==0) break; 
	}
	int dem=1;
	int u=truoc[1];
	while(u!=a){
		dem++;
		u=truoc[u];
	}
	cout<<dem<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		solve(n);
	}
 
}